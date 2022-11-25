
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

	void loadFromFile(const char* path, SDL_Window* window);
	void draw(const WindowController& wc) override;
	void release();

	Uint32 width() const;
	Uint32 height() const;

private:
	SDL_Surface* sprite_;
	SDL_Surface* screenSurface_;
	
	Uint32 width_;
	Uint32 height_;
};

#endif