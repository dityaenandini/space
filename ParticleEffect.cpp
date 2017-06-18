#include "GLee.h"

#include "ParticleEffect.h"
#include <iostream>
RandomNum ra;

ParticleEffect::ParticleEffect(unsigned int numParticles /* = 0 */)
	: particleEmitter(NULL)
	, colorInterpolator(glm::vec4(1))
	, textureID(0)
	, force(0, 0, 0)
	, scale(1)
{
	toWorld.identity();
	Resize(numParticles);
}

ParticleEffect::~ParticleEffect()
{
	if (textureID != 0)
	{
		glDeleteTextures(1, &textureID);
		textureID = 0;
	}
}

void ParticleEffect::SetParticleEmitter(ParticleEmitter* pEmitter)
{
	particleEmitter = pEmitter;
}

void ParticleEffect::SetColorInterplator(const ColorInterpolator& colors)
{
	colorInterpolator = colors;
}

bool ParticleEffect::LoadTexture(const std::string& fileName)
{
	if (textureID != 0)
		glDeleteTextures(1, &textureID);

	//NOTE: Quick fix (not working correctly)
	Texture text;
	text = Texture("data/textures/particle.DDS");
	textureID = text.id;
	return (textureID != 0);
}

void ParticleEffect::EmitParticle(Particle& particle)
{
	if (particleEmitter != NULL)
		particleEmitter->EmitParticle(particle);
}

void ParticleEffect::EmitParticles()
{
	for (unsigned int i = 0; i < particles.size(); ++i)
		EmitParticle(particles[i]);
}

void ParticleEffect::BuildVertexBuffer()
{
	const glm::vec3 X(0.5, 0, 0);
	const glm::vec3 Y(0, 0.5, 0);
	const glm::vec3 Z(0, 0, 1.0);

	// Make sure the vertex buffer has enough vertices to render the effect
	// If the vertex buffer is already the correct size, no change is made.
	vertexBuffer.resize(particles.size() * 4, Vertex());
	for (unsigned int i = 0; i < particles.size(); ++i)
	{
		Particle& particle = particles[i];
		glm::quat rotation = glm::angleAxis(particle.rotate, Z);

		unsigned int vertexIndex = i * 4;
		Vertex& v0 = vertexBuffer[vertexIndex + 0];   // Bottom-left
		Vertex& v1 = vertexBuffer[vertexIndex + 1];   // Bottom-right
		Vertex& v2 = vertexBuffer[vertexIndex + 2];   // Top-right
		Vertex& v3 = vertexBuffer[vertexIndex + 3];   // Top-left

		// Bottom-left
		v0.pos = particle.position + ((-X - Y) * particle.size);
		v0.tex = glm::vec2(0, 1);
		v0.diffuse = particle.color;

		// Bottom-right
		v1.pos = particle.position + ((X - Y) * particle.size);
		v1.tex = glm::vec2(1, 1);
		v1.diffuse = particle.color;

		// Top-right
		v2.pos = particle.position + ((X + Y) * particle.size);
		v2.tex = glm::vec2(1, 0);
		v2.diffuse = particle.color;

		// Top-left
		v3.pos = particle.position + ((-X + Y) * particle.size);
		v3.tex = glm::vec2(0, 0);
		v3.diffuse = particle.color;
	}

}

int ParticleEffect::Update()
{
	for (unsigned int i = 0; i < particles.size(); ++i)
	{
		Particle& particle = particles[i];

		particle.age++;

		//End particle instance
		if (particle.age > particle.lifeTime)
			return 0;

		float lifeRatio = glm::saturate(particle.age / particle.lifeTime);
		particle.velocity = particle.velocity + force;
		particle.position = particle.position + particle.velocity;
		particle.color = colorInterpolator.GetValue(lifeRatio);
		particle.rotate = glm::lerp<float>(0.0f, 720.0f, lifeRatio);
		particle.size = glm::lerp<float>(5.0f, 0.0f, lifeRatio);
	}

	BuildVertexBuffer();

	//Particle instance still active
	return 1;
}

void ParticleEffect::Render()
{
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);                 // Enable Blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // Type Of Blending To Perform
	glEnable(GL_TEXTURE_2D);            // Enable textures

	glPushMatrix();

	glMultMatrixf(toWorld.ptr());

	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &(vertexBuffer[0].pos));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &(vertexBuffer[0].tex));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), &(vertexBuffer[0].diffuse));

	glDrawArrays(GL_QUADS, 0, vertexBuffer.size());

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glBindTexture(GL_TEXTURE_2D, 0);

	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void ParticleEffect::Resize(unsigned int numParticles)
{
	particles.resize(numParticles, Particle());
	vertexBuffer.resize(numParticles * 4, Vertex());
}