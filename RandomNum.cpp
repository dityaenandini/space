#include "RandomNum.h"

float RandomNum::Random()
{
	return rand() / (float)RAND_MAX;
}

float RandomNum::RandRange(float fMin, float fMax)
{
	if (fMin > fMax) std::swap(fMin, fMax);
	return (Random() * (fMax - fMin)) + fMin;
}

glm::vec3 RandomNum::RandUnitVec()
{
	float x = (Random() * 2.0f) - 1.0f;
	float y = (Random() * 2.0f) - 1.0f;
	float z = (Random() * 2.0f) - 1.0f;

	return glm::normalize(glm::vec3(x, y, z));
}