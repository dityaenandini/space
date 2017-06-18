#ifndef CSE167_Window_h
#define CSE167_Window_h

#include <string>

#include "Vector3.h"
#include "Matrix4.h"
#include "Globals.h"
#include "ParticleEmitter.h"
#include "ParticleEffect.h"

class Window	  // OpenGL output window related routines
{
    
public:
    
    static int width, height; 	            // window size
    
    static void initialize(void);
    static void idleCallback(void);
    static void reshapeCallback(int, int);
    static void displayCallback(void);

	static void normalKeys(unsigned char, int, int);
	static void normalKeysUp(unsigned char, int, int);
	static void specialKeys(int key, int x, int y);
	static void specialKeysUp(int key, int x, int y);
	static void processKeyFuncs();

	static void moveShip();
	static void fireMissle();
	static void animateMissles();
	static void spawnEnemy();
	static void animateEnemies();
	static int seekPosition(int list[]);
	static Vector3 getPos(Matrix4 world);
	static void updateTimers();
	static void drawHUD();
	static void hitDetector();
	static float checkDistance(Vector3 posA, Vector3 posB);
	static void gameOverScreen();
	static void gameStartScreen();
};

#endif

