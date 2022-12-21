
#include "sprite.h"

Sprite::Sprite(){
	width_ = 0;
	height_ = 0;
	sprite_ = NULL;
}

Sprite::Sprite(const Sprite& copy){
	width_ = copy.width_;
	height_ = copy.height_;
	sprite_ = copy.sprite_;
}

Sprite::~Sprite(){}

void Sprite::loadFromFile(const char* path, SDL_Renderer* renderer){

	SDL_Surface* new_sprite = IMG_Load(path);
	if(new_sprite == NULL){
		SDL_Log("Failed to load new image: %s! Error: %s", path, IMG_GetError());
		return;
	}

	sprite_ = SDL_CreateTextureFromSurface(renderer, new_sprite);
	SDL_FreeSurface(new_sprite);

	width_ = new_sprite->w;
	height_ = new_sprite->h;
}

void Sprite::draw(const WindowController& wc){
	if(sprite_ != NULL && enabled()){
		SDL_FRect dstRect = { position().x, position().y, scale().x, scale().y };
		SDL_RenderCopyExF(wc.renderer(), sprite_, NULL, &dstRect, rotation(), NULL, SDL_FLIP_NONE);
	}
}

void Sprite::release(){
	if(NULL != sprite_)
		SDL_DestroyTexture(sprite_);
}
Uint32 Sprite::width() const {
	return width_;
}

Uint32 Sprite::height() const {
	return height_;
}
