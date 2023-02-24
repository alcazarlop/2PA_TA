
#include "particle.h"

Particle::Particle(){
	entity_ = nullptr;
}

Particle::Particle(const Particle& copy){
	entity_ = copy.entity_;
}

Particle::~Particle(){
	delete entity_;
}

void Particle::init(Uint8 type){
	switch(type){
		case 0: 
			{
				Path* path = new Path();
				path->set_scale(10.0f, 10.0f, 10.0f);
				switch(rand()%3){
					case 0: path->loadSquare(); break;
					case 1: path->loadCircle(); break;
					case 2: path->loadStar(); break;
					default: path->loadSquare(); break;
				}
				entity_ = path;
				break;
			}
		case 1:
			{
				Sprite* sprite = new Sprite();
				sprite->loadFromFile("../data/cuadrado.png", GameManager::Instance().renderer());
				sprite->set_scale(1.0f, 1.0f, 1.0f);
				entity_ = sprite;
				break;
			}
	}

}

void Particle::update(){
	entity_->set_position(entity_->position() + (params_.velocity * params_.speed));
}

Entity* Particle::entity() const {
	return entity_;
}
