//Author: Manuel Alcazar Lopez
#ifndef __PARTICLE_H__
#define __PARTICLE_H__ 1

#include "entity.h"
#include "path.h"
#include "sprite.h"
#include "game_manager.h"

class Particle {
public: 
	Particle();
	Particle(const Particle& copy);
	~Particle();

private:
	Entity* entity_;
	
};

#endif