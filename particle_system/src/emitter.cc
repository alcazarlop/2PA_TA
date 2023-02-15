
#include "emitter.h"

Emitter::Emitter(){
	sprite_ = nullptr;
	pool_.clear();
}

Emitter::Emitter(const Emitter& copy){
	pool_ = copy.pool_;
}

Emitter::~Emitter(){
	pool_.clear();
}

void Emitter::init(SDL_Renderer* renderer){
	sprite_ = new Sprite();
	Uint32 buffer = 0xFFFFFFFF;
	sprite_->loadFromBuffer(32, 32, renderer, &buffer);
	sprite_->set_scale(1.0f, 1.0f, 0.0f);
	sprite_->set_position(100.0f, 100.0f, 0.0f);
}

void Emitter::add(int num){
	switch(num){
	case 0: 
		{
			Path* path = new Path();
			path->set_scale(10.0f, 10.0f, 10.0f);
			pool_.push_back(path);
			break;
		}
	case 1:
		{
			Sprite* sprite = new Sprite();
			pool_.push_back(sprite);
			break;
		}
	}
}

void Emitter::update(){
	for(unsigned int i = 0; i < pool_.size(); ++i){
		pool_[i]->set_position(1.0f + (float)(SDL_GetTicks() * 0.0016f), 1.0f, 0.0f);
	}
}

void Emitter::draw(SDL_Renderer* renderer){
	sprite_->draw(renderer);
	for(unsigned int i = 0; i < pool_.size(); ++i){
		pool_[i]->draw(renderer);
	}
}

void Emitter::release(){
	delete sprite_;
	for(unsigned int i = 0; i < pool_.size(); ++i){
		delete pool_[i];
	}
}