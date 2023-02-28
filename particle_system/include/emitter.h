//Author: Manuel Alcazar Lopez
#ifndef __EMITTER_H__
#define __EMITTER_H__ 1

#include <SDL.h>
#include <vector>
#include <math.h>
#include "math_utils.h"
#include "sprite.h"
#include "particle.h"
#include "game_manager.h"

class Vec3;

class Emitter {
public:
	Emitter();
	Emitter(const Emitter& copy);
	~Emitter();

	void init(SDL_Renderer* renderer, Vec3 pos, Uint8 mode, Uint8 type);
	void resize(Uint32 new_size);
	void add_particle();
	void update();
	void draw(SDL_Renderer* renderer);
	void release();

	void burst(Particle* particle, Uint32 index);
	void firework(Particle* particle);
	void smoke(Particle* particle);
	void waterfall(Particle* particle);

	void set_mode(Uint8 mode);
	void set_type(Uint8 type);

	Uint32 size() const;
	Uint8 mode() const;
	Uint8 type() const;

	Sprite* sprite() const;

private:
	Sprite* sprite_;
	std::vector<Particle*> pool_;

	Uint8 currentMode_;
	Uint8 currentType_;
	Uint32 totalParticles_;

};

#endif
