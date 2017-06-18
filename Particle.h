#ifndef _PARTICLE_H_
#define _PARTICLE_H_


using namespace std;
#include <vector>
#include "Vector3.h"
#include "Vector4.h"
#include "externals\glm-0.9.1\glm\glm.hpp"

//Defines a single particle
struct Particle
{
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec4 color;
	float rotate;
	float size;
	float age;	
	float lifeTime;
};

typedef vector<Particle> ParticleBuffer;

#endif