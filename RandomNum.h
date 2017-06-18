#ifndef _RANDOMNUM_H_
#define _RANDOMNUM_H_

#include <math.h>
#include <utility>
#include "Vector3.h"
#include "externals\glm-0.9.1\glm\glm.hpp"					//for Vector2


// Generate a random number between [0..1)
class RandomNum{
public:
	float Random();
	float RandRange(float fMin, float fMax);
	glm::vec3 RandUnitVec();
};

//inline float Random()
//{
//	return rand() / (float)RAND_MAX;
//}
//
//inline float RandRange(float fMin, float fMax)
//{
//	if (fMin > fMax) std::swap(fMin, fMax);
//	return (Random() * (fMax - fMin)) + fMin;
//}
//
//inline glm::vec3 RandUnitVec()
//{
//	float x = (Random() * 2.0f) - 1.0f;
//	float y = (Random() * 2.0f) - 1.0f;
//	float z = (Random() * 2.0f) - 1.0f;
//
//	return glm::normalize(glm::vec3(x, y, z));
//}

#endif