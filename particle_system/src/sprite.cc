
#include "sprite.h"

Sprite::Sprite(){
	width_ = 0;
	height_ = 0;
	sprite_ = NULL;
	screenSurface_ = NULL;
}

Sprite::Sprite(const Sprite& copy){
	width_ = copy.width_;
	height_ = copy.height_;
	sprite_ = copy.sprite_;
}

Sprite::~Sprite(){}

void Sprite::loadFromFile(const char* path, SDL_Window* window){
	if(screenSurface_ == NULL)
		screenSurface_ = SDL_GetWindowSurface(window);

	SDL_Surface* new_sprite = IMG_Load(path);
	if(new_sprite == NULL){
		SDL_Log("Failed to load new image: %s! Error: %s", path, IMG_GetError());
		return;
	}
	width_ = new_sprite->w;
	height_ = new_sprite->h;
	sprite_ = SDL_ConvertSurface(new_sprite, screenSurface_->format, 0);
	SDL_FreeSurface(new_sprite);
}

void Sprite::draw(const WindowController& wc){
	if(sprite_ != NULL && enabled()){
		SDL_Rect dstRect = { (Sint32)position_.x, (Sint32)position_.y, (Sint32)(width_ * scale_.x), (Sint32)(height_ * scale_.y) };
		SDL_BlitSurface(sprite_, NULL, screenSurface_, &dstRect);
		SDL_UpdateWindowSurface(wc.window());
	}
}

void Sprite::release(){
	if(NULL != sprite_)
		SDL_FreeSurface(sprite_);
}

Uint32 Sprite::width() const {
	return width_;
}

Uint32 Sprite::height() const {
	return height_;
}
