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

class Emitter : public Path {
public:
	Emitter();
	Emitter(const Emitter& copy);
	virtual ~Emitter();


/** @brief Emitter's Initializer
*
* Initializes a Emitter
*
* @param pos A vec3 which indicates the Emitter's position
* @param scale A vec3 which contains the Emitter's scale
*/
	void init(Vec3 pos, Vec3 scale) override;

/** @brief Emitter resizer
*
* Resizes a emitter
*
* @param new_size A integer value for the new emitter's size
* @param texture A texture reference object for the particle's Sprite
*/
	void resize(Uint32 new_size, Texture* texture);

/** @brief Add particle
*
* Adds a new partcile
*
* @param texture A texture reference object for the particle's Sprite
*/
	void add_particle(Texture* texture);

/** @brief Emitter's update
*
* Updates the emitter's particles
*
*/
	void update() override;

/** @brief Emitter Draw
*
* Drawing of the emitter's particles
*
* @param renderer SDL renderer object
*/
	void draw(SDL_Renderer* renderer) override;


/** @brief Emitter's burst mode
*
* Manages the emitter's partciles for burst mode
*
* @param particle Emitter's particle object to be updated
* @param index Emitter's index ID
*/
	void burst(Particle* particle, Uint32 index);

/** @brief Emitter's firework mode
*
* Manages the emitter's partciles for firework mode
*
* @param particle Emitter's particle object to be updated
*/
	void firework(Particle* particle);

/** @brief Emitter's smoke mode
*
* Manages the emitter's partciles for smoke mode
*
* @param particle Emitter's particle object to be updated
*/
	void smoke(Particle* particle);

/** @brief Emitter's waterfall mode
*
* Manages the emitter's partciles for waterfall mode
*
* @param particle Emitter's particle object to be updated
*/
	void waterfall(Particle* particle);

	void set_mode(Uint8 mode);
	void set_type(Uint8 type);

	Uint32 particle_number() const;
	Uint8 mode() const;
	Uint8 type() const;

	struct EmitterParams {
		int emitterMode;
		int emitterSize;
	} e_params_;

private:
	std::vector<Entity*> pool_;

  // GUSTAVO: This should probably be an enum.
	Uint8 currentMode_;
	Uint32 totalParticles_;
};

#endif
