
#ifndef __PARTICLE_H__
#define __PARTICLE_H__ 1

#include "path.h"
#include "collider2D.h"
#include "game_manager.h"

class Vec2;
class WindowController;

class Particle {
public: 
	Particle();
	Particle(const Particle& copy);
	~Particle();

	struct ParticleParams {
		Vec2 pos;
		Vec2 scale;
		Vec2 velocity;
		float angle;
		float speed;
		Uint8 lifeTime;
		Uint8 shape;
		Uint8 type;
	};

	void init(ParticleParams& params, const WindowController& wc);
	void reset(ParticleParams& params);
	void update();
	void draw(const WindowController& wc);
	void release();

	Uint32 currentTime() const;

private:
	ParticleParams params_;
	Uint8 currentTime_;

	Path path_;
	Collider2D collider_;
};

#endif