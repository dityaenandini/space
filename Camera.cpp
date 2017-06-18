#include "Camera.h"

Camera::Camera()
{
    c.identity();
    e.set(0.0, 150.0, 50.0);
    d.set(0.0, 0.0, 0.0);
    up.set(0.0, 1.0, 0.0);
    
    //Pre-define a camera matrix (and its inverse) that are shifted 'e' from the origin
    //This is used as a default camera position for Project 1
    c.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, e[0], e[1], e[2], 1);
    ci.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -e[0], -e[1], -e[2], 1);

	move_scale = 2;
}

Camera::~Camera()
{
    //Delete and dynamically allocated memory/objects here
}

Matrix4& Camera::getMatrix()
{
    return c;
}

Matrix4& Camera::getInverseMatrix()
{
    return ci;
}

void Camera::update()
{
  

	Vector3 zc = (e - d).normalize();
	Vector3 xc = (up.cross(zc)).normalize();
	Vector3 yc = zc.cross(xc);

	c.set(xc[0], xc[1], xc[2], 0, yc[0], yc[1], yc[2], 0, zc[0], zc[1], zc[2], 0, e[0], e[1], e[2], 1);

	Matrix4 r = Matrix4(xc[0], xc[1], xc[2], 0, yc[0], yc[1], yc[2], 0, zc[0], zc[1], zc[2], 0, 0, 0, 0, 1);
	Matrix4 ti;
	ti.makeTranslate(-e[0], -e[1], -e[2]);

	Matrix4 ri = r.transpose();
	ci = ri * ti;
}

void Camera::set(Vector3& e, Vector3& d, Vector3& up)
{
    this->e = e;
    this->d = d;
    this->up = up;
    update();
}

void Camera::reset(){
	e = Vector3(0, 0, 20);
	d = Vector3(0, 0, 0);
	up = Vector3(0, 1, 0);
	update();
}

void Camera::rotate(Matrix4 trans){
	Vector3 lookAt = trans * (d - e);
	d = e + lookAt;
	update();
}

void Camera::forward(){
	Vector3 forward = (d - e).normalize().scale(move_scale);
	e = e + forward;
	d = d + forward;
	update();
}

void Camera::backward(){
	Vector3 backward = (d - e).normalize().scale(-move_scale);
	e = e + backward;
	d = d + backward;
	update();
}

void Camera::left(){
	Vector3 left = up.cross((d - e).normalize()).scale(move_scale);
	e = e + left;
	d = d + left;
	update();
}

void Camera::right(){
	Vector3 right = up.cross((d - e).normalize()).scale(-move_scale);
	e = e + right;
	d = d + right;
	update();
}