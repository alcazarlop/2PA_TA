
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
	startParams_ = copy.startParams_;
}

Particle::~Particle(){
	Sprite::~Sprite();
}

void Particle::init(Vec3 pos, Vec3 scale){
	Sprite::init(pos, scale);
}

void Particle::update(){
	if(params_.lifeTime >= params_.spawnTime && enabled()){
		if(params_.lifeTime < params_.maxTimeAlive){
			set_position(position() + (params_.velocity * params_.speed));
		} 
		else {
			params_ = startParams_;
			set_enable(false);
		}
	}
	params_.lifeTime += 0.016f;
}
