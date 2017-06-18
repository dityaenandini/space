#ifndef _PARTICLEEMITTER_H_
#define _PARTICLEEMITTER_H_

#include "Particle.h"
#include "RandomNum.h"

class ParticleEmitter
{
public:
	ParticleEmitter();
	virtual void EmitParticle(Particle& particle);

	float MinimumRadius;
	float MaximumRadius;

	float MinInclination;
	float MaxInclination;

	float MinAzimuth;
	float MaxAzimuth;

	float MinSpeed;
	float MaxSpeed;

	float MinLifetime;
	float MaxLifetime;

	glm::vec3   Origin;
};

#endif