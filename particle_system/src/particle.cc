
#include "particle.h"

Particle::Particle(){
	params_.velocity = Vec3();
	params_.speed = 0.0f;
	params_.lifeTime = 0.0f;
	params_.spawnTime = 0.0f;
	params_.maxTimeAlive = 0.0f;
}

Particle::Particle(const Particle& copy){
	params_ = copy.params_;
}

Particle::~Particle(){
	Sprite::~Sprite();
}

void Particle::init(){
	Sprite::init();
}

void Particle::update(){
	if(params_.lifeTime >= params_.spawnTime){
		if(params_.lifeTime < params_.maxTimeAlive){
			set_position(position() + (params_.velocity * params_.speed));
		} 
	}
	params_.lifeTime += 0.016f;
}
