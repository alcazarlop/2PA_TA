//Author: Manuel Alcazar Lopez
#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include <SDL.h>
#include "entity.h"
#include "texture.h"

// GUSTAVO: Sprite should use the features of the Texture class, not
// re-implement them.

class Sprite : public Entity {
public:
	Sprite();
	Sprite(const Sprite& copy);
	virtual ~Sprite();

	void loadFromBuffer(Uint32 width, Uint32 height, SDL_Renderer* renderer, Uint32* pixel_buffer, Uint32 pitch = 4);
/** @brief Sprite load
*
* Loads a Sprite from memory
*
* @param path The loaded image address in the system
*/

	void loadFromFile(const char* path, SDL_Renderer* renderer);

/** @brief Sprite draw
*
* Drawing of a Sprite using SDL
*
* @param wc WindowController object used to draw the Sprite
*/

	void draw(SDL_Renderer* renderer) override;

/** @brief Sprite release
*
* Sprite release using SDL
*
*/

	Texture* texture() const;

private:
	Texture* tex_;
};

#endif
