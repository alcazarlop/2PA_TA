
#include "particle.h"

Particle::Particle(){
	params_.velocity = Vec3();
	params_.speed = 0.0f;
	params_.lifeTime = 0.0f;
	params_.spawnTime = 0.0f;
	params_.maxTimeAlive = 0.0f;
}

Particle::Particle(const Particle& copy){
	params_.velocity = copy.params_.velocity;
	params_.speed = copy.params_.speed;
	params_.lifeTime = copy.params_.lifeTime;
	params_.spawnTime = copy.params_.spawnTime;
	params_.maxTimeAlive = copy.params_.maxTimeAlive;
}

Particle::~Particle(){
	Entity::~Entity();
}

void Particle::init(Uint8 type){
	// switch(type){
	// 	case 0: 
	// 		{
	// 			Path* path = new Path();
	// 			path->set_scale(10.0f, 10.0f, 10.0f);
	// 			switch(rand()%3){
	// 				case 0: path->loadSquare(); break;
	// 				case 1: path->loadCircle(); break;
	// 				case 2: path->loadStar(); break;
	// 				default: path->loadSquare(); break;
	// 			}
	// 			entity_ = path;
	// 			break;
	// 		}
	// 	case 1:
	// 		{
	// 			Sprite* sprite = new Sprite();
	// 			sprite->loadFromFile("../data/cuadrado.png", GameManager::Instance().renderer());
	// 			sprite->set_scale(1.0f, 1.0f, 1.0f);
	// 			entity_ = sprite;
	// 			break;
	// 		}
	// }

}

void Particle::draw(SDL_Renderer* renderer) {

}

void Particle::update(){
	// entity_->set_position(entity_->position() + (params_.velocity * params_.speed));
}
