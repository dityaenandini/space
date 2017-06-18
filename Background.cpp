#include "GLee.h"
#include <Windows.h>

#include "Background.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"
#include <iostream>
using namespace std;

Background::Background(float size) : Drawable()
{
	this->size = size;
}

Background::~Background()
{
}

void Background::draw_bg(DrawData& data)
{
	float halfSize = size / 2.0;

	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glMultMatrixf(toWorld.ptr());

	Globals::bg.bind();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(-halfSize, halfSize, 0);
	glTexCoord2f(1, 0); glVertex3f(halfSize, halfSize, 0);
	glTexCoord2f(1, 1); glVertex3f(halfSize, -halfSize, 0);
	glTexCoord2f(0, 1); glVertex3f(-halfSize, -halfSize, 0);

	glEnd();

	Globals::bg.unbind();

	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void Background::update(UpdateData& data)
{
	//
}