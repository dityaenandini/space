#ifndef _PARTICLEEFFECT_H_
#define _PARTICLEEFFECT_H_


#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include "Matrix4.h"
#include "Particle.h"
#include "Interpolator.h"
#include "RandomNum.h"
#include "Globals.h"
#include "ParticleEmitter.h"
#include "externals\glm-0.9.1\glm\glm.hpp"					//for Vector2
#include "externals\glm-0.9.1\glm\gtc\type_ptr.hpp"
#include "externals\glm-0.9.1\glm\gtc\quaternion.hpp"
#include "externals\glm-0.9.1\glm\gtx\quaternion.hpp"
#include "externals\glm-0.9.1\glm\gtx\compatibility.hpp"

class ParticleEffect
{
public:
	//Vertex for particle
	struct Vertex
	{
		Vertex()
			: pos(0)
			, diffuse(0)
			, tex(0)
		{}

		glm::vec3 pos;		//Vertex coordinate
		glm::vec4 diffuse;	//Diffuse color
		glm::vec2 tex;		//Texture coordinate
	};

	typedef std::vector<Vertex> VertexBuffer;
	typedef Interpolator<glm::vec4> ColorInterpolator;

	ParticleEffect(unsigned int numParticles = 0);
	virtual ~ParticleEffect();

	void SetParticleEmitter(ParticleEmitter* pEmitter);
	void SetColorInterplator(const ColorInterpolator& colors);

	void EmitParticles();

	virtual int Update();
	virtual void Render();

	bool LoadTexture(const std::string& fileName);

	// Resize the particle buffer with numParticles
	void Resize(unsigned int numParticles);

protected:
	//void RandomizeParticle(Particle& particle);
	void EmitParticle(Particle& particle);

public:
	// Build the vertex buffer from the particle buffer
	void BuildVertexBuffer();

	ParticleEmitter*    particleEmitter;
	ColorInterpolator   colorInterpolator;

	ParticleBuffer      particles;
	VertexBuffer        vertexBuffer;
	Matrix4		 		toWorld;
	GLuint              textureID;

	bool				move;
	float				scale;

	// Apply this force to every particle in the effect
	glm::vec3 				force;
};

#endif