#include "Vector3.h"
#include <math.h>
#include <iostream>
#include <cstring>
#include "Vector4.h"

Vector3::Vector3()
{
    std::memset(m, 0, sizeof(m));
}

Vector3::Vector3(float m0, float m1, float m2)
{
    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
}

Vector3::~Vector3()
{
    //
}

float* Vector3::ptr()
{
    return &m[0];
}

void Vector3::set(float x, float y, float z)
{
    m[0] = x;
    m[1] = y;
    m[2] = z;
}

void Vector3::set(int index, float value)
{
    m[index] = value;
}

float& Vector3::operator [] (int loc)
{
    return m[loc];
}

Vector3 Vector3::add(Vector3 a)
{
    Vector3 b;
    
	for (int i = 0; i < 3; i++){
		b.m[i] = m[i] + a.m[i];
	}
    
    return b;
}

Vector3 Vector3::operator + (Vector3 a)
{
    return add(a);
}

Vector3 Vector3::subtract(Vector3 a)
{
    Vector3 b;
    
	for (int i = 0; i < 3; i++){
		b.m[i] = m[i] - a.m[i];
	}
    
    return b;
}

Vector3 Vector3::operator - (Vector3 a)
{
    return subtract(a);
}

Vector3 Vector3::negate(void)
{
    Vector3 b;
    
	for (int i = 0; i < 3; i++){
		b[i] = -m[i];
	}
    
    return b;
}

Vector3 Vector3::scale(float s)
{
    Vector3 b;
    
	for (int i = 0; i < 3; i++){
		b[i] = s * m[i];
	}
    
    return b;
}

Vector3 Vector3::multiply(float a)
{
    Vector3 b;
    
	for (int i = 0; i < 3; i++){
		b[i] = a * m[i];
	}
    
    return b;
}

Vector3 Vector3::operator * (float a)
{
    return multiply(a);
}

Vector3 Vector3::multiply(Vector3 a)
{
    Vector3 b;
    
	for (int i = 0; i < 3; i++){
		b[i] = m[i] * a.m[i];
	}

    return b;
}

Vector3 Vector3::operator * (Vector3 a)
{
    return multiply(a);
}


float Vector3::dot(Vector3 a)
{
	Vector3 b = *this * a;

	return b[0] + b[1] + b[2];
}

Vector3 Vector3::cross(Vector3 a)
{
    Vector3 b;
    
	b[0] = m[1] * a.m[2] - m[2] * a.m[1];
	b[1] = m[2] * a.m[0] - m[0] * a.m[2];
	b[2] = m[0] * a.m[1] - m[1] * a.m[0];
    
    return b;
}

float Vector3::angle(Vector3 a)
{
	float dotProd = dot(a);
	float magProd = magnitude() * a.magnitude();
    
	if (magProd == 0){
		return 0;
	}

    float ret = acos(dotProd/magProd);

	if (ret != ret){
		return 0;
	}

	return ret;
}

float Vector3::magnitude(void)
{
	Vector3 temp = *this * *this;
    return sqrt(temp[0] + temp[1] + temp[2]);
}

Vector3 Vector3::normalize(void)
{
    Vector3 b;
    
	float mag = magnitude();

	if (mag != 0){
		b[0] = m[0] / mag;
		b[1] = m[1] / mag;
		b[2] = m[2] / mag;
	}
    
    return b;
}

Vector4 Vector3::toVector4(float w)
{
    Vector4 b(m[0], m[1], m[2], w);
    return b;
}

void Vector3::print(std::string comment)
{
    std::cout << comment << std::endl;
    std::cout << "<x:" << m[0] <<  ", y:" << m[1] << ", z:" << m[2] << ">" << std::endl;
}
