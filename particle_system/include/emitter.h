
#ifndef __EMITTER_H__
#define __EMITTER_H__ 1

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "entity.h"
#include "particle.h"

class WindowController;

class Emitter : public Entity {
public:
	Emitter();
	Emitter(const Emitter& copy);
	virtual ~Emitter();

	void loadPool(Uint32 pool_size);
	void init(Uint8 mode);
	void update();
	void draw(const WindowController& wc) override;
	void release();

	void smoke();
	void burst(Uint32 index);
	void firework(Uint32 index);
	void custom();

	Particle::ParticleParams params() const;

	void set_particle_scale(float sx, float sy);
	void set_particle_velocity_x(float min, float max);
	void set_particle_velocity_y(float min, float max);
	void set_particle_angle(float angle);
	void set_particle_speed(float min, float max);
	void set_particle_lifetime(Uint8 time);
	void set_particle_shape(Uint8 shape);
	void set_physics(Uint8 type);

	void set_random_shape();
	void set_random_lifetime(Uint32 rand);
	void set_random_angle();

private:
	std::vector<Particle> particle_pool_;
	Uint8 emmiter_mode_;
	Particle::ParticleParams emitter_params_;

	float min_speed_, max_speed_;
	float min_vel_x_, max_vel_x_;
	float min_vel_y_, max_vel_y_;
	float scale_x_, scale_y_;
	float angle_;
	Uint8 lifeTime_;
	Uint8 shape_;
	Uint8 physics_;

};

#endif