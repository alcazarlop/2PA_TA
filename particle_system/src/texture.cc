
#include "texture.h"

Texture::Texture(){
	width_ = 0;
	height_ = 0;
	texture_ = NULL;
}

Texture::Texture(const Texture& copy){
	width_ = copy.width_;
	height_ = copy.height_;
	texture_ = copy.texture_;
}

Texture::~Texture(){

}

void Texture::loadFromFile(const char* path, SDL_Renderer* renderer){
	SDL_Surface* new_texture = IMG_Load(path);
	if(new_texture == NULL){
		SDL_Log("Failed loading image %s! SDL image error: %s\n", path, IMG_GetError());
		return;
	}
	width_ = new_texture->w;
	height_ = new_texture->h;
	texture_ = SDL_CreateTextureFromSurface(renderer, new_texture);
	SDL_FreeSurface(new_texture);
}

void Texture::loadFromBuffer(Uint32 width, Uint32 height, SDL_Renderer* renderer){
	//TODO
	texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB565, SDL_TEXTUREACCESS_STREAMING, width, height);
}

void Texture::release(){
	if(texture_ != NULL)
		SDL_DestroyTexture(texture_);
}

Uint32 Texture::width() const {
	return width_;
}

Uint32 Texture::height() const {
	return height_;
}

void Texture::draw(SDL_Renderer* renderer){
	SDL_RenderCopyExF(renderer, texture_, NULL, NULL, NULL, NULL, SDL_FLIP_NONE);
}