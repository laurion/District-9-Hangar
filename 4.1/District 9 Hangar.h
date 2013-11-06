/////////////////////////////////////////////////////////////////////////////
//	Project		:	D9
//	File		:	District 9 Hangar_The Entrance.h
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//	Includes	:
/////////////////////////////////////////////////////////////////////////////
#include "InitGraphics.h"
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include "SC_Collision.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
//#include <sstream>

/*
int NextImageValidID(){
	static int NextImageID = 0;
	return NextImageID++;
}
int NextSoundValidID(){
	static int NextSoundID = 0;
	return NextSoundID++;
}
int NextMusicValidID(){
	static int NextMusicID = 0;
	return NextMusicID++;
}
int NextObjectValidID(){
	static int NextObjectID = 0;
	return NextObjectID++;
}
int NextBitmapValidID(){
	static int NextBitmapID = 0;
	return NextBitmapID++;
}
enum {	wall=1,
		floor,
		ceiling,
		gunTexture,
};
*/


typedef struct tPlayer//class
{

} tPlayer;


typedef struct tBaddie//class
{

	int		type;		// type of baddie, 0 = monster
	int		mode;		// 0 = idle, 1 = seeking, 2 = hit, 99 = dead
	int		obj;			// which object number the baddie occupies
	int		life;		// how much damage left before perishing
	bool	hit;		// has been hit - do anim
	int		fallAmount; // how many points of damage before falling over
	int		hitCount;	// count of hits taken, when it reaches fallAmount the baddie will keel over
	bool	attack;
	bool	firing;		// is this baddie currently firing?
} tBaddie;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum doorType{	south = 0,
				north
};
typedef struct tDoor//class
{
	int		type;
	int		distObj;
	int		leftObj;
	int		rightObj;
	float	leftStartX;
	float	rightStartX;
	float	leftCurrentX;
	float	rightCurrentX;
} tDoor;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



typedef struct tVis//class
{
	int		start;
	int		end;
	int		startObj;
	int		endObj;
} tVis;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct tFire//class
{
	bool	on;
	int		baddie; // the baddie who is firing this
	float	angleY;
	int		life;	// when reaches zero the fireball will perish
	//int		BaddieType;
} tFire;


using namespace std;

