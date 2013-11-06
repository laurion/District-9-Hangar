//
// The Game Creators (www.thegamecreators.com)
// MAKESKIN and DRAWSKIN Effects
//

#include "basepool.fx"

// defines
#define MAX_BONE_MATRICES 255

// Input/Output structures
struct VSSkinnedIn
{
    float3 Pos	: POSITION;			    //Position
    float3 Norm : NORMAL;			//Normal
    float2 Tex	: TEXTURE;		    //Texture coordinate
    float4 Weights : WEIGHTS;		//Bone weights
    uint4  Bones : BONES;			//Bone indices
    float3 Tan : TANGENT;		    //Normalized Tangent vector
};

struct VSStreamOut
{
    float4 Pos	: POSITION;			    //Position
    float3 Norm : NORMAL;			//Normal
    float2 Tex	: TEXTURE;		    //Texture coordinate
    float3 Tangent : TANGENT;		//Normalized Tangent vector
};

struct VSStreamOutInst
{
    float4 Pos	: POSITION;			    //Position
    float3 Norm : NORMAL;			//Normal
    float2 Tex	: TEXTURE;		    //Texture coordinate
    float3 Tangent : TANGENT;		//Normalized Tangent vector
    row_major float4x4 mTransform : mTransform;		// instance struct
    uint4 uExtraData : uExtraData;
};

struct PSSkinnedIn
{
    float4 Pos	: SV_Position;		//Position
    float3 vPos : POSWORLD;		//world space Pos
    float3 Norm : NORMAL;		//Normal
    float2 Tex	: TEXTURE;	        //Texture coordinate
    float3 Tangent : TANGENT;		//Normalized Tangent vector
    float3 planeDist : SV_ClipDistance0;
    float4 colorD : COLOR0;
    uint TexIndex : TexIndex;
};

cbuffer cbUserChange
{
    float3 g_vLightPos;
    float3 g_vEyePt;
};

cbuffer cbPerCubeRender
{
    float4x4 g_mViewCM[6];
};

cbuffer cbImmutable
{
    float4   g_fAmbientLight;
};

// Constant buffer for bone matrices
cbuffer cbAnimMatrices
{
    matrix g_mConstBoneWorld[MAX_BONE_MATRICES];
};

// Textures
Texture2D g_tx2D0;
Texture2D g_tx2D1;
Texture2D g_tx2D2;

// Texture samplers
SamplerState g_samLinear
{
    Filter = ANISOTROPIC;
    AddressU = Clamp;
    AddressV = Clamp;
};

// State
DepthStencilState DisableDepth
{
    DepthEnable = FALSE;
    DepthWriteMask = 0;
};

DepthStencilState EnableDepth
{
    DepthEnable = TRUE;
    DepthWriteMask = ALL;
};

// Helper struct for passing back skinned vertex information
struct SkinnedInfo
{
    float4 Pos;
    float3 Norm;
    float3 Tan;
};

// SkinVert skins a single vertex
SkinnedInfo SkinVert( VSSkinnedIn Input )
{
    SkinnedInfo Output = (SkinnedInfo)0;
    
    float4 Pos = float4(Input.Pos,1);
    float3 Norm = Input.Norm;
    float3 Tan = Input.Tan;
    
    //Bone0
    uint iBone = Input.Bones.x;
    float fWeight = Input.Weights.x;
    matrix m = g_mConstBoneWorld[ iBone ];
    Output.Pos += fWeight * mul( Pos, m );
    Output.Norm += fWeight * mul( Norm, (float3x3)m );
    Output.Tan += fWeight * mul( Tan, (float3x3)m );
    
    //Bone1
    iBone = Input.Bones.y;
    fWeight = Input.Weights.y;
    m = g_mConstBoneWorld[ iBone ];
    Output.Pos += fWeight * mul( Pos, m );
    Output.Norm += fWeight * mul( Norm, (float3x3)m );
    Output.Tan += fWeight * mul( Tan, (float3x3)m );
    
    //Bone2
    iBone = Input.Bones.z;
    fWeight = Input.Weights.z;
    m = g_mConstBoneWorld[ iBone ];
    Output.Pos += fWeight * mul( Pos, m );
    Output.Norm += fWeight * mul( Norm, (float3x3)m );
    Output.Tan += fWeight * mul( Tan, (float3x3)m );
    
    //Bone3
    iBone = Input.Bones.w;
    fWeight = Input.Weights.w;
    m = g_mConstBoneWorld[ iBone ];
    Output.Pos += fWeight * mul( Pos, m );
    Output.Norm += fWeight * mul( Norm, (float3x3)m );
    Output.Tan += fWeight * mul( Tan, (float3x3)m );
    
    return Output;
}

// Vertex shader used for skinning and streaming out
VSStreamOut VSSkinnedStreamOutmain(VSSkinnedIn input)
{
    VSStreamOut output = (VSStreamOut)0;
    
    SkinnedInfo vSkinned = SkinVert( input );
    output.Pos = vSkinned.Pos;
    output.Norm = normalize( vSkinned.Norm );
    output.Tangent = normalize( vSkinned.Tan );
    output.Tex = input.Tex;
    
    return output;
}

