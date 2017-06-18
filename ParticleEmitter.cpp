#include "GLee.h"

#include "ParticleEmitter.h"
#include "Globals.h"
#include <iostream>
using namespace std;

ParticleEmitter::ParticleEmitter()
	: Origin(0)
{}

RandomNum rn;

void ParticleEmitter::EmitParticle(Particle& particle)
{
	float inclination = glm::radians( rn.RandRange( MinInclination, MaxInclination ) );
	float azimuth = glm::radians( rn.RandRange( MinAzimuth, MaxAzimuth ) );
	
	float radius = rn.RandRange(MinimumRadius, MaximumRadius);
	float speed = rn.RandRange(MinSpeed, MaxSpeed);
	float lifetime = rn.RandRange(MinLifetime, MaxLifetime);

	float sInclination = sinf(inclination);

	float X = sInclination * cosf(azimuth);
	float Y = sInclination * sinf(azimuth);
	float Z = cosf(inclination);

	glm::vec3 vector(X, Y, Z);

	particle.position = (vector * radius) + Origin;
	particle.velocity = vector * speed;

	particle.lifeTime = lifetime;
	particle.age = 0;
}