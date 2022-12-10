
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
	void init(Uint8 mode, const WindowController& wc);
	void update();
	void draw(const WindowController& wc) override;
	void release();

	void smoke();
	void burst();
	void firework();

private:
	std::vector<Particle> particle_pool_;
	Uint8 emmiter_mode_;
	Particle::ParticleParams emitter_params_;

};

#endif