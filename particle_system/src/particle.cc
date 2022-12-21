
#include "particle.h"

Particle::Particle(){
	params_.pos = Vec2();
	params_.scale = Vec2();
	params_.velocity = Vec2();
	params_.angle = 0.0f;
	params_.speed = 0.0f;
	params_.lifeTime = 0;
	params_.shape = 0;
	currentTime_ = 0;
}

Particle::Particle(const Particle& copy){
	entity_ = copy.entity_;
	params_ = copy.params_;
	currentTime_ = copy.currentTime_;
}

Particle::~Particle(){}

void Particle::init(ParticleParams& params, Uint8 mode, const WindowController& wc){
	Sprite* sprite = new Sprite();
	switch(mode){
	case 0: entity_ = new Path(); break;
	case 1:  
		sprite->loadFromFile("../data/melocoton.png", wc.renderer()); 
		entity_ = sprite;
	break;
	}
	params_ = params;
	entity_->set_position(params_.pos);
	entity_->set_scale(params_.scale);
	entity_->set_rotation(params_.angle);
}

void Particle::reset(ParticleParams& params){
	params_ = params;
	entity_->set_position(params_.pos);
	entity_->set_rotation(params_.angle);
	currentTime_ = 0;
}

void Particle::update(){
	// if(params_.lerpColor){
	// 	path_.set_color(Vec4::LerpUnclamped(params_.startColor, params_.endColor, (float)SDL_GetTicks()));
	// }
	entity_->set_position(entity_->position() + params_.velocity * params_.speed);
	currentTime_++;
}

void Particle::draw(const WindowController& wc){
	entity_->draw(wc);
}

void Particle::set_currentTime(Uint32 time){
	currentTime_ = time;
}

Uint32 Particle::currentTime() const {
	return currentTime_;
}

Entity* Particle::entity() const {
	return entity_;
}
