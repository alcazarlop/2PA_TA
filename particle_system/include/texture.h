
#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL.h>
#include <SDL_image.h>

class Texture {
public:
	Texture();
	Texture(const Texture& copy);
	~Texture();

	void loadFromFile(const char* path, SDL_Renderer* renderer);
	void loadFromBuffer(Uint32 width, Uint32 height, SDL_Renderer* renderer);
	void release();

	Uint32 width() const;
	Uint32 height() const;

	void draw(SDL_Renderer* renderer);

private:
	Uint32 width_;
	Uint32 height_;
	
	SDL_Texture* texture_;

};

#endif