//Author: Manuel Alcazar Lopez
#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"
#include "matrix_3.h"
#include "vector_2.h"

class WindowController;

class Sprite : public Entity {
public:
	Sprite();
	Sprite(const Sprite& copy);
	virtual ~Sprite();

/** @brief Sprite load
*
* Loads a Sprite from memory
*
* @param path The loaded image address in the system
* @param window A SDL window object to get the screenSurface_
*/

	void loadFromFile(const char* path, SDL_Window* window);

/** @brief Sprite draw
*
* Drawing of a Sprite using SDL
*
* @param wc WindowController object used to draw the Sprite
*/

	void draw(const WindowController& wc) override;

/** @brief Sprite release
*
* Sprite release using SDL
*
*/

	void release();

/** @brief Sprite width getter
*
* Gets the Sprite's width
*
*/

	Uint32 width() const;

/** @brief Sprite height getter
*
* Gets the Sprite's height
*
*/

	Uint32 height() const;

private:
	SDL_Surface* sprite_;
	SDL_Surface* screenSurface_;
	
	Uint32 width_;
	Uint32 height_;
};

#endif