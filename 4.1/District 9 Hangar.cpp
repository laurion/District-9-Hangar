/////////////////////////////////////////////////////////////////////////////
//	Project		:	D9
//	File		:	District 9 Hangar.cpp
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//	Includes	:
/////////////////////////////////////////////////////////////////////////////
#include "District 9 Hangar.h"


/*
//void GameStart ( void )
//{
	
	//dbCreateBitmap( 1,screenX,screenY);


	/*
	dbSetTextFont( "Verdana" );
	dbSetTextToBold		 ( );
	dbSetTextTransparent ( );
	
	//dbPasteImage ( controlsImage , 0 , 0 , 1 );
	
//}


void D9Main ( void )
{
	dbSetDir ( "media" );
	initWindow ( );
	/*
	if ( checkpassword() == false )
	{
		dbPrint("Wrong!");
		dbPrint("Press any key to exit.");
		dbWaitKey();
		//goto _End;
		return;
	}
	

	//GameStart();
	srand ( (unsigned) time(NULL) );
	dbLoadBitmap ( "images\\loading.jpg",1 );
	dbCopyBitmap ( 1 , 0 , 0 , 800 , 600 , 0 , 0 , 0 , screenX , screenY );
	dbDeleteBitmap( 1 );
	dbSetCurrentBitmap ( 0 );

	dbSync( );
	dbSync( );
	
	dbHideMouse ( );
	//dbDisableEscapeKey();
	//readData ( );
	loadMedia( );
	dbTextureBackdrop ( 0, ceiling );
	setup( );
	//dbSetTextFont( "Verdana" );
	//ShowMenu();
	dbPlayObject ( gunObj , 0 , 9 );
	while ( loopInvariant ( ) )
	{
		
			/*
			//ShowMenu();
			while ( true )
			{
				//....
				if ( dbEscapeKey() )
					break;
				if ( dbKeyState ( 25 ) )//'p'
					goto _End;
				dbSync();
			}
			
		

		GameCycle	( );
		
		dbSync		( );

	}
	return;
//_End:
//GameEnd	( );

}*/
void D9Main ( void )
{
	dbSetDir ( "media" );
	
	initWindow ( );

	GameStart ( );

	while ( LoopGDK ( ) )
	{
		if ( !bGame )
		{
			GameEnd	();
			exit(0);
		}
		GameCycle();
		dbSync		( );
	}
}
void initWindow	( void )
{
	
	if(  dbCheckDisplayMode( screenX , screenY , 32 )  )
			dbSetDisplayMode ( screenX , screenY , 32 );
	else
	{
		//I want to play in fullscreen without changing the resoltution and GetSystemMetrics is a good way to find out what the current desktop resolution is.
		screenX=GetSystemMetrics(SM_CXSCREEN);
		screenY=GetSystemMetrics(SM_CYSCREEN);
		dbSetDisplayMode ( screenX , screenY , 32 );
	}
	//HUD data
	livesX = 31 * screenX/1152;
	livesY = 34 * screenY/864;
	
	healthX = 137 * screenX/1152;
	healthY =  34 * screenY/864;
	
	copyrX = screenX >> 1 ;
	copyrY =  screenY - (40* screenY/864) ;
	
	ammoX = screenX - ( 130 *  screenX/1152);
	ammoY = 93* screenY/864;
	
	LivesX = 63 *  screenX/1152;
	LivesY = 58* screenY/864;
	
	HealthX = 169 *  screenX/1152;
	HealthY = 58* screenY/864;

	playX = 100 * screenX/1152;
	playY = 280 * screenY/864;

	creditsX = 300 * screenX/1152;
	creditsY = 430 * screenY/864;

	exitY = 600* screenY/864;
			

	char title[]=" District  9  Hangar : The  Entrance                                           Ion Laurentiu Cristian";
	title[77]=(unsigned char) 169;//copyright
	dbSetWindowTitle( title );
	dbSetWindowOff ( );
	dbDisableEscapeKey();
	dbBackdropOff ( 0 );
	//dbMaximizeWindow();
	dbSyncOn ( );
	dbSyncRate ( 60 );

	dbExitPrompt ("Esti primul care a iesit teafar din acel hangar... Ai talent!","Iesirea din Baza Districtului 9");
	
}
void GameStart ( void )
{
	dbLoadBitmap ( "images\\splash.jpg" , loadingScreen );
	//dbPasteImage ( loadingScreen , 0 , 0 , 0 );
	int w = dbBitmapWidth( loadingScreen );
	int h = dbBitmapHeight( loadingScreen );
	dbCopyBitmap  ( loadingScreen,0,0,w,h,0,(screenX>>1)- (w>>1),(screenY>>1)- (h>>1),(screenX>>1)+ (w>>1) ,(screenY>>1) +(h>>1) );
	//dbDeleteImage ( loadingScreen );

	dbDeleteBitmap ( loadingScreen );
	dbSetCurrentBitmap ( 0 );

	dbFastSync ( );
	dbFastSync ( );
	

	loadMedia();
	dbLoadBitmap ( "images\\loading.bmp" , loadingScreen2 );
	//dbPasteImage ( loadingScreen2 , 0 , 0 , 0 );
	dbCopyBitmap  ( loadingScreen2,0,0,dbBitmapWidth( loadingScreen2 ),dbBitmapHeight( loadingScreen2 ),0,0,0,screenX,screenY );
	//dbDeleteImage ( loadingScreen2 );

	dbDeleteBitmap ( loadingScreen2 );
	dbSetCurrentBitmap ( 0 );

	dbFastSync ( );
	dbFastSync ( );
	
	//dbRandomize ( dbTimer () );
	srand ( (unsigned) time(NULL) );

	setup();
	
	//dbLoadImage ( "images\\fire.bmp", firePart );
	//dbMakeParticles ( ParticleNumber, firePart, 40, 30.0f );/*create a particles object using 
	//				a specified image and radius. A particles object will emit single particles 
	//				given a default set of rules than can be changed using the particle commands.*/
	//dbPositionParticles ( ParticleNumber, 0, -58, 0 );/*position a particles object in 3D world space.
	//												  By moving a particles object you will be moving 
	//												  at the same time every particle that belongs 
	//												  to the particles object. To create the effect 
	//												  of trails, see dbPositionParticleEmissions command.*/
	//dbColorParticles ( ParticleNumber, 255, 128, 0 );
	//dbSetParticleEmissions ( ParticleNumber, 10 );/*set the number of particles emitted from the 
	//											  particles object each cycle. A value of zero will 
	//											  stop the particles object emitting new particles.*/
	//dbSetParticleSpeed ( ParticleNumber, 0.01f );
	//dbSetParticleGravity ( ParticleNumber, 2 );/*set the gravity of particles within the particles 
	//										   object. This controls the actual course of the partic-
	//										   le. A negative gravity value will actually pull the 
	//										   particle upwards at a rotation of 0,0,0. A high posit-
	//										   ive gravity value will make the particle very heavy. 
	//										   The default is a gravity value of 5.*/
	//dbSetParticleLife(ParticleNumber, 50);

	//dbSetTextFont( "Arial" );
	//dbSetTextToBoldItalic ( );
	//dbSetTextTransparent  ( );
	//dbPasteImage ( controlsImage , 0 , 0 , 1 );
	//checkpassword();	
}



