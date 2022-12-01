
#include "texture.h"

Uint32 Texture::num_textures = 0;

Texture::Texture(){
	width_ = 0;
	height_ = 0;
	position_ = Vec2();
	angle_ = 0.0f;
	texture_ = NULL;
}

Texture::Texture(const Texture& copy){
	width_ = copy.width_;
	height_ = copy.height_;
	texture_ = copy.texture_;
	position_ = copy.position_;
	angle_ = copy.angle_;
}

Texture::~Texture(){
	Texture::num_textures--;
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

void Texture::loadFromBuffer(Uint32 width, Uint32 height, SDL_Renderer* renderer, Uint32* pixel_buffer, Uint32 pitch){
	texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB565, SDL_TEXTUREACCESS_STREAMING, width, height);
	width_ = width;
	height_ = height;
	SDL_UpdateTexture(texture_, NULL, pixel_buffer, pitch);
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
	SDL_FRect dstRect = {position_.x, position_.y, (float)width_, (float)height_};
	SDL_RenderCopyExF(renderer, texture_, NULL, &dstRect, angle_, NULL, SDL_FLIP_NONE);
}

void Texture::set_position(float x, float y){
	position_.x = x;
	position_.y = y;
}

void Texture::set_position(Vec2 pos){
	position_ = pos;
}

void Texture::set_rotation(float angle){
	angle_ = angle;
}

Vec2 Texture::position() const {
	return position_;
}

float Texture::rotation() const {
	return angle_;
}

Texture* Texture::CreateTexture(){
	if(Texture::num_textures < Texture::kMaxTexture){
		Texture* t = new Texture();
		Texture::num_textures++;
		return t;
	} else {
		return nullptr;
	}
}