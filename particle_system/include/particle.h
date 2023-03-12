///@author: Manuel Alcazar Lopez

#ifndef __PARTICLE_H__
#define __PARTICLE_H__ 1

#include "entity.h"
#include "path.h"
#include "sprite.h"
#include "game_manager.h"
#include <stdlib.h>

class Vec3;

class Particle : public Sprite {
public: 
	Particle();
	Particle(const Particle& copy);
	virtual ~Particle();

/** @brief Particle's Initialization
*
* Sets all the particle's initial parameters
*
* @return pos A vec3 which contains the Particle's position
* @return scale which contains the Particle's scale
*/
	void init(Vec3 pos, Vec3 scale) override;

/** @brief Particle's update
*
* Updates the particle while it's alive
*
*/
	void update() override;

	struct ParticleParams {
		Vec3 velocity;
		float speed;
		float lifeTime;
		float spawnTime;
		float maxTimeAlive;
	};

	ParticleParams params_; 
	ParticleParams startParams_;

};

#endif