bool checkpassword ( void )
{
	dbPrint("Enter the key to this fantastic world:");
	//dbSync();
    if( strcmp(dbInput(),"'" )==0 )
		return true;
	return false;				
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void loadMedia()
{
	dbLoadMusic			( "music\\loading.mp3" , 1 );
	
	dbLoopMusic ( 1 );

	dbLoadImage			("scenery\\floors\\floor.dds" , floorTexture , 0 );
	/*load a picture file as an image. The picture file must be of the BMP, JPG, 
	TGA, DDS, DIB or PNG format. All images loaded are prepared with mipmaps if they do not already 
	have them. TGA, DDS and PNG will retain their alpha channel data when loaded, providing the 
	required transparency information when combined with transparency commands. A Texture Flag of 
	zero will treat the image as a texture and load to fill a texture surface in memory. A value of 
	one will preserve the image without adding mipmaps, scaling or filtering and so retaining its 
	pixel perfect quality. */

	dbLoadImage			("entity\\bezerker.bmp" , monsterTexture );
	dbLoadImage			("scenery\\shadow.png" , shadow , 0 );
	//walls:

	dbLoadImage			("scenery\\walls\\wall1.dds" , wallTexture , 0 );

	dbLoadImage			("scenery\\walls\\wall2.dds" , wallTop , 0 );
		
	dbLoadImage			("guns\\muzzleFlash\\flash4.dds" , muzzleFlash , 0 );

	dbLoadImage			("guns\\tavor\\hud_icon.dds" , tavorHUD );

	dbLoadImage			("images\\blood.dds" , blood1 , 1 ); // blood on the floor
	
	dbLoadImage			("images\\hit.png" , hit , 1); // blood as a shot hits home
	
	dbLoadImage			("images\\redLaser.png" , ATlaser , 1); // laserball from the troopers
	
	dbLoadBitmap			("images\\controlsImage.bmp" , controlsImage ); 
	//dbLoadImage			("images\\title.jpg" , controlsImage ); 

	dbLoadImage			("guns\\tavor\\gun_D2.dds" , tavorTexture);

	dbLoadImage			("scenery\\battery_D2.dds" , batteryTexture);

	dbLoadImage			("scenery\\ceilings\\ceiling_D2.dds" , ceiling );

	dbLoadImage			("scenery\\corridors\\corridor1.dds" , corridor , 0 );

	dbLoadImage			("images\\simple_title.bmp" , YouWin , 1 );
	
	dbLoadImage			("images\\greenLaser.tga" , MonsterLaser , 0 );

	dbLoadImage			("huds\\health.dds", HEALTH );
	
	//dbSprite ( HEALTH , 0 , 0 , HEALTH );
	//dbHideSprite ( HEALTH );
	
	dbLoadImage			("huds\\lives.dds", LIVES );
	//dbSprite ( LIVES , 0 , 0 , LIVES );
	//dbHideSprite ( LIVES );

	char czZoom[64];
	wsprintf( czZoom,"guns\\tavor\\scope2_%d%d.dds",screenX,screenY);

	dbLoadImage			(czZoom , zoomScope );
	//dbLoadImage		("guns\\tavor\\scope2_1152864.dds" , zoomScope );
	//dbSprite			( zoomScope , 0,0,zoomScope );
	//dbSizeSprite		( zoomScope , screenX , screenY );
	//dbHideSprite		( zoomScope );

	//dbLoadImage		( "images\\damageBox1.bmp", damageBox , 1 );




	//ui:
	/*dbLoadImage		( "huds\\backButton.dds", back );
	dbLoadImage		( "huds\\backMO.dds", backMO );

	dbLoadImage		( "huds\\creditsButton.dds", creditsButton );
	dbLoadImage		( "huds\\creditsMO.dds", creditsMO );

	dbLoadImage		( "huds\\quitButton.dds", exitGame );
	dbLoadImage		( "huds\\quitMO.dds", exitMO );

	dbLoadImage		( "huds\\start.dds", play );
	dbLoadImage		( "huds\\startMO.dds", playMO );*/





	//dbLoadImage		( "images\\eyehud.dds", damageBox , 1 );
	//dbSprite			( damageBox , 0,0,damageBox );
	//dbSizeSprite		( damageBox , screenX , screenY );
	//dbHideSprite		( damageBox );



	//dbSetCurrentBitmap  ( 0 );
	iImageCount = zoomScope;

	// gun
	dbLoadObject			("guns\\tavor\\HUD.x", gunObj );
	dbYRotateObject			( gunObj , 180 );
	dbTextureObject			( gunObj , tavorTexture );
	dbSetObjectAmbient		( gunObj , 0 );/*This command will set the ambient state of the specified
									   object. Setting the ambience to one will ensure the object 
									   is affected by the global ambient light level.*/
	//dbPositionObject		( gunObj , dbObjectPositionX ( gunObj ) , dbObjectPositionY ( gunObj ) , dbObjectPositionZ ( gunObj ) +300 );
	dbSetObjectAmbience		( gunObj , 0x00000000 );
							/*This command will alter the material ambience component of the object.
							The ambience component makes up one of the factors that controls the 
							final colour of the object, specifically the amount of global ambient 
							light it receives. If the global ambient was red, and this component was
							set to white, the object would receive 'full' ambient light and drown 
							out any lighting otherwise applied to the object. The object would be 
							completely red. This command should not be confused with 
							dbSetObjectAmbient which controls the flag which states whether the 
							object receives any ambient light whatsoever.*/

	dbFixObjectPivot		( gunObj );/*This command will fix the current angles of the specified 3D 
								   object as the new absolute rotation of the model. It is often 
								   required to load, rotate and fix models to face a particular 
								   direction before using them.*/
	dbDisableObjectZDepth	( gunObj );/*This command will make the specified object ignore the Zdepth 
								   data and render to the screen over standard polygons. This 
								   command is useful for ensuring your FPS Gun will not poke 
								   through walls when you get too close.*/
	dbSetObjectCollisionOff	( gunObj );
	dbHideObject			( gunObj );


	// gunfire
	dbMakeObjectBox			( muzzleFlashObj, 2 , 2, 0 );
	dbTextureObject			( muzzleFlashObj , muzzleFlash );
	dbScaleObject			( muzzleFlashObj, 400, 400 , 0 );
	dbSetObjectLight		( muzzleFlashObj , 0 );
	dbSetObjectEmissive		( muzzleFlashObj , 0x00646464 );/*This command will alter the material emissive 
												component of the object. The emissive component 
												makes up one of the factors that controls the final
												colour of the object, specifically the colour the 
												object emits irrespective of any light or ambience.
												Setting this value to a high colour will make it 
												bright under its own inner colour.*/

	dbSetObjectAmbience		( muzzleFlashObj , 0x00FFFFFF );
							/*This command will alter the material ambience component of the object.
							The ambience component makes up one of the factors that controls the 
							final colour of the object, specifically the amount of global ambient 
							light it receives. If the global ambient was red, and this component was
							set to white, the object would receive 'full' ambient light and drown 
							out any lighting otherwise applied to the object. The object would be 
							completely red. This command should not be confused with 
							dbSetObjectAmbient which controls the flag which states whether the 
							object receives any ambient light whatsoever.*/
	dbFadeObject			( muzzleFlashObj, 8000 );/*This command will make the specified 3D object fade to the
										 current ambient light level. With ambient light set to zero
										 and the object faded using a value of zero, the object will
										 be completely unlit. With a fade value of 200 its 
										 illumination will be doubled. With a fade value of 50, the 
										 illumination is halved. This technique can also be used 
										 with a ghosted object to slowly fade an object until 
										 completely invisible.*/
	dbSetObjectTransparency	( muzzleFlashObj , 1 );/*This command will set the transparency state of the specified
									   object. Setting the transparency to one will ensure the 
									   object does not draw the transparent colour during final 
									   rendering. The transparent colour is determined by the 
									   dbSetImageColorKey command.*/
	dbHideObject			( muzzleFlashObj );
	dbSetObjectCollisionOff	( muzzleFlashObj );
	dbHideObject			( muzzleFlashObj );

	//hit as the bullet hits a wall / object
	
	for ( iBlood = 0 ; iBlood < 10 ; ++iBlood )
	{
		dbMakeObjectPlane		( 13 + iBlood , 20 , 20 );
		dbTextureObject			( 13 + iBlood , hit );
		dbSetObjectCollisionOff	( 13 + iBlood );
		dbSetObjectTransparency ( 13 + iBlood , 1 );
		dbFadeObject			( 13 + iBlood , 400 );
		iBloodAlpha[ iBlood ] = 0;
		dbSetAlphaMappingOn		( 13 + iBlood , iBloodAlpha[ iBlood ]);
							//This command will set the true alpha value of an object to a percentage value from 0 to 100.
							//Zero represents an alpha state that makes the object completely 
							//invisible. An alpha percentage of 100 will render the object fully 
							//visible. A value between these limits will create a true transparency 
							//effect when the object is transparent, as set by the 
							//dbSetObjectTransparency command.
	}
	iBlood = 0;
	
	

	dbLoadSound			( "sound\\gun.wav" , gunSound , 0 );
									
	dbLoadSound			( "sound\\open.wav" , doorOpen1 , 0 );
	dbLoadSound			( "sound\\close.wav" , doorClose1 , 0 );
	dbCloneSound		( doorOpen2 , doorOpen1 );
	dbCloneSound		( doorClose2 , doorClose1 );
	//dbLoadSound			( "sound\\shoop.wav" , 4 , 0 );
	dbSetSoundSpeed		( gunSound , 88000 );/*This command will set the frequency used by the specified 
									  Sound Number. Decibel frequency ranges from 100 to 100,000 
									  and must be specified using an integer value.*/
	dbLoad3DSound		( "sound\\roar.wav" , roar  );
	dbLoadSound			( "sound\\die.wav" , dieSound , 0 );
	dbLoad3DSound		( "sound\\laser.wav" , laserSound  );


	//dbLoadSound			( "sound\\metalA1.wav" , footsteps , 0 );
	//dbSetSoundSpeed		( footsteps , 88000 );

	dbLoad3DSound			( "sound\\attacking_enemies.wav" , ATsound  );


	dbLoadSound			( "sound\\monsterLeap.wav" , monsterDie , 0 );
	dbSetSoundVolume ( monsterDie , 100 );


	dbLoadSound			( "sound\\monsterLand.wav" , monsterRise , 0 );
	dbSetSoundVolume ( monsterRise , 100 );


	dbLoadSound			( "sound\\hurt1.wav" , hurt1 , 0 );
	dbSetSoundVolume ( hurt1 , 100 );	


	dbLoadSound			( "sound\\finalmoan.wav" , finalmoan , 0 );
	dbSetSoundVolume ( finalmoan , 100 );


	dbLoadSound			( "sound\\monsterDie.wav" , monsterFinalmoan , 0 );

	dbLoadSound			( "sound\\hes_dead.wav" , ATfinalmoan , 0 );	

	for( int t=27; t <= 35 ; ++t )
		dbCloneSound( t , 1 );
	
	dbLoadSound			( "guns\\tavor\\zoom.wav" , zoomSound , 0 );

	dbLoadSound			( "music\\WR_RoundWin.wav" , RoundWin , 0 );

	iSoundCount = RoundWin;

	dbLoadMusic			( "music\\mainloop.mp3" , 2 );

	
	
	for ( int iLoop = 0 ; iLoop < MAXCRUMBS ; ++iLoop )
	{
		dbMakeObjectCube		( iLoop + 5000 , 5 );
		dbPositionObject		( iLoop + 5000 , -99999, -99999 , -99999 );
		dbSetObjectCollisionOff ( iLoop + 5000 );

		crumbs[iLoop][0] = - 99999;
		crumbs[iLoop][1] = - 99999;
		crumbs[iLoop][2] = 0;
		dbHideObject ( iLoop + 5000 );
	}




	for ( int iLoop = 0 ; iLoop < MAXFIREBALLS ; ++iLoop )
	{
		dbMakeObjectPlane		( iLoop + 10000 + MONSTER, 10 , 10 );
		//dbCloneObject			( iLoop + 10000 + ATrooper , iLoop + 10000 + MONSTER );
		
		dbSetObjectCollisionOff ( iLoop + 10000 + MONSTER );
		//dbSetObjectCollisionOff ( iLoop + 10000 + ATrooper );
		
		dbTextureObject			( iLoop + 10000 + MONSTER , MonsterLaser );
		//dbTextureObject			( iLoop + 10000 + ATrooper , ATlaser );
		
		//dbSetObjectAmbient		( iLoop + 10000 + MONSTER , 0 );
		//dbSetObjectAmbient		( iLoop + 10000 + ATrooper , 0 );

		dbFadeObject			( iLoop + 10000 + MONSTER , 800 );
		//dbFadeObject			( iLoop + 10000 + ATrooper , 800 );
		
		dbSetObjectTransparency ( iLoop + 10000 + MONSTER , 1 );
		////dbSetObjectTransparency ( iLoop + 10000 + ATrooper , 1 );/*This command will set the transparency state of the specified
		//							   object. Setting the transparency to one will ensure the 
		//							   object does not draw the transparent colour during final 
		//							   rendering. The transparent colour is determined by the 
		//							   dbSetImageColorKey command.*/
		dbSetObjectLight		( iLoop + 10000 + MONSTER , 0 );
		//dbSetObjectLight		( iLoop + 10000 + ATrooper , 0 );

		//dbSetObject				( iLoop + 10000 + MONSTER , 1 , 0 , 0 );


		fire[iLoop].baddie	= 0;
		fire[iLoop].on		= false;

		fire[iLoop].angleY	= 0.0f;
		dbHideObject			( iLoop + 10000 + MONSTER );
	}

}



void setup()
{
	CreateLevel ( );

	dbHideLight					( muzzleflashLight );
	dbSetAmbientLight			( 30 );/*This command will set the percentage level of ambient light. 
									   A setting of 100 provides full illumination and no shadow 
									   whereas a setting of zero gives no illumination and 
									   substantial shadowing on any 3D object. */
	dbSetPointLight				( 0 , 0 , 0 ,0 );
	dbColorLight				( 0 , 0x00FFFF00 );
	dbSetLightRange				( 0 , 400 );
	dbPositionCamera			( 0 , 200.0f , 40.0f , 100.0f );
	dbAutomaticCameraCollision	( 0 , 10 , 0 );
	dbSetCameraRange			( 0 , 1 , 2000 );

	//setupVis					( );


}

void Fade (int imgNr, int starta, int stopa, int rate)
{
	dbGetImage ( 1001, 0, 0, screenX, screenY , 1 );

	dbSprite (imgNr, 0, 0, imgNr);
	dbSetSprite (imgNr, 0, 1);
	dbSetSpritePriority (imgNr, 1000);
	int a = starta;
	int r;
	if ( starta > stopa )
		r = -rate;
	else
		r = rate;
	
	do
	{
		dbSetSpriteAlpha ( imgNr, a );
		dbPasteImage ( 1001, 0, 0, 0 );
		a += r;
		dbSync();
	}
	while ( (r>0 && a>stopa) || (r<0 && a<stopa) );
	dbSetSpriteAlpha (imgNr, stopa);
	dbPasteImage ( 1001, 0, 0, 0 );
	dbSync();
}
inline void GameCycle()
{
	static eGame D9 = eMenuStart;
	switch ( D9 )
	{
	case eMain:
		{
			if (	(dbCameraPositionX ( ) >= ( 11 * 100.0f ) )
				&&	(dbCameraPositionZ ( ) >= ( 48 * 100.0f ) ) 
				&&	(iDeadBaddies == iNumBaddies) )
			{
				D9 = eWon;
			}
			//dead?
			if ( iHealth > 0 )
			{
				
				updatePlayer	( );
				updateBaddies	( );
				updateDoors		( );
				HUD				( );
				updateFire		( );
			}
			else
			{
				die( );
				static bool sound = true;
				if ( sound )
				{
					dbStopSound ( gunSound );
					sound = false;
				}
			}
			if(dbEscapeKey() == 1 )
			{
				D9 = eMenuStart;
			}
			

		}break;
	
	case eMenu:
		{
			int click = dbMouseClick ( );
			static int oldButton=0;
			int mx = dbMouseX ( );
			int my = dbMouseY ( );
			
			/*if ( click )
			{	r=rand()%255;
				g=rand()%255;
				 b=rand()%255;
				dbColorParticles ( ParticleNumber, r,g,b );
			}*/
			//dbPositionParticleEmissions ( ParticleNumber, ( dbMouseX ( ) - 320 ) / 2.0f , ( 360 - dbMouseY ( ) ) / 2.0f, 200 );
			
			static bool credits = false;
			dbCopyBitmap  ( controlsImage,0,0,dbBitmapWidth( controlsImage ),dbBitmapHeight( controlsImage ),0,0,0,screenX,screenY );
			dbSetCurrentBitmap ( 0 );
			static bool once = true;
			
			dbSetTextSize ( 30 );
			dbSetTextFont ( "Arial Black");
			dbInk ( dbRgb ( 255,255,255 ),0 );
			if ( once )
			{
			
				
				if (mx > playX  && mx < playX +dbTextWidth ( "NEW GAME" )  && my > playY && my < playY + dbTextHeight ( "NEW GAME" ))
				{
					dbInk ( dbRgb(50,50,255 ),0 );
					dbText ( playX,playY,"NEW GAME");
					if ( click == 1 && oldButton != 1 )
						D9 = eStart,once  =  false;
				}
				else
				{
					dbInk ( dbRgb ( 255,255,255 ),0 );
					dbText (  playX , playY , "NEW GAME");
				}
			}
			else
			{
				if ( ! credits )
				{
					if (mx > playX  && mx < playX + dbTextWidth ( "BACK" ) && my > playY && my < playY + dbTextHeight ( "BACK" ))
					{
						dbInk ( dbRgb(50,50,255 ),0 );
						dbText (  playX,playY,"BACK" );
						if ( click == 1 && oldButton != 1 )
							D9 = eStart;
					}
					else
					{
						dbInk ( dbRgb ( 255,255,255 ),0 );
						dbText ( playX,playY,"BACK" );
					}
				}

			}
			
			if ( credits )
			{
				if (mx > playX  && mx < playX + dbTextWidth ( "BACK" ) && my > creditsY && my < creditsY + dbTextHeight ( "BACK" ))
				{
					dbInk ( dbRgb(50,50,255 ),0 );
					dbText (  playX,creditsY,"BACK" );
					if ( click == 1 && oldButton != 1 )
						credits = false;
				}
				else
				{
					dbInk ( dbRgb ( 255,255,255 ),0 );
					dbText (  playX,creditsY,"BACK" );
				}
				dbSetTextFont ( "Verdana" );
				dbInk ( dbRgb(202,0,0), 0 );
				dbCenterText ( (screenX>>1 ),(screenY>>1) - 20, "Created by Ion Laurentiu Cristian" );
				dbSetTextFont ( "Arial Black");
				
			}
			else
			{
				if (mx > creditsX  && mx < creditsX + dbTextWidth ( "CREDITS" ) && my > creditsY && my < creditsY + dbTextHeight ( "CREDITS" ))
				{
					dbInk ( dbRgb(50,50,255 ),0 );
					dbText ( creditsX,creditsY,"CREDITS");
					if ( click == 1 && oldButton != 1 )
						credits = true;
				}
				else
				{
					dbInk ( dbRgb ( 255,255,255 ),0 );
					dbText (  creditsX , creditsY , "CREDITS" );
				}
				
			}


			if (mx > playX  && mx < playX + dbTextWidth ( "EXIT" ) && my > exitY && my < exitY + dbTextHeight ( "EXIT" ))
			{
				dbInk ( dbRgb(50,50,255 ),0 );
				dbText ( playX,exitY,"EXIT");
				if ( click == 1 && oldButton != 1 )
				{
					bGame = false;
					dbSetTextFont ( "Verdana" );
					dbInk ( dbRgb(202,0,0), 0 );
					dbCenterText ( (screenX>>1 ),40,"Iesirea din Baza Districtului 9" ); 
					dbCenterText ( (screenX>>1 ),(screenY>>1) - 6, "Created by Ion Laurentiu Cristian" );
					dbCenterText ( (screenX>>1 ),(screenY>>1) + 20,"Esti primul care a iesit teafar din acel hangar... Ai talent!");
					//dbSleep ( 2000 );
					//dbWaitKey	( );
				}
			}
			else
			{
				dbInk ( dbRgb ( 255,255,255 ),0 );
				dbText (playX,exitY,"EXIT");
			}

			static bool once2 = true;
			if( once2 )
			{
				once2 = false;
			}
			else if(dbEscapeKey() == 1 )
			{
				D9 = eMenuStart;
			}
			
			
			oldButton = click;
				
		}break;
	case eMenuStart:
	{
		dbShowMouse ( );
		dbPauseMusic ( 2 );
		dbLoopMusic ( 1 );
		D9 = eMenu;
	}break;
	case eStart:
		{
				dbHideMouse ( );
				
				bool once = true;
				//dbDeleteBitmap  (  controlsImage  );

				dbStopMusic ( 1 );
				
				dbPlayObject			( gunObj , _select , select_ );
				dbLoadSound			( "guns\\tavor\\cock_Separate.wav" , returned , 0 );	
				dbPlaySound ( returned );
				if ( once )
				{
					dbLoopMusic ( 2 );
					once = false;
				}
				else
				{
					dbResumeMusic ( 2 );
				}
				D9 = eMain;
		}break;
	case eWon:
		{
			//dbPasteImage ( YouWin, 0, 0, 1 );
			dbCopyBitmap  ( YouWin,0,0,dbBitmapWidth( YouWin ),dbBitmapHeight( YouWin ),0,0,0,screenX,screenY );
			dbSetCurrentBitmap ( 0 );
			static bool once = true;
			if( once )	
			{
				dbPlaySound	 ( RoundWin );
				once = false;
			}
		}break;

	}
	

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float OldCamAngleY;
float OldCamAngleX;
float CameraAngleY;
float CameraAngleX;




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void HandleKeys ( void )
{
	

	//dbControlCameraUsingArrowKeys ( 0 , 1 , 1 );
	dbPositionMouse ( dbScreenWidth()/2 , dbScreenHeight()/2 );

	if ( dbUpKey() || dbKeyState( 17 ) == 1 )
	{
		dbMoveCamera ( 0 , fPlayerSpeed );
		fGunWaggle += 0.5f;
		fGunWaggle2 += 0.25f;
		if ( shakeCrosshair < 10 )
		{
			++shakeCrosshair;
		}
		/*if ( dbSoundPlaying ( footsteps ) == 0 ) //footsteps.wav
	  {
         dbLoopSound ( footsteps , 0 , 10000 , 0 );
	  } */

	}
	if ( dbDownKey() || dbKeyState( 31 ) == 1 ) 
	{
		if ( shakeCrosshair < 10 )
		{
			++shakeCrosshair;
		}
		dbMoveCamera ( 0 , -fPlayerSpeed );
		fGunWaggle += 0.5f;
		fGunWaggle2 += 0.25f;
		/*if ( dbSoundPlaying ( footsteps ) == 0 ) //footsteps.wav
	  {
         dbLoopSound ( footsteps , 0 , 10000 , 0 );
	  } */
	}
	
	if ( dbLeftKey() || dbKeyState( 30 ) == 1 )
	{
		if ( shakeCrosshair < 10 )
		{
			++shakeCrosshair;
		}
		fGunWaggle += 0.5f;
		dbYRotateCamera ( 0 , dbCameraAngleY( 0 ) -90 );
		dbMoveCamera ( 0 , fPlayerSpeed );
		dbYRotateCamera ( 0 , dbCameraAngleY( 0 ) +90 );
		/*if ( dbSoundPlaying ( footsteps ) == 0 ) //footsteps.wav
	  {
         dbLoopSound ( footsteps , 0 , 10000 , 0 );
	  } */
	}

	if ( dbRightKey() || dbKeyState( 32 ) == 1 )
	{
		if ( shakeCrosshair < 10 )
		{
			++shakeCrosshair;
		}
		fGunWaggle += 0.5f;
		dbYRotateCamera ( 0 , dbCameraAngleY( 0 ) + 90 );
		dbMoveCamera ( 0 , fPlayerSpeed );
		dbYRotateCamera ( 0 , dbCameraAngleY( 0 ) -90 );
		/*if ( dbSoundPlaying ( footsteps ) == 0 ) //footsteps.wav
	  {
         dbLoopSound ( footsteps , 0 , 10000 , 0 );
	  } */
	}

   float OldCamAngleY = dbCameraAngleY ( 0 );
   float OldCamAngleX = dbCameraAngleX ( 0 );

   CameraAngleY = dbWrapValue ( ( dbCameraAngleY ( 0 ) +  dbMouseMoveX ( ) * 0.4f ) );
   CameraAngleX = dbWrapValue ( ( dbCameraAngleX ( 0 ) + dbMouseMoveY ( ) * 0.4f ) );

   if ( CameraAngleX > 80 && CameraAngleX <180 ) 
	   CameraAngleX = 80;
   if ( CameraAngleX < 270 && CameraAngleX > 180 ) 
	   CameraAngleX = 270;

   dbYRotateCamera	( 0 , dbCurveAngle ( CameraAngleY , OldCamAngleY , 6 ) );
   dbXRotateCamera	( 0 , dbCurveAngle ( CameraAngleX , OldCamAngleX , 6 ) );

   dbPositionCamera ( 0 , dbCameraPositionX ( 0 ) , 40 , dbCameraPositionZ ( 0 ) );
   dbSetPointLight	( 0 , dbCameraPositionX ( 0 ) , 80 , dbCameraPositionZ ( 0 ) );

}
inline void updatePlayer()
{
	int oldX = ( (( ( int ) ( dbCameraPositionX ( 0 ) - 50 )) >>2 ) /25 + 1 );
	int oldZ = ( (( ( int ) ( dbCameraPositionZ ( 0 ) - 50 )) >>2 ) /25 + 1 );
	int newX;
	int newZ;
	int iStrike;		// which baddie has been hit
	int iOldBaddieRotY; // used so we can face the baddie to the camera, blast him away and rotate back
	int iLoop;
	int iBloodLoop = 0;

//	static int		gunFrame		= 54;
	static int		gunFrame2		= 65;
	

	//if( dbScanCode() == 16 )
	//	GunAngleY-=0.1f;
	//if( dbScanCode() == 18 )
	//	GunAngleY+=0.1f;

	//if(strcmp(dbInKey(), "u") == 0)
	//	GunAngleX-=0.1f;
	//if(strcmp(dbInKey(), "j") == 0)
	//	GunAngleX+=0.1f;
	//
	//if(dbScanCode() == 34)
	//	GunZ-=0.1f;
	//if(dbScanCode() == 20)
	//	GunZ+=0.1f;
	//
	//if(dbScanCode() == 33)
	//	GunX-=0.1f;
	//if(dbScanCode() == 35)
	//	GunX+=0.1f;

	//if(dbScanCode() == 23)
	//	GunY-=0.1f;
	//if(dbScanCode() == 37)
	//	GunY+=0.1f;
	if(dbScanCode() == 25)
	{
		dbSetCursor ( 1,80 );
		/*dbPrint ( (double)GunX );
		dbPrint ( (double)GunY );
		dbPrint ( (double)GunZ );*/
		dbPrint ( (LONGLONG) screenX );
		dbPrint ( (LONGLONG) screenY );
		
		//dbPrint ( (double)GunAngleX );
		//dbPrint ( (double)GunAngleY );
	}
	
	
	
	//wsprintf ( czText , "Gun Move Z: %f" , GunMove );
	//dbText ( 0, dbScreenHeight ( ) - 45, czText );
	
	// viteza in functie de dbScreenFPS ( )
	fps = (float) dbScreenFPS ( );
	fPlayerSpeed = 4.5f *  ( 30.0f / (( fps > 10 )?fps:10) );
	fBaddieSpeed = 4.0f *  ( 30.0f / (( fps > 10 )?fps:10) );
/*
	float cx=dbCameraPositionX(  );
	float cz=dbCameraPositionZ(  );
	float cax=dbCameraAngleX(  );
	float cay=dbCameraAngleY(  );
	float gx=dbObjectPositionX( gunObj );
	float gy=dbObjectPositionY( gunObj );
	float gz=dbObjectPositionZ( gunObj );
*/
	HandleKeys ( );
	//breathing
	dbPositionCamera (	dbCameraPositionX ( 0 ) ,
						dbCameraPositionY ( 0 ) + cos ( fGunWaggle / 2.0f ) ,
						dbCameraPositionZ ( 0 ) );
	if ( bZoom )
	{
		//_fov=dbCurveAngle ( 100.0f , fov , 3 );
	
		//dbSetCameraFOV ( 0, _fov );
		zz +=  dbMouseMoveZ();
			 
		if ( zz < 0 )
			zz=0;
		else if ( zz > 480 )
			zz=600;
	
		dbSetCameraFOV ( 0, 28.0f - (5 * zz/120) );
		//dbCopyBitmap ( zoomScope , 0,0,dbBitmapWidth(zoomScope),dbBitmapHeight(zoomScope),0,0,0,screenX,screenY );
		dbPasteImage	( zoomScope , 0,0,1 );
		dbHideObject   ( gunObj );
		dbHideObject   ( muzzleFlashObj );
	}
	else
	{
		dbShowObject	( gunObj );
		dbShowObject	( muzzleFlashObj );
		zz = 0;
		//_fov=dbCurveAngle ( 90.0f , fov , 3 );
		//dbSetCameraFOV ( 0 , _fov ); 
		dbSetCameraFOV ( 0 , 61.9621f ); 

		//GUN
		dbSetObjectToCameraOrientation ( gunObj );
		dbSetObjectToCameraOrientation ( muzzleFlashObj );
		//dbSetObjectToObjectOrientation ( muzzleFlashObj , gunObj);
	
		dbPositionObject		( gunObj ,	dbCameraPositionX ( 0 ),
											dbCameraPositionY ( 0 ),
											dbCameraPositionZ( 0 ) );
	
		dbMoveObjectRight		( gunObj , GunX );
  
		dbMoveObject			( gunObj , GunZ );
   
		dbMoveObjectDown		( gunObj , GunY );
		dbYRotateObject			( gunObj , dbObjectAngleY( gunObj ) + GunAngleY );
		dbXRotateObject			( gunObj , dbObjectAngleX( gunObj ) + GunAngleX );
		
		
		if (	dbUpKey() == 0 
			&&	dbDownKey() == 0 
			&&	dbLeftKey() == 0 
			&&	dbRightKey() == 0 
			&&	dbKeyState( 17 ) == 0 
			&&	dbKeyState( 30 ) == 0 
			&&	dbKeyState( 31 ) == 0 
			&&	dbKeyState( 32 ) == 0 
			&&	dbMouseClick() == 0
			)
		{
			dbLoopObject			( gunObj , _idle , idle_ );
		}

		if (  ( dbUpKey() == 1 
			||	dbDownKey() == 1 
			||	dbLeftKey() == 1 
			||	dbRightKey() == 1 
			||	dbKeyState( 17 ) == 1 
			||	dbKeyState( 31 ) == 1 
			||	dbKeyState( 31 ) == 1 
			||	dbKeyState( 32 ) == 1 
			   )
			&&  dbMouseClick()== 0
			)
		{
			dbLoopObject			( gunObj , _move , move_ );
		}

	}
		fGunWaggle += 0.25f;//////////also incerc aici <
		
		// draw cross hair
		// draw cross hair and gun icon
		//dbDrawSpritesLast( );
	//bPasteSprite ( 1 , ( (screenX) >>1 ) - 16 , ( (screenY) >>1 ) - 16  );
	
	//__________________________crosshair:______________________________
		if (	dbUpKey() == 0 
			&&	dbDownKey() == 0 
			&&	dbLeftKey() == 0 
			&&	dbRightKey() == 0 
			&&	dbKeyState( 17 ) == 0 
			&&	dbKeyState( 30 ) == 0 
			&&	dbKeyState( 31 ) == 0 
			&&	dbKeyState( 32 ) == 0 
			&&	dbMouseClick() == 0
			&&	shakeCrosshair > 4
			)
		{
			--shakeCrosshair;
		}
		dbInk ( dbRgb(0,200,0),1 );
	
		dbLine ( ( screenX>>1 ) - 10 - shakeCrosshair ,
				( screenY>>1 ) ,  
				( screenX>>1 ) - shakeCrosshair ,
				( screenY>>1 )
				);
		
		dbLine ( ( screenX>>1 ) + shakeCrosshair ,
				( screenY>>1 ) ,  
				( screenX>>1 ) + shakeCrosshair + 10,
				( screenY>>1 )
				 );
	
		dbLine ( ( screenX>>1 ),
				( screenY>>1 ) - 10 - shakeCrosshair,  
				( screenX>>1 ) ,
				 ( screenY>>1 ) - shakeCrosshair
				);	
	
		dbLine ( ( screenX>>1 ) ,
				( screenY>>1 ) + shakeCrosshair ,  
				( screenX>>1 ) ,
				( screenY>>1 ) + shakeCrosshair + 10
				);
		//_____________________________________________________________
	
	
		//dbPasteSprite ( tavorHUD , screenX - 300 , 10 );
		dbPasteImage ( tavorHUD , screenX - 300 , 10 , 1 );
	//dbPasteImageEx ( 		
	for ( iBloodLoop = 0 ; iBloodLoop < 10 ; ++iBloodLoop )
	{
		dbSetAlphaMappingOn ( 13 + iBloodLoop , iBloodAlpha[ iBloodLoop ]);
		if ( iBloodAlpha[ iBloodLoop ] > 0.0f )
		{
			iBloodAlpha[ iBloodLoop ] -= 2;
			if ( iBloodLoop % 2 )
			{
				dbRollObjectLeft ( 13 + iBloodLoop, 2 );
			}
			else
			{
				dbRollObjectRight ( 13 + iBloodLoop, 2 );
			}
			dbMoveObjectDown ( 13 + iBloodLoop , 0.6f );
		}
	}
	
	if ( dbMouseClick() == 1 || dbMouseClick() == 3 )
	{
		/*if ( gunFrame++ < 57 )
			dbSetObjectFrame ( gunObj , gunFrame );
		else
		{*/
			dbLoopObject	( gunObj , _startFire , automaticFire_ );
		/*}*/
		if ( shakeCrosshair < 14 )
		{
			++shakeCrosshair;
		}

		if ( dbSoundPlaying ( gunSound ) == 0 )
		{
			dbLoopSound ( gunSound , 0 , 10000 , 0 );
		}
		//iShow = rand () % 2;
	    if ( ++iPlayerBullet == 2 )
		{
			if ( dbSoundPlaying ( gunSound ) == 0 )
			{
				dbLoopSound ( gunSound , 0 , 10000 , 0 );
			}
			iPlayerBullet = 0;
			dbShowObject ( muzzleFlashObj );
	        dbRollObjectLeft ( muzzleFlashObj , (float)(rand() % 360) );
			dbShowLight ( 0 );
			dbPositionLight ( 0 , dbObjectPositionX ( muzzleFlashObj ) , dbObjectPositionY ( muzzleFlashObj ), dbObjectPositionZ ( muzzleFlashObj ) );
			// Have we shot a baddie?
			iStrike = dbPickObject ( dbScreenWidth( ) / 2 , dbScreenHeight( ) / 2 , 100 , 5000 );
			if ( iStrike >= 100 && iStrike < 200 )
			{
				dbPositionObject ( 12 + iBlood , dbCameraPositionX ( 0 ) + 0 , dbCameraPositionY ( 0 ) + 0 , dbCameraPositionZ ( 0 ) + 0 );
				dbSetObjectToCameraOrientation ( 12 + iBlood );
				dbMoveObject ( 12 + iBlood , getDistance ( dbCameraPositionX ( 0 ) , 0 , dbCameraPositionZ ( 0 ) , dbObjectPositionX ( iStrike ) , 0 , dbObjectPositionZ ( iStrike ) ) -30 );
				dbShowObject ( 12 + iBlood );
				iBloodAlpha[ iBlood ] = 100;
				if (++iBlood == 9 ) iBlood = 0;
			
				iOldBaddieRotY = (int) dbObjectAngleY	( iStrike );
				dbSetObjectToCameraOrientation		( iStrike );
				dbXRotateObject					( iStrike , 0 );
				dbYRotateObject					( iStrike , (float)iOldBaddieRotY );
	
				if ( baddie [ iStrike - 100 ].mode < 2 ) baddie [ iStrike - 100 ].mode = 2;
	
				 if ( baddie[ iStrike - 100 ].hitCount < 5 || baddie[ iStrike - 100 ].hitCount == 7 )
				{
					baddie [ iStrike - 100 ].hit = true;
					dbStopObject ( iStrike );
					++baddie [ iStrike - 100 ].hitCount;
					if ( baddie [ iStrike - 100 ].hitCount == 5 )
					{
						--baddie [ iStrike - 100 ].life;
						if ( baddie [ iStrike - 100 ].life <= 0 ) //baddie died!! :((
						{
							++iDeadBaddies;
							dbPlayObject ( baddie [ iStrike - 100 ].obj , 370*160 , 400*160 );
							dbTextureObject ( baddie [ iStrike - 100 ].obj + 100 , blood1 );
							dbSetObjectCollisionOff ( baddie [ iStrike - 100 ].obj );
							dbScaleObject ( baddie [ iStrike - 100 ].obj + 100 , 200 , 100 , 200 );
							//dbMoveObjectDown ( baddie [ iStrike - 100 ].obj , 10 );
							if ( baddie [ iStrike - 100 ].type == 0 )//monster
								dbPlaySound ( monsterFinalmoan );
							else
								dbPlaySound ( ATfinalmoan );
						}
					}
					if ( baddie[ iStrike - 100 ].hitCount > 7 )
						baddie[ iStrike - 100 ].hitCount = 0;
				}
				//else//hit a wall or floor or pillar --> smoke and particles
				//{

				//}
			}
		}
		else
		{
			dbHideObject	( muzzleFlashObj );
			dbHideLight	( 0 );
		}
		gunFrame2 = 65;
   }
   else
   {
		if ( gunFrame2++ < 71 )
			dbSetObjectFrame ( gunObj , gunFrame2 );
		//gunFrame = 54;
		iPlayerBullet	= 1;
		dbStopSound	( gunSound );//gun1.wav
		dbHideObject( muzzleFlashObj );
		dbHideLight	( muzzleflashLight );
	}
	static bool rightclick = false;
	if ( dbMouseClick() == 2 || dbMouseClick() == 3)
	{
		if ( !rightclick )
		{		
			rightclick = true;		
			bZoom=!bZoom;
			shakeCrosshair = 5;
			dbPlaySound ( zoomSound );
		}		
	}
	else
	{
		rightclick = false;
	}




	//__________________________________________flash____________________________________
		dbPositionObject		( muzzleFlashObj ,	dbLimbPositionX ( gunObj, FIRESPOT ) ,
													dbLimbPositionY ( gunObj, FIRESPOT ) ,
													dbLimbPositionZ ( gunObj, FIRESPOT ) );




	
   /*
	int oldX = ( ( int ) ( dbCameraPositionX ( 0 ) - 50 ) / 100 + 1 );
	int oldZ = ( ( int ) ( dbCameraPositionZ ( 0 ) - 50 ) / 100 + 1 );
	*/
	newX = ( ( ( int ) ( dbCameraPositionX ( 0 ) - 50 ))>>2) / 25  + 1 ;
	newZ = ( ( ( int ) ( dbCameraPositionZ ( 0 ) - 50 ))>>2) / 25  + 1 ;

   // drop a crumb?
   if (		( oldX != newX || oldZ != newZ ) 
	   &&	( szLevel[newZ][newX] == '#' 
	   ||	szLevel[newZ][newX] == '+' 
	   ||	szLevel[newZ][newX] == 's' 
	   ||	szLevel[newZ][newX] == 'n' )   )// || ( ++timer == 8 && szLevel[newZ][newX] != 'o') ) // || szLevel[newZ][newX] == '.' ) //also drop a crumb ( firimitura ) near a pillar? 
   {
		++iCurrentCrumb;
		if (iCurrentCrumb > MAXCRUMBS-1 )
			iCurrentCrumb = 0; // reset and kill off the first crumb
		crumbs[iCurrentCrumb][0] = (( ( (int) ( dbCameraPositionX ( 0 ) - 50 ) / 100 ) + 1) * 100 ) ;
		crumbs[iCurrentCrumb][1] = (( ( (int) ( dbCameraPositionZ ( 0 ) - 50 ) / 100 ) + 1) * 100 ) ;
		crumbs[iCurrentCrumb][2] = ++iCrumbCount;
		dbPositionObject ( 5000+iCurrentCrumb , (float)crumbs[iCurrentCrumb][0] , 0 , (float)crumbs[iCurrentCrumb][1] );
		dbSetObjectCollisionOff ( 5000+iCurrentCrumb );
			
		// clear the baddies flags since no baddies have hit this crumb yet
		for ( iLoop = 3 ; iLoop < baddieCount+2 ; ++iLoop)
					crumbs[iCurrentCrumb][iLoop] = 0; 
   }
   	dbPositionListener( dbCameraPositionX	( ),
						dbCameraPositionY	( ),
						dbCameraPositionZ	( ) );
	dbRotateListener (	dbCameraAngleX		( ),
						dbCameraAngleY		( ),
						dbCameraAngleZ		( ) );
	dbScaleListener							( 4 );

	//cheats:	
/*  char* szKey = dbInKey ( );

	if ( strcmp ( szKey, "+" ) == 0 && dbShiftKey ( ) && dbControlKey ( ) && dbRightKey ( ) )
	{
		if ( fPlayerSpeed < 1000 )
			fPlayerSpeed += 0.01f;
	}

	if ( strcmp ( szKey, "-" ) == 0 && dbShiftKey ( ) && dbControlKey ( ) && dbRightKey ( ) )
	{
		if ( fPlayerSpeed > 0.02f )
			fPlayerSpeed -= 0.01f;
	}
*/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void updateBaddies()
{
	float	fX;
	float	fZ;
	int		whichWay;
	char	chCol = ' ';
	int		prevZ; // = (int) ( ( dbObjectPositionZ ( 100 ) - 50 ) / 100.0f ) + 1;
	int		prevX; // = (int) ( ( dbObjectPositionX ( 100 ) - 50 ) / 100.0f ) + 1;
	int		curAngle; // = dbWrapValue ( dbObjectAngleY ( 100 ) );
	float	dist;
	float	dist2;
	float	dist3;
	int		crumb; // If this stays set to 0 then the baddie will turn to the camera otherwise turn to object crumb+5000
	bool	hit;
	int		odd; //odd or even baddie number to decide direction round things
	int		colX;
	int		colZ;
	int		oldColX;
	int		oldColZ;
	//int		colLoop;
	//int		plusZ;
	//int		plusX;
	//bool	hasCol;


	for (int iLoop = 0 ; iLoop < baddieCount ; ++iLoop )
	{
		if ( baddie [ iLoop ].life > 0 )
		{
			switch ( baddie [ iLoop ].mode )
			{
			case 0:
				{
					dbLoopObject ( baddie [ iLoop ].obj , 0 , 80*160 );
					baddie [ iLoop ].mode = 1;
				} break;
			case 1:
				{
					dist = getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
										0 , 
										dbObjectPositionZ ( baddie [ iLoop ].obj ) , 
										dbCameraPositionX ( 0 ) , 
										0 , 
										dbCameraPositionZ ( 0 ) );
					if (dist < 1000 )
						baddie [ iLoop ].mode = 2;
				} break;
			case 2:
				{
					dbLoopObject ( baddie [ iLoop ].obj , 91200 , 100800 );
					if ( baddie [ iLoop ].type==MONSTER ) //monster
					{
						dbPositionSound ( roar , dbObjectPositionX( baddie [ iLoop ].obj ), dbObjectPositionY( baddie [ iLoop ].obj ), dbObjectPositionZ( baddie [ iLoop ].obj ) );
						dbPlaySound ( roar , 0 );//roar
					}
					else
					{
						dbSetSoundVolume ( ATsound , 100 );
						dbPositionSound ( ATsound , dbObjectPositionX( baddie [ iLoop ].obj ), dbObjectPositionY( baddie [ iLoop ].obj ), dbObjectPositionZ( baddie [ iLoop ].obj ) );
						dbPlaySound ( ATsound , 0 );//attacking enemies.wav
					}
					baddie [ iLoop ].mode = 3;
				} break;
			case 3:
				{
					prevZ = ((int) ( ( dbObjectPositionZ ( baddie [ iLoop ].obj ) - 50 ))>>2 ) / 25  + 1;
					prevX = ((int) ( ( dbObjectPositionX ( baddie [ iLoop ].obj ) - 50 ))>>2 ) / 25  + 1;
					curAngle = (int)dbWrapValue ( dbObjectAngleY ( baddie [ iLoop ].obj ) );
					crumb = 0; // If this stays set to 0 then the baddie will turn to the camera otherwise turn to object crumb+5000
					hit = false;

					if ( ! baddie [ iLoop ].hit)
					{
						if ( dbObjectPlaying ( baddie [ iLoop ].obj ) == 0 ) 
							dbLoopObject ( baddie[ iLoop ].obj , 91200 , 100800 );
						
						fX = dbCameraPositionX ( 0 ) - dbObjectPositionX ( baddie [ iLoop ].obj );
						fZ = dbCameraPositionZ ( 0 ) - dbObjectPositionZ ( baddie [ iLoop ].obj );
						
						dist = getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
											0 ,
											dbObjectPositionZ ( baddie [ iLoop ].obj ) ,
											dbCameraPositionX ( 0 ) ,
											0 ,
											dbCameraPositionZ ( 0 ) );


						for ( int iLoop2 = 0 ; iLoop2 < baddieCount ; ++iLoop2 )
						{
							if ( iLoop2 != iLoop )
							{
								if ( baddie[ iLoop2 ].life > 0 )
								{
									dist2 = getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
															0 ,
															dbObjectPositionZ ( baddie [ iLoop ].obj ) ,
															dbObjectPositionX ( baddie [ iLoop2 ].obj ) ,
															0 ,
															dbObjectPositionZ ( baddie [ iLoop2 ].obj ) );
									
									
									dbMoveObject ( baddie [ iLoop ].obj , fBaddieSpeed );
									
									
									dist3 = getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
															0 ,
															dbObjectPositionZ ( baddie [ iLoop ].obj ) ,
															dbObjectPositionX ( baddie [ iLoop2 ].obj ) ,
															0 ,
															dbObjectPositionZ ( baddie [ iLoop2 ].obj ) );
									if ( dist3 < dist2 
										&&  dist3 < 40 )
										dist = 0;
									dbMoveObject ( baddie [ iLoop ].obj , -fBaddieSpeed );
								}
							}
						}
						
						if ( baddie [ iLoop ].type == MONSTER )
						{
							if( dist > 80 ) 
							{
								oldColZ = ((int) ( ( dbObjectPositionZ ( baddie [ iLoop ].obj ) - 50 ))>>2 ) / 25  + 1;
								oldColX = ((int) ( ( dbObjectPositionX ( baddie [ iLoop ].obj ) - 50 ))>>2 ) / 25  + 1;
								dbMoveObject ( baddie [ iLoop ].obj , fBaddieSpeed );
								if ( baddie [ iLoop ].attack == true 
									&& dbObjectFrame ( baddie [ iLoop ].obj ) > 195*160 )
								{
									baddie [ iLoop ].attack = false;
									baddie [ iLoop ].mode = 2;
								}
							}
							else /* SLASH ATTACK */ 
								
							{
						
								dbLoopObject ( baddie [ iLoop ].obj , 150*160 , 200*160 );
								
								if( dbObjectFrame( baddie [ iLoop ].obj )> (1670 * 16) 
									&& dbObjectFrame( baddie [ iLoop ].obj ) < (1700 * 16 )
									//&& baddie [ iLoop ].attack
									)
								
								{
									//if ( dist < 30 )
									//{
										static bool once=true;
										dbBox(0,0,dbScreenWidth(),dbScreenHeight(), dbRgb(16,0,0), dbRgb(64,10,10), dbRgb(64,10,10), dbRgb(16,0,0) ); 
										//dbPasteSprite ( damageBox , 0 ,0 );
										//dbPasteImage ( damageBox , 0 ,0,1 );
										
										if ( once )
										{
											float oldAngleY= dbCameraAngleY();
											dbPlaySound ( hurt1 );
										}
										once = !once;
										if( iHealth )
											--iHealth ;//Damage player when anim struck
									//}
																		
								}
								baddie [ iLoop ].attack = true;
								
							
							}
						}
						else if ( baddie [ iLoop ].type == ATrooper )
						{
							if( dist > 300 )
							{
								oldColZ = ((int) ( ( dbObjectPositionZ ( baddie [ iLoop ].obj ) - 50 ))>>2 ) / 25  + 1;
								oldColX = ((int) ( ( dbObjectPositionX ( baddie [ iLoop ].obj ) - 50 ))>>2 ) / 25  + 1;
								dbMoveObject ( baddie [ iLoop ].obj , fBaddieSpeed );
								if ( baddie [ iLoop ].attack == true 
									&& dbObjectFrame ( baddie [ iLoop ].obj ) > 195*160 )
								{
									baddie [ iLoop ].attack = false;
									baddie [ iLoop ].mode = 2;
								}
							}
							else
							{
								if ( dbObjectFrame( baddie [ iLoop ].obj ) > 91200 && dbObjectFrame( baddie [ iLoop ].obj ) < 100800 )
								{
									dbStopObject ( baddie [ iLoop ].obj ); 
									dbLoopObject ( baddie [ iLoop ].obj , 0 , 80*160 );
								}
							}
						}
					
						// Check for collision
						chCol = szLevel	[ ((int) ( ( dbObjectPositionZ ( baddie [ iLoop ].obj ) - 50 ) )>>2 )/25  + 1 ]
										[ ((int) ( ( dbObjectPositionX ( baddie [ iLoop ].obj ) - 50 ) )>>2 )/25  + 1 ];
						if ( chCol == 'o' || chCol == '^' )	
						{
							dbMoveObject ( baddie [ iLoop ].obj , -fBaddieSpeed );
							odd = ( iLoop % 2 );
							( odd == 0 ) ? dbMoveObjectRight ( baddie [ iLoop ].obj , 1.5f ) : dbMoveObjectLeft ( baddie [ iLoop ].obj , 1.5f );
						}
						else if ( chCol == '1' || chCol == '2' )	
						{
							colZ = (((int) ( dbObjectPositionZ ( baddie [ iLoop ].obj ) - 50 ))>>2) / 25 + 1;
							colX = (((int) ( dbObjectPositionX ( baddie [ iLoop ].obj ) - 50 ))>>2) / 25 + 1;
							// moved west
							if ( oldColX > colX ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 270 );
							// moved east
							if ( oldColX < colX ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 90 );
							// moved north
									//don't rotate
							// moved south
							if ( oldColZ > colZ ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 180 );
							// moved north east 
							if ( oldColZ < colZ && oldColX < colX ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 45 );
							// moved north west
							if ( oldColZ < colZ && oldColX > colX ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 315 );
							// moved south west
							if ( oldColZ > colZ && oldColX > colX ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 225 );
							// moved south est
							if ( oldColZ > colZ && oldColX < colX ) 
								dbYRotateObject ( baddie [ iLoop ].obj , 135 );

							while ( chCol == '1' || chCol == '2' )
							{
								dbMoveObject ( baddie [ iLoop ].obj ,-0.5f );
								chCol = szLevel[ ((int) ( ( dbObjectPositionZ ( baddie [ iLoop ].obj ) - 50 ) )>>2 )/25  + 1 ]
											   [ ((int) ( ( dbObjectPositionX ( baddie [ iLoop ].obj ) - 50 ) )>>2 )/25  + 1 ];
							}
							//odd = ( iLoop % 2 );
							//( odd == 0 ) ? dbMoveObjectRight ( baddie [ iLoop ].obj , 1.5f ) : dbMoveObjectLeft ( baddie [ iLoop ].obj , 1.5f );
							dbYRotateObject ( baddie [ iLoop ].obj , (float)curAngle );
						}						
							
						for (int crumbLoop = 0 ; crumbLoop < MAXCRUMBS ; ++crumbLoop )
						{
							if ( crumbs[crumbLoop][ 3 + iLoop ] == 0 && getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) , 0 , dbObjectPositionZ ( baddie [ iLoop ].obj ) , (float)crumbs[crumbLoop][0] , 0 , (float)crumbs[crumbLoop][1] ) < dist )
							{
								dist = getDistance ( dbCameraPositionX ( 0 ) , 0 , dbCameraPositionZ ( 0 ) , (float)crumbs[crumbLoop][0] , 0 , (float)crumbs[crumbLoop][1] );
								if ( getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) , 0 , dbObjectPositionZ ( baddie [ iLoop ].obj ) , (float)crumbs[crumbLoop][0] , 0 , (float)crumbs[crumbLoop][1] ) < 30 )
								{
									crumbs[crumbLoop][ 3 + iLoop ] = 1;
								}
								else
								{
									if ( getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
														0 ,
														dbObjectPositionZ ( baddie [ iLoop ].obj ) ,
														(float)crumbs[crumbLoop][0] ,
														0 ,
														(float)crumbs[crumbLoop][1] ) 
										<  getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
														0 ,
														dbObjectPositionZ ( baddie [ iLoop ].obj ) ,
														(float)crumbs[crumb][0] ,
														0 ,
														(float)crumbs[crumb][1] ) 
										|| crumb == 0 )
									{
										crumb = crumbLoop; // this crumb is closer to the baddie than the player
										// lets get rid of all the crumbs further away from the player than this one
										
									}
								}
							}
						}

						( crumb ) ? whichWay = turnToFace ( baddie [ iLoop ].obj , crumb+5000 ) : whichWay = turnToFace ( baddie [ iLoop ].obj , 0 );

						if (whichWay == -1 ) // turn left
						{
							/*if ( hasCol == true )*/ dbMoveObjectLeft ( baddie [ iLoop ].obj , 1.5f );
							dbYRotateObject ( baddie [ iLoop ].obj , dbObjectAngleY ( baddie [ iLoop ].obj ) - 4.0f );
						}
						else if (whichWay == 1 ) // turn right
						{
							/*if ( hasCol == true )*/ dbMoveObjectRight ( baddie [ iLoop ].obj , 1.5f );
							dbYRotateObject ( baddie [ iLoop ].obj , dbObjectAngleY ( baddie [ iLoop ].obj ) + 4.0f );
						}

						dbPositionObject ( baddie [ iLoop ].obj + 100 , dbObjectPositionX ( baddie [ iLoop ].obj ) , .1f , dbObjectPositionZ ( baddie [ iLoop ].obj ) );

						// Firing at the player if we are facing him
						//if ( baddie [ iLoop ].attack == false && whichWay == 0 )
						if (  ( baddie [ iLoop ].attack == false ) 
								&& ( ( rand() % 60 == 10 ) 
								&& baddie [ iLoop ].firing == false )  )
						{
							 	dist = getDistance ( dbObjectPositionX ( baddie [ iLoop ].obj ) ,
													0 ,
													dbObjectPositionZ ( baddie [ iLoop ].obj ) ,
													dbCameraPositionX ( 0 ) ,
													0 ,
													dbCameraPositionZ ( 0 ) );
								if ( ( baddie [ iLoop ].type == MONSTER && dist > 100 && dist < 700 ) 
									|| ( baddie [ iLoop ].type == ATrooper) )
								{
									if ( baddie [ iLoop].type == ATrooper 
										&& baddie [ iLoop ].attack == false )
									{
										dbPlayObject ( baddie [ iLoop ].obj , 150*160 , 200*160 );
										//baddie [ iLoop ].attack = true;
									}
									baddie [ iLoop ].firing = true;
									if ( fire[currentFire].on == false )
									{
										fire[currentFire].on = true;
										fire[currentFire].life = 200;
										fire[currentFire].baddie = iLoop;
										//fire[currentFire].BaddieType = baddie[iLoop].type;
										dbPositionSound ( laserSound ,
														dbObjectPositionX ( baddie [ iLoop ].obj ),
														dbObjectPositionY ( baddie [ iLoop ].obj ),
														dbObjectPositionZ ( baddie [ iLoop ].obj ) );
										dbPlaySound		( laserSound , 0 );//laser

										dbShowObject	( currentFire + 10000  );
										dbPositionObject( currentFire + 10000 ,
														dbObjectPositionX ( baddie [ iLoop ].obj ) ,
														42.5 ,
														dbObjectPositionZ ( baddie [ iLoop ].obj ) );
										dbYRotateObject	( currentFire + 10000 ,
														dbObjectAngleY ( baddie [ iLoop ].obj ) ); 
										fire[currentFire].angleY = dbObjectAngleY ( currentFire + 10000   );
										
										if ( ++currentFire == MAXFIREBALLS ) 
											currentFire = 0;
									}
								}
						}
					}
					else
					{
						if ( baddie [ iLoop ].hitCount == 5 )
						{
							dbPlayObject ( baddie [ iLoop ].obj , 370*160 , 390*160 );
							if ( baddie [ iLoop ].type == ATrooper )
								dbPlaySound ( dieSound , 0 );//die.wav
							else
								dbPlaySound ( monsterDie , 0 );//monsterLeap.wav
							
							++baddie [ iLoop ].hitCount;
						}

						if ( baddie [ iLoop ].hitCount == 6 && dbObjectPlaying ( baddie[ iLoop ].obj ) == 0 )
						{
							dbPlayObject ( baddie [ iLoop ].obj , 390*160 , 500*160 );	
							++baddie [ iLoop ].hitCount;
							if ( baddie [ iLoop ].type == MONSTER )
								dbPlaySound ( monsterRise , 0 );//monsterLand.wav
						}

						if ( dbObjectPlaying ( baddie[ iLoop ].obj ) == 0 )
						{
							baddie[ iLoop ].hit = false;
							dbPlayObject ( baddie[ iLoop ].obj , 230*160 , 235*160 );
							if ( baddie [ iLoop ].hitCount == 7 )
							{
								baddie [ iLoop ].hitCount = 0;
								if ( baddie [ iLoop ].type == MONSTER ) //monster
								{
									dbPositionSound ( roar , dbObjectPositionX( baddie [ iLoop ].obj ), dbObjectPositionY( baddie [ iLoop ].obj ), dbObjectPositionZ( baddie [ iLoop ].obj ) );
									dbPlaySound ( roar , 0 );//roar
								}
								else
								{
									dbPositionSound ( ATsound , dbObjectPositionX( baddie [ iLoop ].obj ), dbObjectPositionY( baddie [ iLoop ].obj ), dbObjectPositionZ( baddie [ iLoop ].obj ) );
									dbPlaySound ( ATsound , 0 );//attacking enemies.wav
								}
					
								dbLoopObject ( baddie[ iLoop ].obj , 91200 , 100800 );
							}
						}


					}

				}
			}
		}
	}

}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int turnToFace( int source, int target )
{
	// source: object that we want to turn too 
	// target: camera or object to point too ( 0 = camera )

	// Returned values:
	//   0  : no turn needed
	//   -1  : turn left
	//   1 : turn right

	float	fOrignalAngleY = dbObjectAngleY ( source ); // store the original yaw of the target
	int		s;
	int		t;
	int		sum;

	// turn to face the target pivot
	if ( target == 0 ) // if 0 then it is the camera we are pointing too
	{
		dbPointObject ( source , dbCameraPositionX ( 0 ) , 0 , dbCameraPositionZ ( 0 ) );
		/*This command will point the specified 3D object towards a point in 3D space. The command 
		sets the current direction of the object to face towards this point in space.*/
	}
	else
	{
		dbPointObject ( source , dbObjectPositionX ( target ) , 0 , dbObjectPositionZ ( target ) );		
	}
	
	// start angle and end angle
	s = (int) dbWrapValue( fOrignalAngleY );
	t = (int) dbWrapValue( dbObjectAngleY ( source ) );

	// Put original Y rotation back
	dbYRotateObject ( source , fOrignalAngleY );
	
	sum = abs( s - t );
		
	if ( sum <= 4 ) return 0; // If the two angles are close we don't need any rotation !

	// the angle goes from 0,180 and 0,-180; now I normalize to 0-360
	//if ( s < 0 ) s = 360 + s;
	//if ( t < 0 ) t = 360 + t;

	// now we found the right direction where to turn, in order to choose the shortest path:

	// check if the difference is greather than 180
	if ( abs ( s - t ) > 180 )
	{
		// check if the start angle is greater than the target angle
		if ( s > t )
		{
			return 1; // turn left
		}
		else
		{
			return -1; //turn right
		}
	}
	else
	{
		// check if the start angle is greater than the target angle
		if ( s > t )
		{
			return -1; //turn right
		}
		else
		{
			return  1; //turn left
		}
		
	}

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline float getDistance ( float x1 , float y1 , float z1 , float x2 , float y2 , float z2)
{
	float dist;
	float dx;
	float dy;
	float dz;

	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;

	dist = sqrt ( ( dx * dx ) + ( dy * dy ) + ( dz * dz ) );

	return dist;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void addFloor ( int& objectCount, int charNum , int stringNum  )
{
	// Add the ceiling
	dbMakeObjectPlane		( objectCount , 100, 100 );
	dbXRotateObject			( objectCount , 90 );
	//dbLoadObject			( "scenery\\ceilings\\floor_a.x", objectCount );
	dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 200 ,  (float)(( stringNum <<2 ) * 25) );
	dbTextureObject			( objectCount , ceiling );
	dbSetObjectCollisionOff ( objectCount );
	++objectCount;
	
	// Now the floor
	dbMakeObjectPlane		( objectCount , 100, 100 );
	dbXRotateObject			( objectCount , -90 );
	dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 0 ,  (float)(( stringNum <<2 ) * 25) );
	dbTextureObject			( objectCount , floorTexture );
	dbScaleObjectTexture	( objectCount , 2 , 2 );
	dbSetObjectCollisionOff ( objectCount );
			
	++objectCount;
	
}
void CreateLevel( )
{
	int		objectCount = 300;
	int		charNum		= 0;
	int		stringNum	= 0;
	int		lightNum	= 1; // can have 6 lights max in the level R, G or B
	int		n			= 0;
	
	//ifstream fin("levels\\level1.txt");
	//fin>>n;
	FILE* fin=fopen ( "level1.txt", "r");
	if ( fin != NULL )
	{
		fscanf ( fin,"%d ",&n);
		for(int i=0;i!=n;++i)
		{
			//getline ( fin , szLevel[i] );
			fgets ( szLevel[i], 2048, fin );
		}
		fclose ( fin );
	}
	
	
	//szLevel.resize( n );
	
	//szLevel = new char* [ 50 ];
	
	
	for ( stringNum = 0 ; stringNum < n ; ++stringNum )
	{
		//int begin	=	szLevel.find_first_not_of(' ');
		//int end	=	szLevel.find_first_of(' ');
		int end		=	( int ) strlen(szLevel[ stringNum ]);
		for ( charNum = 0 ; charNum < end ; ++charNum )
		{
			switch ( szLevel[ stringNum ][ charNum ] )
			{
			case '{':
				{
					vis[visCount].start		= stringNum;
					vis[visCount].startObj	= objectCount;
				} break;
			case '}':
				{
					vis[visCount].end		= stringNum;
					vis[visCount].endObj	= objectCount - 1;
					++visCount;
				} break;
			case ':': // empty space
				{
					addFloor(objectCount, charNum, stringNum);
				} break;

			/*case '+': // empty space with crumbs ( firimituri )
				{
					addFloor(objectCount, charNum, stringNum);
				} break;
			*/
			case 's': // south facing door empty space
				{
					dbLoadObject			( "scenery\\door_frame1.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbScaleObject			( objectCount , 180 , 160 , 130 );
					dbMoveObject			( objectCount ,  -10 );
					dbFadeObject			( objectCount , 200 );
					dbSetObjectCollisionToPolygons	( objectCount );

					door[ doorCount ].type			= 0; // south
					door[ doorCount ].distObj		= ( objectCount );

					++objectCount;

					dbLoadObject			( "scenery\\door_1a.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbScaleObject			( objectCount , 100 , 110 , 100 );
					dbMoveObject			( objectCount ,  5 );
					dbSetObjectCollisionOff	( objectCount );

					door[ doorCount ].leftObj		= ( objectCount );
					door[ doorCount ].leftStartX	= dbObjectPositionX ( objectCount );
					door[ doorCount ].leftCurrentX	= dbObjectPositionX ( objectCount );

					++objectCount;

					dbLoadObject			( "scenery\\door_1b.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbScaleObject			( objectCount , 100 , 110 , 100 );
					dbMoveObject			( objectCount ,  5 );
					dbSetObjectCollisionOff	( objectCount );

					door[ doorCount ].rightObj		= ( objectCount );
					door[ doorCount ].rightStartX	= dbObjectPositionX ( objectCount );
					door[ doorCount ].rightCurrentX = dbObjectPositionX ( objectCount );

					++objectCount;

					++doorCount;

					addFloor(objectCount, charNum, stringNum);
				} break;

			case 'n': // north facing door empty space
				{
					dbLoadObject			( "scenery\\door_frame1.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateObject			( objectCount , 180 );
					dbScaleObject			( objectCount , 180 , 160 , 130 );
					dbMoveObject			( objectCount ,  -10 );
					dbFadeObject			( objectCount , 200 );
					dbSetObjectCollisionToPolygons	( objectCount );

					door[ doorCount ].type			= 1; // north
					door[ doorCount ].distObj		= ( objectCount );

					++objectCount;

					dbLoadObject			( "scenery\\door_1a.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateObject			( objectCount , 180 );
					dbScaleObject			( objectCount , 100 , 110 , 100 );
					dbMoveObject			( objectCount ,  5 );
					dbSetObjectCollisionOff	( objectCount );

					door[ doorCount ].leftObj		= ( objectCount );
					door[ doorCount ].leftStartX	= dbObjectPositionX ( objectCount );
					door[ doorCount ].leftCurrentX	= dbObjectPositionX ( objectCount );

					++objectCount;

					dbLoadObject			( "scenery\\door_1b.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateObject			( objectCount , 180 );
					dbScaleObject			( objectCount , 100 , 110 , 100 );
					dbMoveObject			( objectCount ,  5 );
					dbSetObjectCollisionOff	( objectCount );

					door[ doorCount ].rightObj		= ( objectCount );
					door[ doorCount ].rightStartX	= dbObjectPositionX ( objectCount );
					door[ doorCount ].rightCurrentX = dbObjectPositionX ( objectCount );

					++objectCount;

					++doorCount;

					addFloor(objectCount, charNum, stringNum);
				} break;

			case '~': // north facing door empty space 
				{
					dbLoadObject			( "scenery\\door_frame1.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateObject			( objectCount , 180 );
					dbScaleObject			( objectCount , 180 , 160 , 130 );
					dbMoveObject			( objectCount ,  -10 );
					dbFadeObject			( objectCount , 200 );
					dbSetObjectCollisionToPolygons	( objectCount );

					door[ doorCount ].type			= 1; // north
					door[ doorCount ].distObj		= ( objectCount );

					++objectCount;

					dbLoadObject			( "scenery\\door_1a.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateObject			( objectCount , 180 );
					dbScaleObject			( objectCount , 100 , 110 , 100 );
					dbMoveObject			( objectCount ,  5 );
					dbSetObjectCollisionOff	( objectCount );

					door[ doorCount ].leftObj		= ( objectCount );
					door[ doorCount ].leftStartX	= dbObjectPositionX ( objectCount );
					door[ doorCount ].leftCurrentX	= dbObjectPositionX ( objectCount );

					++objectCount;

					dbLoadObject			( "scenery\\door_1b.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateObject			( objectCount , 180 );
					dbScaleObject			( objectCount , 100 , 110 , 100 );
					dbMoveObject			( objectCount ,  5 );
					dbSetObjectCollisionOff	( objectCount );

					door[ doorCount ].rightObj		= ( objectCount );
					door[ doorCount ].rightStartX	= dbObjectPositionX ( objectCount );
					door[ doorCount ].rightCurrentX = dbObjectPositionX ( objectCount );

					++objectCount;

					++doorCount;

					addFloor(objectCount, charNum, stringNum);
				} break;

			case '^': // empty space + item
				{
					dbLoadObject			( "items\\Energy-Box.X" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 25 ,  (float)(( stringNum <<2 ) * 25)-50 );
					dbScaleObject			( objectCount , 400 , 400 , 400 );
					dbSetObjectAmbient		( objectCount , 0 );
					dbSetObjectAmbience		( objectCount , 0x00000000 );
					dbSetObjectSpecular		( objectCount , 0x00111111 );
					++objectCount;
					
					//dbSetObjectAmbient		( objectCount , 0 );
					//dbSetObjectAmbience		( objectCount , 0x00000000 );
					//dbSetObjectSpecular		( objectCount , 0x00111111 );
					++objectCount;
					addFloor(objectCount, charNum, stringNum);
				} break;

			case '$': // Player start plus empty space
				{
					dbPositionCamera ( 0 ,  (float)(( charNum <<2 ) * 25) , 40.0f ,  (float)(( stringNum <<2 ) * 25) );
					dbYRotateCamera ( 90 );
					/*
					dbLoadObject ( "scenery\\walls\\walltop3.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 150 ,  (float)(( stringNum <<2 ) * 25) );
					dbTextureObject			( objectCount , 6 );
					dbSetObjectCollisionOff ( objectCount );
					//dbScaleObjectTexture	( objectCount , 2 , 2 );
					//dbSetBumpMappingOn		( objectCount , 5 );
					++objectCount;
					*/
					addFloor(objectCount, charNum, stringNum);
				} break;

			case '@': // Add Monster Baddie start plus empty space
				{
					++iNumBaddies;
					dbLoadObject			("entity\\Bezerker.X" , baddieCount + 100 );
					dbTextureObject			( baddieCount + 100 , 2 );
					dbRotateObject			( baddieCount + 100 , -90 , 0 , 0 );
					dbFixObjectPivot		( baddieCount + 100 );
					dbSetObjectSpeed		( baddieCount + 100 , 20000 );
					dbPositionObject		( baddieCount + 100 ,  (float)(( charNum <<2 ) * 25) , 0.0f ,  (float)(( stringNum <<2 ) * 25) );
					//dbSetObjectCollisionToBoxes ( baddieCount + 100 );
					//dbScaleObject			( baddieCount + 100 , 100.0f , 60.0f , 120.0f );
					dbSetObjectCollisionToPolygons ( baddieCount + 100 );
					//dbAutomaticObjectCollision ( baddieCount + 100 , 10 , 1 );
					//dbShowObjectBounds	( baddieCount + 100 , 0 );

					baddie[ baddieCount ].obj = baddieCount + 100;
					baddie[ baddieCount ].life = 3;
					baddie[ baddieCount ].mode = 0;
					baddie[ baddieCount ].type = MONSTER;
					baddie[ baddieCount ].firing = false;

					dbMakeObjectPlane		( baddieCount + 200 , 40 , 40 );
					dbXRotateObject			( baddieCount + 200 , -90 );
					dbTextureObject			( baddieCount + 200 , 3 );
					dbSetObjectTransparency ( baddieCount + 200 , 1 );
					dbPositionObject		( baddieCount + 200 ,  (float)(( charNum <<2 ) * 25) , 0.1f ,  (float)(( stringNum <<2 ) * 25) );
					dbSetObjectCollisionOff	( baddieCount + 200 );
					
					++baddieCount;

					addFloor(objectCount, charNum, stringNum);
				} break;

			case '*': // Add Assault Trooper Baddie start plus empty space
				{
					++iNumBaddies;
					dbLoadObject			("entity\\Assault Trooper.X" , baddieCount + 100 );
					//dbMakeObjectCube ( baddieCount + 100 , 50 );
					//dbTextureObject			( baddieCount + 100 , ATtexture );
					dbRotateObject			( baddieCount + 100 , -90 , 0 , 0 );
					dbFixObjectPivot		( baddieCount + 100 );
					dbSetObjectSpeed		( baddieCount + 100 , 20000 );
					dbScaleObject			( baddieCount + 100 , 90.0f , 90.0f , 90.0f );
					dbPositionObject		( baddieCount + 100 ,  (float)(( charNum <<2 ) * 25) , 0.0f ,  (float)(( stringNum <<2 ) * 25) );
					//dbSetObjectCollisionToBoxes ( baddieCount + 100 );
					dbSetObjectCollisionToPolygons ( baddieCount + 100 );
					//dbAutomaticObjectCollision ( baddieCount + 100 , 10 , 0 );
					//dbShowObjectBounds	( baddieCount + 100 , 0 );


					dbSetObjectAmbient		( baddieCount + 100, 0 );
					dbSetObjectAmbience		( baddieCount + 100, 0x00000000 );
					dbSetObjectSpecular		( baddieCount + 100, 0x00111111 );

					baddie[ baddieCount ].obj = baddieCount + 100;
					baddie[ baddieCount ].life = 3;
					baddie[ baddieCount ].mode = 0;
					baddie[ baddieCount ].type = ATrooper;
					baddie[ baddieCount ].firing = false;

					dbMakeObjectPlane		( baddieCount + 200 , 40 , 40 );
					dbXRotateObject			( baddieCount + 200 , -90 );
					dbTextureObject			( baddieCount + 200 , 3 );
					dbSetObjectTransparency ( baddieCount + 200 , 1 );
					dbPositionObject		( baddieCount + 200 ,  (float)(( charNum <<2 ) * 25) , 0.1f ,  (float)(( stringNum <<2 ) * 25) );
					dbSetObjectCollisionOff	( baddieCount + 200 );
					
					++baddieCount;

					addFloor(objectCount, charNum, stringNum);
				} break;


			case 'r': // red light
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight	( lightNum , 0x00AA8888 );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				} break;

			case 'g': // green light 
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight	( lightNum , 0x0088AA88 );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				} break;

			case 'b': // blue light 
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight	( lightNum , 0x008888AA );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				} break;
			case 'D': // dark
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight ( lightNum, -300, -300, -300 );
					dbSetLightRange	( lightNum , 30 );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				}break;
			case 'B': // BLUE light plus empty space
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight	( lightNum , 0x006666CC );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				} break;
			case 'G': // GREEN light
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight	( lightNum , 0x0022EE33 );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				} break;
			case 'R': // RED light
				{
					dbMakeLight		( lightNum );
					dbSetPointLight ( lightNum ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					dbColorLight	( lightNum , 0x00FF0000 );
					dbSetLightRange	( lightNum , 700 );
					++lightNum;
					addFloor(objectCount, charNum, stringNum);
				} break;


			case '1':	// Wall block
				{
					dbMakeObjectBox			( objectCount , 100, 100 , 100 );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbTextureObject			( objectCount , wallTexture );
					
					
					dbSetObjectCollisionOn	( objectCount );
					dbSetObjectCollisionToBoxes ( objectCount);
					++objectCount;

					dbLoadObject ( "scenery\\walls\\walltop.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 150 ,  (float)(( stringNum <<2 ) * 25) );
					dbTextureObject			( objectCount , wallTop );
					++objectCount;
		
				} break;

			case '2':	// Wall block
				{
					dbMakeObjectBox			( objectCount , 100, 100 , 100 );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 50 ,  (float)(( stringNum <<2 ) * 25) );
					dbTextureObject			( objectCount , wallTexture );
					
					
					dbSetObjectCollisionOn ( objectCount );
					dbSetObjectCollisionToBoxes ( objectCount);
					
					++objectCount;
					dbLoadObject ( "scenery\\walls\\walltop2.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 150 ,  (float)(( stringNum <<2 ) * 25) );
					dbTextureObject			( objectCount , wallTop );
					++objectCount;
			
				} break;

			case 'o':	// Pillars
				{
					dbMakeObjectCylinder	( objectCount , 100 );
					dbScaleObject			( objectCount , 50 , 200 , 50 );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 100 ,  (float)(( stringNum <<2 ) * 25) );
					
					dbTextureObject			( objectCount , pillar );
					dbScaleObjectTexture	( objectCount , 2 , 4 );
					#ifdef SHADERS
						dbSetBumpMappingOn		( objectCount , pillarBump );
					#endif
					++objectCount;
					
					addFloor(objectCount, charNum, stringNum);
					
				} break;

			case '#':	// Doorway
				{
					//dbMakeObjectBox			( objectCount , 100, 100 , 100 );
					dbLoadObject ( "scenery\\walls\\walltop3.x" , objectCount );
					dbPositionObject		( objectCount ,  (float)(( charNum <<2 ) * 25) , 150 ,  (float)(( stringNum <<2 ) * 25) );
					dbTextureObject			( objectCount , corridor );
					dbSetObjectCollisionOff ( objectCount );
					//dbScaleObjectTexture	( objectCount , 2 , 2 );
					//dbSetBumpMappingOn		( objectCount , 5 );
					++objectCount;
					addFloor(objectCount, charNum, stringNum);
				} break;

			case 'x':	// Centre Point
				{
					addFloor(objectCount, charNum, stringNum);
				} break;

			}
			
		}
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void updateDoors()
{
	float	dist;
	bool	open = false;

	for ( int iLoop = 0 ; iLoop < doorCount ; ++iLoop )
	{
		open = false;

		// first check if the player is near the door
		if (door[ iLoop ].type == south )
		{
			dist = getDistance ( dbCameraPositionX ( 0 ) ,
									0 ,
									dbCameraPositionZ ( 0 ) ,
									dbObjectPositionX ( door[ iLoop ].distObj ) ,
									0 ,
									dbObjectPositionZ ( door[ iLoop ].distObj ) + 50 );
		}
		else
		{
			dist = getDistance ( dbCameraPositionX ( 0 ) ,
								0 ,
								dbCameraPositionZ ( 0 ) ,
								dbObjectPositionX ( door[ iLoop ].distObj ) ,
								0 ,
								dbObjectPositionZ ( door[ iLoop ].distObj ) - 50 );
		}

		if ( dist < 150.0f )
		{
			open = true;
		}
		
		// now check if a baddie is near the door
		for (int iLoop2 = 0 ; iLoop2 < baddieCount ; ++iLoop2 )
		{
			if ( door [ iLoop ].type == south )
			{
				dist = getDistance ( dbObjectPositionX ( baddie [ iLoop2 ].obj ) ,
								0 , 
								dbObjectPositionZ ( baddie [ iLoop2 ].obj ) ,
								dbObjectPositionX ( door[ iLoop ].distObj ) ,
								0 ,
								dbObjectPositionZ ( door[ iLoop ].distObj )+ 50 );
			}
			else
			{
				dist = getDistance ( dbObjectPositionX ( baddie [ iLoop2 ].obj ) ,
								0 ,
								dbObjectPositionZ ( baddie [ iLoop2 ].obj ) ,
								dbObjectPositionX ( door[ iLoop ].distObj ) ,
								0 ,
								dbObjectPositionZ ( door[ iLoop ].distObj ) - 50 );
			}
			if ( dist < 150.0f ) 
			{
				if (dist < 50.0f && baddie [ iLoop2 ].life <= 0 )
					open = false;
				else
					open = true;
			}
		}
		
		if ( open == true )
		{
			if ( dbObjectPositionX ( door[ iLoop ].leftObj ) == door[ iLoop ].leftStartX )
			{
				bDoorSound = !bDoorSound;
				if ( bDoorSound )
				{
					dbStopSound ( doorOpen1 );
					dbPlaySound ( doorOpen1 , 0 );
				}
				else
				{
					dbStopSound ( doorOpen2 );
					dbPlaySound ( doorOpen2 , 0 );
				}
			}
			dbMoveObjectLeft	( door[ iLoop ].leftObj , 4 );
			dbMoveObjectRight	( door[ iLoop ].rightObj , 4 );

			if ( door[ iLoop ].type == south )
			{
				if ( dbObjectPositionX ( door[ iLoop ].leftObj ) < door[ iLoop ].leftStartX - 100.0f )
				{
					dbPositionObject ( door[ iLoop ].leftObj ,
						door[ iLoop ].leftStartX - 100.0f ,
						dbObjectPositionY ( door[ iLoop ].leftObj )  ,
						dbObjectPositionZ ( door[ iLoop ].leftObj ) );
					dbPositionObject ( door[ iLoop ].rightObj ,
						door[ iLoop ].rightStartX + 100.0f ,
						dbObjectPositionY ( door[ iLoop ].leftObj ) ,
						dbObjectPositionZ ( door[ iLoop ].rightObj ) );
				}
			}
			else
			{
				if ( dbObjectPositionX ( door[ iLoop ].leftObj ) > door[ iLoop ].leftStartX + 100.0f )
				{
					dbPositionObject ( door[ iLoop ].leftObj ,
						door[ iLoop ].leftStartX + 100.0f ,
						dbObjectPositionY ( door[ iLoop ].leftObj ) ,
						dbObjectPositionZ ( door[ iLoop ].leftObj ) );
					dbPositionObject ( door[ iLoop ].rightObj ,
						door[ iLoop ].rightStartX - 100.0f ,
						dbObjectPositionY ( door[ iLoop ].leftObj ) ,
						dbObjectPositionZ ( door[ iLoop ].rightObj ) );
				}
			}

		}
		else
		{
			if ( dbObjectPositionX ( door[ iLoop ].leftObj ) != door[ iLoop ].leftStartX )
			{	
				if ( door[ iLoop ].type == south )
				{
					if ( dbObjectPositionX ( door[ iLoop ].leftObj ) == door[ iLoop ].leftStartX - 100.0f )
					{
						bDoorClose = !bDoorClose;
						if ( bDoorClose )
						{
							dbStopSound ( doorClose1 );
							dbPlaySound ( doorClose1 , 0 );
						}
						else
						{
							dbStopSound ( doorClose2 );
							dbPlaySound ( doorClose2 , 0 );
						}
					}
				}
				else
				{
					if ( dbObjectPositionX ( door[ iLoop ].leftObj ) == door[ iLoop ].leftStartX + 100.0f )
					{
						bDoorClose = !bDoorClose;
						if ( bDoorClose )
						{
							dbStopSound ( doorClose1 );
							dbPlaySound ( doorClose1 , 0 );
						}
						else
						{
							dbStopSound ( doorClose2 );
							dbPlaySound ( doorClose2 , 0 );
						}
					}
				}
					
			
				dbMoveObjectRight	( door[ iLoop ].leftObj , 4 );
				dbMoveObjectLeft	( door[ iLoop ].rightObj , 4 );
				
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void updateVis()
{
	int colZ	= (((int) ( ( dbCameraPositionZ ( 0 ) - 50 ) ))>>2) /25  + 1;
	int	oldVis	= currentVis;
	int iLoop;
	int	visLoop;
	int	baddieLoop;
	int baddieVis;

	for ( iLoop = 0 ; iLoop < visCount ; iLoop++ )
	{
		if ( colZ >= vis[iLoop].start && colZ <= vis[iLoop].end )
		{
			currentVis = iLoop;
		}
	}

	// Are we in a different vis area?
	if ( currentVis != oldVis )
	{

		// First lets move the new blocks down (if needed)
		for ( iLoop = currentVis -1 ; iLoop < currentVis + 2 ; iLoop++ )
		{
			// does the area need moving down?
			if (iLoop > -1 && iLoop < visCount )
			{
				if ( dbObjectPositionY ( vis[iLoop].startObj ) > 49000 )
				{
					for ( visLoop = vis[iLoop].startObj ; visLoop < vis[iLoop].endObj + 1 ; visLoop++ )
					{
						dbMoveObjectDown ( visLoop , 50000 );	
						//dbExcludeOff ( visLoop );
					}
				}
			}
		}

		// Now lets move the other blocks up (if needed)
		for ( iLoop = 0 ; iLoop < visCount ; iLoop++ )
		{
			if ( iLoop < currentVis -1 || iLoop > currentVis +1 ) // dont move the current vis up
			{
				// does the area need moving up?
				if ( dbObjectPositionY ( vis[iLoop].startObj ) < 49000 )
				{
					for ( visLoop = vis[iLoop].startObj ; visLoop < vis[iLoop].endObj + 1 ; visLoop++ )
					{
						dbMoveObjectUp ( visLoop , 50000 );	
						//dbExcludeOn ( visLoop );
					}
				}
			}
		}

	}



	// Now lets check the baddies
	for ( baddieLoop = 0 ; baddieLoop < baddieCount ; baddieLoop++ )
	{
		colZ = (int) ( ( dbObjectPositionZ ( baddie[baddieLoop].obj ) - 50 ) / 100.0f ) + 1;

		for ( iLoop = 0 ; iLoop < visCount ; iLoop++ )
		{
			if ( colZ >= vis[iLoop].start && colZ <= vis[iLoop].end )
			{
				baddieVis = iLoop;
			}
		}

		if ( baddieVis > currentVis + 1 || baddieVis < currentVis -1 )
		{
			dbStopObject ( baddie[baddieLoop].obj );
			dbPositionObject ( baddie[baddieLoop].obj , dbObjectPositionX ( baddie[baddieLoop].obj ) , 50000 , dbObjectPositionZ ( baddie[baddieLoop].obj ) );
			dbPositionObject ( baddie[baddieLoop].obj + 100 , dbObjectPositionX ( baddie[baddieLoop].obj ) , 50000 , dbObjectPositionZ ( baddie[baddieLoop].obj ) );
		}
		else
		{
			dbPositionObject ( baddie[baddieLoop].obj , dbObjectPositionX ( baddie[baddieLoop].obj ) , 0 , dbObjectPositionZ ( baddie[baddieLoop].obj ) );
			dbPositionObject ( baddie[baddieLoop].obj , dbObjectPositionX ( baddie[baddieLoop].obj ) , 0.1f , dbObjectPositionZ ( baddie[baddieLoop].obj ) );
		}
	}


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Move all blocks up 50000
void setupVis()
{
	int iLoop;
	int visLoop;

	for ( iLoop = 0 ; iLoop < visCount ; iLoop++ )
	{
		for ( visLoop = vis[iLoop].startObj ; visLoop < vis[iLoop].endObj + 1 ; visLoop++ )
		{
			dbMoveObjectUp ( visLoop , 50000 );
			//dbExcludeOn ( visLoop );
		}
	}

	currentVis = -1; //to force the vis to update first frame

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void HUD ( )
{
	
	char	czText[4];
	char	czText2[4];
	//char	czFPS[10];

	////////////////////////////////////////////////////////////////////////
	//dbPasteSprite ( LIVES, 31,34 );
	//dbPasteSprite ( HEALTH, 137,34 );
	
	
	dbPasteImage ( LIVES, livesX , livesY , 1);
	dbPasteImage ( HEALTH,healthX, healthY , 1);
	////////////////////////////////////////////////////////////////////////

	//wsprintf ( czFPS , "%d" , dbScreenFPS ( ) );
	//dbText ( dbScreenWidth ( ) - 10 - dbTextWidth ( czFPS ), dbScreenHeight ( ) - 25, czFPS );
	
	////////////////////////////////////////////////////////////////////////
	
	dbSetTextFont ("Arial Black" );
	dbSetTextSize ( 20 );
	
	dbInk ( 0,0 );
	
	dbCenterText ( copyrX - 1, copyrY - 1 , "(C) COPYRIGHT ION LAURENTIU, CNICB PITESTI" );
	dbCenterText ( copyrX - 1, copyrY + 1, "(C) COPYRIGHT ION LAURENTIU, CNICB PITESTI" );
	dbCenterText ( copyrX + 1, copyrY - 1, "(C) COPYRIGHT ION LAURENTIU, CNICB PITESTI" );
	dbCenterText ( copyrX + 1, copyrY + 1, "(C) COPYRIGHT ION LAURENTIU, CNICB PITESTI" );
	dbInk ( dbRgb ( 255,255,255 ),0 );
	dbCenterText ( copyrX , copyrY , "(C) COPYRIGHT ION LAURENTIU, CNICB PITESTI" );
	
	////////////////////////////////////////////////////////////////////////
	dbSetTextSize ( 25 );
	dbSetTextFont ( "Arial" );
	//dbSetTextFont ( "Copperplate Gothic Bold" );
	
	dbInk ( dbRgb ( 163,130,23 ),0 );
	
	
	wsprintf ( czText2 , "%d" , iLives );
	dbCenterText ( LivesX , LivesY , czText2 );
	
	wsprintf ( czText , "%d" , iHealth );
	dbCenterText ( HealthX , HealthY , czText );
	//wsprintf ( czText , "X %f Y %f Z %f AX %f AY%f" ,GunX,GunY,GunZ,GunAngleX,GunAngleY  );
	//dbText ( 169 , 58 , czText );
	
	
	dbText (  ammoX, ammoY, "24/72" );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


inline void updateFire()
{
	int		iLoop;
	char	chCol;

	for ( iLoop = 0 ; iLoop < MAXFIREBALLS ; iLoop++ )
	{
		if ( fire[iLoop].on == true )
		{
			chCol = szLevel [( ((int) ( ( dbObjectPositionZ ( iLoop + 10000 ) - 50 ) ) )>>2 )/25 + 1 ]
							[( ((int) ( ( dbObjectPositionX ( iLoop + 10000 ) - 50 ) ) )>>2 )/25 + 1 ];
			
			if ( chCol == '1' 
				|| chCol == '2' 
				|| chCol == 'o' 
				|| chCol == '~' 
				|| chCol == 'n' 
				|| chCol == 's') fire[iLoop].life = 0;

			dbShowObject ( iLoop + 10000  );
			dbRotateObject					( iLoop + 10000  ,
												0 ,
												fire[iLoop].angleY ,
												0 );
			dbMoveObject					( iLoop + 10000  , 30.0f*30.0f/((fps>10)?fps:10 ) );
			dbSetObjectToCameraOrientation	( iLoop + 10000  );

			chCol = szLevel [( ((int) ( ( dbObjectPositionZ ( iLoop + 10000 ) - 50 ) ) )>>2 )/25 + 1 ]
							[( ((int) ( ( dbObjectPositionX ( iLoop + 10000 ) - 50 ) ) )>>2 )/25 + 1 ];
			
			if ( chCol == '1' 
				|| chCol == '2' 
				|| chCol == 'o' 
				|| chCol == '~' 
				|| chCol == 'n' 
				|| chCol == 's') fire[iLoop].life = 0;
			
			// have we hit the player?
			if ( getDistance ( dbCameraPositionX ( 0 ) ,
								0 ,
								dbCameraPositionZ ( 0 ) ,
								dbObjectPositionX ( iLoop + 10000  ) ,
								0 ,
								dbObjectPositionZ ( iLoop + 10000  ) ) < 30
				&& fire [ iLoop ].on
				)
			{
				playerHurt();
			}

			// Has the life of the fireball run out? if so shift it out of the view fustrum
			if ( --fire[iLoop].life <= 0 )
			{
				fire[iLoop].on						= false;
				baddie[fire[iLoop].baddie].firing	= false;
				dbHideObject ( iLoop + 10000  );
				/*dbPositionObject					( iLoop + 10000  ,
														0 ,
														50000 ,
														0 );
				*/
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void playerHurt()
{
	static int timer = 5;
	if ( iHealth && iHealth < 2 )
	{
		//-----------------------
		//a) with fog: +see lines 600-612 -end of updatePlayer()
		//Control hurt fog (from iced)
		//hurt=100.0f;

		//b) with Box:
		//dbBox ( 0 , 0 , dbScreenWidth() , dbScreenHeight() , 0x00FF0000 , 0x00FF0000 , 0x00FF0000 , 0x00FF0000 );
		/*This command will draw a filled box on screen in the current ink color. The command requires the
		top	left and bottom right coordinates of the box. You can also draw to a bitmap, by using the 
		dbSetCurrentBitmap command. */
		
		//dbInk(dbRgb(255,0,0),0 );
		
		
		//-----------------------
		if ( --timer == 0 )
		{
			//dbBox(0,0,dbScreenWidth(),dbScreenHeight(), dbRgb(16,0,0), dbRgb(64,10,10), dbRgb(64,10,10), dbRgb(16,0,0) ); 
			dbPasteImage ( damageBox , 0 ,0,1 );
			
			timer=2;
			dbPlaySound ( hurt1 );
		}
		iHealth-=2;
	}
	else if ( iHealth > 1 )
	{
		if ( --timer == 0 )
		{
			dbBox(0,0,dbScreenWidth(),dbScreenHeight(), dbRgb(16,0,0), dbRgb(64,0,0), dbRgb(64,0,0), dbRgb(16,0,0) ); 
			//dbPasteImage ( damageBox , 0 ,0,1 );
			timer=2;
			dbPlaySound ( hurt1 );
		}
		iHealth-=2;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void die( )
{
	if ( !bGameover )
	{
		dbSetObjectCollisionOn ( gunObj );
		dbEnableObjectZDepth ( gunObj );
		bGameover = true;
		dbPlaySound ( finalmoan );
		dbAutomaticObjectCollision ( gunObj , 4 , 1 );
	}
	
	if ( dbCameraPositionY ( 0 ) > 5.0f )
	{
		dbPositionCamera ( 0 , dbCameraPositionX ( 0 ) , dbCameraPositionY ( 0 ) - 0.4f , dbCameraPositionZ ( 0 ) );
		dbZRotateCamera ( 0 , dbCameraAngleZ ( 0 ) - 1 );
	}
	if ( dbObjectPositionY ( gunObj ) >=1.0f )
	{
		dbMoveObjectDown ( gunObj , .5 );
		dbMoveObjectLeft ( gunObj , 1.5 );
		dbZRotateObject ( gunObj , dbObjectAngleZ ( gunObj ) + 5 );
		
	}
	else if ( dbObjectPositionY ( gunObj ) >= 0.5f )
	{
		dbMoveObjectDown ( gunObj , .5 );
		dbMoveObjectLeft ( gunObj , 1.5 );
		dbRotateObject   ( gunObj , 0 , 0 , 90 ); 
	}
	else //if ( dbObjectPositionY ( gunObj ) >= 0.1f )
	{
		dbRotateObject   ( gunObj , 0 , 0 , 90 );
	}
	static int d = dbTimer() + 1200;
	if ( d == dbTimer() )
	{
		dbHideObject ( gunObj );
	}
	
	if ( ++isDying == 150 )
	{
		if ( dbImageExist ( 1 ) )
		{
			dbDeleteImage ( 1 );
			dbLoadImage ( "images\\gameover.jpg" , 1 , 1 );
		}
	}
	if ( isDying > 150 )
	{
		dbPasteImage ( 1 , 0 , 0 );
		isDying = 151;
	}
}
void GameEnd ( void )
{
	for ( int iLoop = 0; iLoop< 1100; ++iLoop )
	{
		if ( dbObjectExist ( iLoop ) )
			dbDeleteObject ( iLoop );
	}
	for ( int iLoop = 10000; iLoop< 11000; ++iLoop )
	{
		if ( dbObjectExist ( iLoop ) )
			dbDeleteObject ( iLoop );
	}
	for ( int iLoop = 50000; iLoop< 50100; ++iLoop )
	{
		if ( dbObjectExist ( iLoop ) )
			dbDeleteObject ( iLoop );
	}
	for ( int iLoop = 0; iLoop <= iSoundCount; ++iLoop )
	{
		if ( dbSoundExist ( iLoop ) )
			dbDeleteSound ( iLoop );
	}
	for ( int iLoop = 0; iLoop <= iImageCount; ++iLoop )
	{
		if ( dbImageExist ( iLoop ) )
			dbDeleteImage ( iLoop );
	}
	if ( dbMusicExist ( 1 ) )
		dbDeleteMusic ( 1 );		
}
