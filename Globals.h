#ifndef CSE167_Globals_h
#define CSE167_Globals_h

#include "Camera.h"
#include "Light.h"
#include "Sphere.h"
#include "OBJObject.h"
#include "Texture.h"
#include "Background.h"

#define PI 3.14159265
#define MAX 10	//Max number of enemies/missles

//Positioning Bounds
#define LBOUND -224	//left bound
#define RBOUND 224	//right bound
#define UBOUND 400	//upper bound
#define ESPAWN 440	//enemy spawn point
#define FLOOR 0		//Floor level
#define COLLISION 20

//Speed Definitions
#define SHIP_SPEED 4
#define MISSLE_SPEED 6
#define ENEMY_SPEED 3

//Timer Limits
#define COOLDOWN 15
#define SPAWN_DELAY 40

class Globals
{
    
public:
    
	static DrawData drawData;
    static UpdateData updateData;

    static Camera camera;
    static Light light;

	static Texture bg;
	
	static Sphere sphere;

	static OBJObject ship;
	static OBJObject enemy;
	static OBJObject astro;
    
};

#endif
