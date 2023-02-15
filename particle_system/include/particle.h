//Author: Manuel Alcazar Lopez
#ifndef __PARTICLE_H__
#define __PARTICLE_H__ 1

#include "entity.h"
#include "path.h"
#include "sprite.h"
#include "game_manager.h"

class Vec2;
class Vec4;

class Particle {
public: 
	Particle();
	Particle(const Particle& copy);
	~Particle();

	struct ParticleParams {
		Vec3 pos;
		Vec3 scale;
		Vec3 velocity;
		float angle;
		float speed;
		Uint32 lifeTime;
		Uint32 shape;
		bool lerpColor;
		Vec4 startColor;
		Vec4 endColor;
	};

/** @brief Particle initialization
*
* Initializes a particle given it's parameters
*
* @param params Particle's parameters values
*/

	void init(ParticleParams& params, Uint8 mode, SDL_Renderer* renderer);

/** @brief Particle reset
*
* Resets a particle given it's new parameters
*
* @param params Particle's parameters new values
*/

	void reset(ParticleParams& params);

/** @brief Particle update
*
* Updates the particles' variables values setting it's color and position
*
*/
	void update();

/** @brief Particle current time setter
*
* Sets the Particle's current time with a given value
*
* @params time New Particle's currentTime value
*/

	void set_currentTime(Uint32 time);

/** @brief Particle current time getter
*
* Gets the Particle's current time
*
* @return Particle's currentTime value
*/

	Uint32 currentTime() const;

/** @brief Particle path object getter
*
* Gets the Particle's path object
*
* @return Particle's path object
*/

	Entity* entity() const;

private:
	ParticleParams params_;
	Uint32 currentTime_;

	Entity* entity_;
};

#endif