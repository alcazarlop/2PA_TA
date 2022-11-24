
#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"
#include "matrix_3.h"
#include "vector_2.h"

class Sprite : public Entity {
public:
	Sprite();
	Sprite(const Sprite& copy);
	~Sprite();

	void loadFromFile(const char* path, SDL_Window* window);
	void draw(SDL_Window* window);
	void release();

	Uint32 width() const;
	Uint32 height() const;

	void set_position(const Vec2& pos);
	void set_position(float x, float y);
	void set_scale(const Vec2& scale);
	void set_scale(float x, float y);
	void set_rotation(float radians);

	Vec2 position() const;
	Vec2 scale() const;
	float rotation() const;

private:
	Vec2 position_;
	Vec2 scale_;
	float rotation_;

	Uint32 width_;
	Uint32 height_;
	SDL_Surface* sprite_;
	SDL_Surface* screenSurface_;
};

#endif