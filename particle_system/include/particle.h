
#ifndef __PARTICLE_H__
#define __PARTICLE_H__ 1

#include <stdlib.h>
#include <math.h>
#include "path.h"

class Vec2;

class Particle : public Path {
public: 
	Particle();
	Particle(const Particle& copy);
	virtual ~Particle();

	void init(float posx, float posy);
	void softInit();

	void load_square();
	void load_circle();
	void load_star();

	void update();

private:
	Vec2 velocity_;
	Vec2 originalPosition_;
	Uint8 lifeTime_, currentTime_;

};

#endif