
#include "particle.h"

Particle::Particle(){
	entity_ = nullptr;
}

Particle::Particle(const Particle& copy){
	entity_ = copy.entity_;
}

Particle::~Particle(){}

void Particle::init(int type){
	switch(type){
		case 0: 
			{
				Path* path = new Path();
				entity_ = path;
				break;
			}
		case 1:
			{
				Sprite* sprite = new Sprite();
				entity_ = sprite;
				break;
			}
	}

}

void Particle::draw(SDL_Renderer* renderer){
	entity_->draw(renderer);
}

void Particle::update(){
	entity_->set_position(entity_->position() + (params_.velocity * params_.speed));
}

void Particle::release(){
	delete entity_;
}

Entity* Particle::entity() const {
	return entity_;
}
