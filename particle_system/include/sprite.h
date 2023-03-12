///@author: Manuel Alcazar Lopez

#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include <SDL.h>
#include "entity.h"
#include "texture.h"

class Sprite : public Entity {
public:

	Sprite();
	Sprite(const Sprite& copy);
	virtual ~Sprite();

/** @brief Sprite Initializer
*
* Initializes a Sprite
*
* @param pos A vec3 which indicates the Sprite's position
* @param scale A vec3 which contains the Sprite's scale
*/
	void init(Vec3 pos, Vec3 scale) override;

/** @brief Sprite Draw
*
* Drawing of the Sprite on the screen using SDL
*
* @param renderer SDL renderer object
*/
	void draw(SDL_Renderer* renderer) override;


/** @brief Particle's update
*
* Updates the Sprite
*
*/
	void update() override;
	void set_texture(Texture* tex);
	Texture* texture() const;

private:
	Texture* tex_;
};

#endif
