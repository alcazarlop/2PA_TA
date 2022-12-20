
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
	path_ = copy.path_;
	params_ = copy.params_;
	currentTime_ = copy.currentTime_;
}

Particle::~Particle(){}

void Particle::init(ParticleParams& params){
	params_ = params;

	switch(params_.shape){
		case 0: path_.loadSquare(); break;
		case 1: path_.loadCircle(); break;
		case 2: path_.loadStar(); break;
		default: path_.loadSquare(); break;
	}
	path_.set_position(params_.pos);
	path_.set_scale(params_.scale);
	path_.set_rotation(params_.angle);
}

void Particle::reset(ParticleParams& params){
	params_ = params;
	path_.set_position(params_.pos);
	path_.set_rotation(params_.angle);
	currentTime_ = 0;
}

void Particle::update(){
	if(params_.lerpColor){
		path_.set_color(Vec4::LerpUnclamped(params_.startColor, params_.endColor, (float)SDL_GetTicks()));
	}
	path_.set_position(path_.position() + params_.velocity * params_.speed);
	currentTime_++;
}

void Particle::draw(const WindowController& wc){
	path_.draw(wc);
}

void Particle::set_currentTime(Uint32 time){
	currentTime_ = time;
}

Uint32 Particle::currentTime() const {
	return currentTime_;
}

Path Particle::path() const {
	return path_;
}
