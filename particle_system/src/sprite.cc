
#include "sprite.h"

Sprite::Sprite(){
	position_ = Vec2();
	scale_ = Vec2(1.0f, 1.0f);
	rotation_ = 0.0f;
	width_ = 0;
	height_ = 0;
	tex_ = NULL;
}

Sprite::Sprite(const Sprite& copy){
	position_ = copy.position_;
	scale_ = copy.scale_;
	rotation_ = copy.rotation_;
	width_ = copy.width_;
	height_ = copy.height_;
	tex_ = copy.tex_;
}

Sprite::~Sprite(){}

SDL_Texture* Sprite::loadFromFile(const char* path, SDL_Renderer* renderer){
	if(NULL != tex_)
		SDL_DestroyTexture(tex_);

	SDL_Surface* new_texture = IMG_Load(path);
	if(new_texture == NULL)
		SDL_Log("Failed to load new image: %s! Error: %s", path, IMG_GetError());

	SDL_Texture* optimizedTexture = SDL_CreateTextureFromSurface(renderer, new_texture);

	width_ = new_texture->w;
	height_ = new_texture->h;

	SDL_FreeSurface(new_texture);
	tex_ = optimizedTexture;
	return tex_;
}

void Sprite::draw(SDL_Renderer* render){
	if(tex_ != NULL && enabled()){
		SDL_FRect dstRect = { position_.x, position_.y, width_ * scale_.x, height_ * scale_.y };
		SDL_RenderCopyExF(render, tex_, NULL, &dstRect, rotation_, NULL, SDL_FLIP_NONE);
	}
}

void Sprite::release(){
	if(NULL != tex_)
		SDL_DestroyTexture(tex_);
}

Uint32 Sprite::width() const {
	return width_;
}

Uint32 Sprite::height() const {
	return height_;
}

void Sprite::set_position(const Vec2& vec){
	position_ = vec;
}

void Sprite::set_position(float x, float y){
	position_.x = x;
	position_.y = y;
}

void Sprite::set_scale(const Vec2& vec){
	scale_ = vec;
}

void Sprite::set_scale(float x, float y){
	scale_.x = x;
	scale_.y = y;
}

void Sprite::set_rotation(float radians){
	rotation_ = radians;
}

Vec2 Sprite::position() const {
	return position_;
}

Vec2 Sprite::scale() const {
	return scale_;
}

float Sprite::rotation() const {
	return rotation_;
}