//#define SHADERS			1		// use shaders
enum eMax{ MAXVIS = 8,		// max vis areas
			MAXFIREBALLS = 10,		// max fire balls
			MAXCRUMBS = 20,		// max amount of crumbs
			MAXBADDIES = 40		// max number of baddies
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function declarations
		void	initWindow		( );
		void	readData		( );
		void	GameStart		( );//load objects,...
		void	GameEnd			( );//delete objects,...
		void	loadMedia		( );
		void	setup			( );
		bool	checkpassword	( );
		//void	updateVis		( );
		//void	setupVis		( );
		void	die				( );
		//void	ShowMenu		( );
inline	void	GameCycle		( );
inline	void	HandleKeys		( );
inline	void	updatePlayer	( );
inline	void	updateBaddies	( );
		void	CreateLevel		( );
inline	void	updateDoors		( );
inline	void	HUD				( );
inline	void	updateFire		( );
inline	void	playerHurt		( );
inline	void	D9Main			( );
		void	DarkGDK()   {D9Main();}//init
inline	bool	loopInvariant( void ){return LoopGDK ( );}
inline	int		turnToFace		( int source, int target );
inline	float	getDistance		( float x1 , float y1 , float z1 , float x2 , float y2 , float z2);
		void	Fade			(int imgNr, int starta, int stopa, int rate);





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// GLOBAL GAME VARIABLES
bool	bGameover		= false;
char	szLevel[65][65];	// LEVEL DATA
int		crumbs[MAXCRUMBS][3 + MAXBADDIES]; // crumbs for the player to drop , 0=x , 1=z , 2=crumb number , 3+ is to flag if each baddie has taken the crumb
int		isDying			= 0;
float	fPlayerSpeed	= 4.5f;
float	fBaddieSpeed	= 4.0f;
bool	bWon			= false;
int		iDeadBaddies	= 0;
int		iNumBaddies		= 0;
int		iCrumbCount		= 1;
int		iSoundCount		= 0;
int		iImageCount		= 0;
int		iCurrentCrumb	= 0;
float	fGunWaggle		= 0;
float	fGunWaggle2		= 0;
int		iPlayerBullet	= 0;
bool	bDoorSound		= false;
bool	bDoorClose		= false;
int		doorCount		= 0;
int		baddieCount		= 0;
int		visCount		= 0;
int		currentVis		= 0;
int		iBlood			= 0;
int		currentFire		= 0;
int		iHealth			= 100;
int		iLives			= 1;
bool	bSplashScreen	= true;
int		iBloodAlpha[10]	   ;
int		iWinDoor		   ;
float	hurt			= 0.0f;
bool	ForcePresent	= false;
bool	gun				= false;
float	finishPosX		   ;
float	finishPosZ		   ;
float	gunInitialPosX	   ;
float	gunInitialPosZ	   ;
bool	once			= true;

bool	bNewGame		= true;

bool	bZoom			= false;
float	fZoomDist		= 200.0f;
float	fov				= 90.0f;
float   _fov			= 0.0f;
int		zz				= 0;
int		mz				= 0;

int		playX;
int		playY;
int		r,g,b;
int		creditsX;
int		creditsY;
int		exitY;

float	GunAngleX		= 5.7f;
float	GunAngleY		= 13.2f;
float	GunX			= 0.7f;
float	GunY			= 2.1f;
float	GunZ			= -0.5f;

float	FlashX			= 2.5f;
float	FlashY			= 2.0f;
float	FlashZ			= 7.0f;

int		shakeCrosshair	= 4;

int		screenX			= 1152 ;
int		screenY			= 864 ;

float	fps				  ;
//HUD data:
int		livesX;
int		livesY;
int		healthX;
int		healthY;
int		copyrX;
int		copyrY;
int		ammoX;
int		ammoY;
int		LivesX;
int		LivesY;
int		HealthX;
int		HealthY;

int		objectCount = 300;

bool	bGame		= true;

enum camera { cameraObj =17399 };

//namespace collisionGroups{
enum collisionGroups { all = 0,
					   camera,
					   level 					  
};
enum collisGroups {
					   baddies = 2
};


enum eBaddies{ MONSTER = 0,
			  ATrooper = 100
};
enum eGun {	gunObj = 486625,
			muzzleFlashObj
};
enum otherObj { _blood = 13,
				blood_ = 23
};
enum eEffects { gunEffect = 1
};
enum eImages {	pillarBump=0,
				floorTexture,
				monsterTexture,
				shadow,
				wallTexture,
				wallTop,
				hit,
				smoke,
				blood1,
				muzzleFlash,
				tavorHUD,//10
				controlsImage,
				tavorTexture,
				batteryTexture,
				ceiling,
				corridor,
				ATlaser,
				pillar,
				YouWin,
				MonsterLaser,
				doorTexture,//20
				HEALTH,
				LIVES,
				zoomScope,
				damageBox,
				/*play,
				playMO,
				exitGame,
				exitMO,
				back,
				backMO,
				creditsButton,
				creditsMO,*/
				firePart
};

int ParticleNumber = 1;
enum eBitmaps32 { loadingScreen = 1,
				  loadingScreen2
};

enum eSounds { gunSound = 2,
			  doorOpen1,
			  doorOpen2,
			  roar,
			  dieSound,
			  laserSound,
			  ATsound,
			  monsterDie,
			  monsterRise,//10
			  hurt1,
			  finalmoan,
			  monsterFinalmoan,
			  ATfinalmoan,
			  returned,//15
			  doorClose1,
			  doorClose2,
			  zoomSound,
			  RoundWin
};
enum eTavorLimbs { FIRESPOT = 2
};
enum tavor {	_select			= 0,
				select_			= 9,
				_idle			= 10,
				idle_			= 38,
				_move			= 39,
				move_			= 53,
				_startFire		= 54,
				startFire_		= 56,
				_automaticFire	= 57,
				automaticFire_	= 64,
				_endFire		= 65,
				endFire_		= 70,
				_reload			= 71,
				reload_			= 99,
				_cock			= 100,
				cock_			= 115,
				_putaway		= 116,
				putaway_		= 124
};


enum eLights { muzzleflashLight = 0
};
tBaddie	baddie[MAXBADDIES];
tDoor	door[20];
tVis	vis[MAXVIS];
tFire	fire[MAXFIREBALLS];

enum eGame { eMenu,
			eMain,
			eStart,
			eMenuStart,
			eWon
};
enum eMenuState {
};
