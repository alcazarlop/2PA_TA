
#include "sprite.h"

Sprite::Sprite(){
	tex_ = NULL;
}

Sprite::Sprite(const Sprite& copy){
	position_ = copy.position_;
	scale_ = copy.scale_;
	rotation_ = copy.rotation_;
	tex_ = copy.tex_;
}

Sprite::~Sprite(){
  // GUSTAVO: CAREFUL! Do not ever explicitly call a destructor.
  // It is already being called by the runtime and this is causing a double destruction.
	Entity::~Entity();
}

void Sprite::init(Vec3 pos, Vec3 scale){
	set_position(pos);
	set_scale(scale);
}

void Sprite::draw(SDL_Renderer* renderer){
	if(tex_ != NULL && enabled()){
		SDL_FRect dstRect = {position_.x, position_.y, scale_.x * tex_->width(), scale_.y * tex_->height()};
		SDL_RenderCopyExF(renderer, tex_->texture(), NULL, &dstRect, rotation_.y, NULL, SDL_FLIP_NONE);
	}
}

void Sprite::update(){}

void Sprite::set_texture(Texture* tex){
	if(tex != NULL)
		tex_ = tex;
}

Texture* Sprite::texture() const {
	return tex_;
}

