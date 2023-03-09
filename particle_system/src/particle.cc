
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
	Sprite::~Sprite();
}

void Particle::init(){
	Sprite::init();
	
}

void Particle::update(){
	set_position(position() + (params_.velocity * params_.speed));
}
