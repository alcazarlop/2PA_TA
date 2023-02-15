//Author: Manuel Alcazar Lopez
#ifndef __EMITTER_H__
#define __EMITTER_H__ 1

#include <SDL.h>
#include <vector>
#include <math.h>
#include "math_utils.h"
#include "sprite.h"
#include "particle.h"

class Vec3;

class Emitter {
public:
	Emitter();
	Emitter(const Emitter& copy);
	~Emitter();

	void init(SDL_Renderer* renderer, Vec3 pos);
	void add_particle();
	void update();
	void draw(SDL_Renderer* renderer);
	void release();

	void burst(Particle* particle, Uint32 index);
	void firework(Particle* particle);
	void smoke(Particle* particle);
	void waterfall(Particle* particle);

private:
	Sprite* sprite_;
	std::vector<Particle*> pool_;

	Uint8 currentMode_;

};

#endif