// Helper to calculate global lighting from all lights in scene
struct ColorsOutput
{
    float4 Diffuse;
};
ColorsOutput CalcLighting( float3 worldNormal, float3 worldPos )
{
    ColorsOutput output = (ColorsOutput)0.0;

    for(int i=0; i<g_LightsUsed; i++)
    {
        float3 toLight = g_lights[i].Position.xyz - worldPos;
        float lightDist = max(length( toLight ),200);
        float fAtten = 1.0/dot( g_lights[i].Atten, float4(1,lightDist,lightDist*lightDist,0) );
        float3 lightDir = normalize( toLight );
        output.Diffuse += max(0,dot( lightDir, worldNormal ) * g_lights[i].Diffuse * fAtten);
    }

    //output.Diffuse += g_fAmbientLight; //moved to pixel shader, ambient must be added seperate from bump
    output.Diffuse.w = 1.0;

    return output;
}

// Vertex shader used for rendering an already skinned mesh
PSSkinnedIn VSRenderPostTransformedmain(VSStreamOut input)
{
    PSSkinnedIn output;

    output.Pos = mul( input.Pos, g_mWorldViewProj );
    output.vPos = input.Pos.xyz;
    output.Norm = normalize( mul( input.Norm, (float3x3)g_mWorld ) );
    output.Tangent = normalize( mul( input.Tangent, (float3x3)g_mWorld ) );
    output.Tex = input.Tex;
    output.TexIndex = 0;
    
    //calc the distance from the clipping plane
    float4 worldPos = mul( input.Pos, g_mWorld );
    worldPos.w = 1;
    output.planeDist.x = dot( worldPos, g_clipplanes[0] );
    output.planeDist.y = 1;
    output.planeDist.z = 1;

    // global scene lighting
    ColorsOutput cOut = CalcLighting( output.Norm, worldPos.xyz );
    output.colorD = cOut.Diffuse;

    return output;
}

// Vertex shader used for zero skinning
PSSkinnedIn VSRenderNoTransformedmain(VSSkinnedIn input)
{
    PSSkinnedIn output;
    
    output.Pos = mul( float4(input.Pos,1), g_mWorldViewProj );
    output.vPos = mul( input.Pos, g_mWorld ).xyz;
    output.Norm = normalize( mul( input.Norm, (float3x3)g_mWorld ) );
    output.Tangent = normalize( mul( input.Tan, (float3x3)g_mWorld ) );
    output.Tex = input.Tex;
    output.TexIndex = 0;
    output.colorD = float4(1,1,1,1);
    
    return output;
}

// Pixel shader that performs bump mapping on the final vertex
float4 PSSkinnedmain(PSSkinnedIn input) : SV_Target
{	
    float4 diffuse = g_tx2D0.Sample( g_samLinear, input.Tex );
    float3 Norm = g_tx2D1.Sample( g_samLinear, input.Tex );
    float3 Shine = g_tx2D2.Sample( g_samLinear, input.Tex );
    Norm.z = -Norm.z; // ATI normal map from Simon
    Norm *= 2.0;
    Norm -= float3(1,1,1);
    
    // Create TBN matrix
    float3 lightDir = normalize( input.vPos - g_vLightPos );
    float3 viewDir = normalize( input.vPos - g_vEyePt );
    float3 BiNorm = normalize( cross( input.Norm, input.Tangent ) );
    float3x3 BTNMatrix = float3x3( BiNorm, input.Tangent, input.Norm );
    Norm = normalize( mul( Norm, BTNMatrix ) ); //world space bump
    
    //diffuse lighting
    float lightAmt = saturate( dot( lightDir, Norm ) );
    float4 lightColor = float4(lightAmt.xxx,1);

    // Calculate specular power
    float3 halfAngle = normalize( lightDir + viewDir );
    float4 spec = saturate( pow( dot( halfAngle, Norm ), 64 ) );

    // indirect lighting from floor
    float3 Ln2 = float3(0,1,0);
    float4 lighting2 = float4(0.1,0.2,0.4,1) * dot(Ln2,Norm);

    // Return combined lighting
    return lighting2*diffuse + lightColor*diffuse*input.colorD + diffuse*input.colorD + (spec*float4(Shine,1))*input.colorD + diffuse*g_fAmbientLight;
}


// Stream out straight from the VS
VertexShader vsConstantBuffer = CompileShader( vs_4_0, VSSkinnedStreamOutmain() );
GeometryShader vsConstantBufferSO = ConstructGSWithSO( vsConstantBuffer, "POSITION.xyzw; NORMAL.xyz; TEXTURE.xy; TANGENT.xyz" );
    
// Render the scene by fetching bone matrices from an SO buffer
technique10 DrawSkin
{
    pass P0
    {       
        SetVertexShader( CompileShader( vs_4_0, VSRenderPostTransformedmain() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PSSkinnedmain() ) );
        
        SetDepthStencilState( EnableDepth, 0 );
    }
}

// Stream out the scene by fetching bone matrices from a constant buffer (StreamOut)
technique10 MakeSkinSO
{   
    pass P0
    {       
        SetVertexShader( vsConstantBuffer );
        SetGeometryShader( vsConstantBufferSO );
        SetPixelShader( NULL );
        
        SetDepthStencilState( DisableDepth, 0 );
    }
}

// Render the scene using no bone animation (meshes with no bones)
technique10 DrawNoSkin
{
    pass P0
    {       
        SetVertexShader( CompileShader( vs_4_0, VSRenderNoTransformedmain() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PSSkinnedmain() ) );
        SetDepthStencilState( EnableDepth, 0 );
    }
}
