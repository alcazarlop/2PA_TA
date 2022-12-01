
#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL.h>
#include <SDL_image.h>
#include "vector_2.h"

class Texture {
public:
	~Texture();

	void loadFromFile(const char* path, SDL_Renderer* renderer);
	void loadFromBuffer(Uint32 width, Uint32 height, SDL_Renderer* renderer, Uint32* pixel_buffer, Uint32 pitch = 4);
	void release();

	Uint32 width() const;
	Uint32 height() const;

	void draw(SDL_Renderer* renderer);

	void set_position(float x, float y);
	void set_position(Vec2 position);
	void set_rotation(float angle);

	Vec2 position() const;
	float rotation() const;

	static Texture* CreateTexture();
	static const Uint32 kMaxTexture = 32; 

private:
	Texture();
	Texture(const Texture& copy);
	static Uint32 num_textures;

	Vec2 position_;
	float angle_;

	Uint32 width_;
	Uint32 height_;
	SDL_Texture* texture_;

};

#endif