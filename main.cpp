#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

#include "glee.h"

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"
#include "Matrix4.h"
#include "Globals.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);                                      //Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   //Open an OpenGL context with double buffering, RGB colors, and depth buffering
    glutInitWindowSize(Window::width, Window::height);          //Set initial window size
    glutCreateWindow("SpaceRescue");							//Open window and set window title
    
    glEnable(GL_DEPTH_TEST);                                    //Enable depth buffering
    glClear(GL_DEPTH_BUFFER_BIT);                               //Clear depth buffer
    glClearColor(0.0, 0.0, 0.0, 0.0);                           //Set clear color to black
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);                  //Set polygon drawing mode to fill front and back of each polygon
    glDisable(GL_CULL_FACE);                                    //Disable backface culling to render both sides of polygons
    glShadeModel(GL_SMOOTH);                                    //Set shading to smooth
    
    glEnable(GL_COLOR_MATERIAL);                                //Enable color materials
    glEnable(GL_LIGHTING);                                      //Enable lighting
    
    //Register callback functions:
    glutDisplayFunc(Window::displayCallback);
    glutReshapeFunc(Window::reshapeCallback);
    glutIdleFunc(Window::idleCallback);

	//Register the callback for the keyboard
	glutKeyboardFunc(Window::normalKeys);
	glutKeyboardUpFunc(Window::normalKeysUp);

	//Register the callbacks for the keyboard function keys
	glutSpecialFunc(Window::specialKeys);
	glutSpecialUpFunc(Window::specialKeysUp);
    
    //Initialize the Window:
    Window::gameStartScreen();
    
    //Start render loop
    glutMainLoop();
    
    return 0;
}

