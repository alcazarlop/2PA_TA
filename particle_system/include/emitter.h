///@author: Manuel Alcazar Lopez

#ifndef __EMITTER_H__
#define __EMITTER_H__ 1

#include <SDL.h>
#include <vector>
#include <math.h>
#include "math_utils.h"
#include "entity.h"
#include "particle.h"
#include "game_manager.h"
#include "texture.h"

class Vec3;

class Emitter : public Entity{
public:
	Emitter();
	Emitter(const Emitter& copy);
	~Emitter();

	void init(SDL_Renderer* renderer, Vec3 pos, Uint8 mode, Uint8 type);
	void resize(Uint32 new_size);
	void add_particle();
	void update();
	void draw(SDL_Renderer* renderer) override;

	void burst(Particle* particle, Uint32 index);
	void firework(Particle* particle);
	void smoke(Particle* particle);
	void waterfall(Particle* particle);

	void set_mode(Uint8 mode);
	void set_type(Uint8 type);

	void set_texture(Texture* tex);
	Texture* texture() const;

	Uint32 size() const;
	Uint8 mode() const;
	Uint8 type() const;

	struct EmitterParams {
		int emitterMode;
		int emitterType;
		int emitterSize;
	} params_;

private:
	std::vector<Particle*> pool_;

	Uint8 currentMode_;
	Uint8 currentType_;
	Uint32 totalParticles_;

	Texture* tex_;
};

#endif
