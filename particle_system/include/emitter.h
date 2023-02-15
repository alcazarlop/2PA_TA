//Author: Manuel Alcazar Lopez
#ifndef __EMITTER_H__
#define __EMITTER_H__ 1

// GUSTAVO: Be careful with the header. There may be some here like stdio,
// stdlib, etc... that are not needed. And some like matrix_4 that are.
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "entity.h"
#include "particle.h"
#include "sprite.h"

class Emitter : public Entity {
public:
	Emitter();
	Emitter(const Emitter& copy);
	virtual ~Emitter();

/** @brief Load Sprite
*
* Creates a texture for the emitter
*
* @param renderer A SDL renderer object necessary to create the texture
*/
	void loadSprite(SDL_Renderer* renderer);

/** @brief Emitter Initialize
*
* Initializes all the emitter's parameters
*
* @param size Value that determines the size of the particle's pool
* @param mode Value that determines the emitter's mode
*/

	void init(Uint32 size, Uint32 mode, Uint8 particle_mode);

/** @brief Load Texture
*
* Updates the emitter's components
*
*/
	void update();

/** @brief Load Texture
*
* Draws the emitter's components
*
* @param wc WindowController object needed for drawing the emitter's components
*/
	void draw(SDL_Renderer* renderer) override;

/** @brief Load Texture
*
* Releases the emitter's components
*
*/

/** @brief Firework
*
* Firework pattern particle mode
*
*/

	void firework();

/** @brief Burst 
*
* Burst pattern particle mode
*
* @param index Particle's index
*/

	void burst(Uint32 index);

/** @brief Custom
*
* Custom pattern particle mode
*
*/

	void custom();

	Particle::ParticleParams params() const;

	void set_particle_velocity_x(float min, float max);
	void set_particle_velocity_y(float min, float max);
	void set_particle_speed(float min, float max);
	void set_particle_lifetime(Uint32 time);
	void set_lerpColor(bool b);
	void set_startColor(Vec4 color);
	void set_endColor(Vec4 color);

	void set_pool_size(Uint32 new_size);
	void set_mode(Uint32 mode);

	void set_random_velocity_x();
	void set_random_velocity_y();
	void set_random_speed();
	void set_random_lifetime();
	void set_random_lerpColor();
	void set_random_startColor();
	void set_random_endColor();

	bool isBound_;

private:
	std::vector<Particle> particle_pool_;
	Uint32 emitter_mode_;
	Particle::ParticleParams emitter_params_;
	Sprite tex_;
	Uint8 particle_mode_;

	float min_speed_;
	float max_speed_;
	float min_vel_x_;
	float max_vel_x_;
	float min_vel_y_;
	float max_vel_y_;
	Uint32 lifeTime_;
	bool lerpColor_;
	Vec4 startColor_;
	Vec4 endColor_;

};

#endif
