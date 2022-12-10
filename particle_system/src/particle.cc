
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
	params_.pos = copy.params_.pos;
	params_.scale = copy.params_.scale;
	params_.velocity = copy.params_.velocity;
	params_.angle = copy.params_.angle;
	params_.speed = copy.params_.speed;
	params_.lifeTime = copy.params_.lifeTime;
	params_.shape = copy.params_.shape;
	currentTime_ = copy.currentTime_;
}

Particle::~Particle(){}

void Particle::init(ParticleParams& params, const WindowController& wc){
	this->params_.speed = params.speed;
	this->params_.velocity = params.velocity;
	this->params_.lifeTime = params.lifeTime;
	this->params_.type = params.type;

	switch(params.type){
		case 0:
			path_.set_position(params.pos);
			path_.set_scale(params.scale);
			path_.set_rotation(params.angle);
			switch(params.shape){
				case 0: path_.loadSquare(); break;
				case 1: path_.loadCircle(); break;
				case 2: path_.loadStar(); break;
				default: path_.loadSquare(); break;
			}
		break;
		case 1:
			collider_.init(params.scale.x, 1.0f, GameManager::Instance().space());
			collider_.set_position(params.pos.x, params.pos.y);
			switch(params.shape){
				case 0: collider_.loadSquare(); break;
				case 1: collider_.loadCircle(); break;
				case 2: collider_.loadStar(); break;
				default: collider_.loadSquare(); break;
			}
		break;
		default:
			path_.set_position(params.pos);
			path_.set_scale(params.scale);
			path_.set_rotation(params.angle);
			path_.loadSquare();
		break;
	}
}

void Particle::reset(ParticleParams& params){
	this->params_.speed = params.speed;
	this->params_.velocity = params.velocity;
	this->params_.lifeTime = params.lifeTime;
	this->params_.type = params.type;	
	switch(params.type){
		case 0:
			path_.set_position(params.pos);
			path_.set_rotation(params.angle);
		break;
		case 1:
			collider_.set_position(params.pos.x, params.pos.y);
		break;
		default:
			path_.set_position(params.pos);
			path_.set_rotation(params.angle);
		break;
	}
	currentTime_ = 0;
}

void Particle::update(){
	switch(params_.type){
		case 0: 
			path_.set_position(path_.position() + params_.velocity);
		break;
		case 1: 
		break;
		default: 
			path_.set_position(path_.position() + params_.velocity);
		break;
	}
	currentTime_++;
}

void Particle::draw(const WindowController& wc){
	switch(params_.type){
	case 0: path_.draw(wc); break;
	case 1: collider_.draw(wc.renderer()); break;
	default: path_.draw(wc); break;
	}
}

void Particle::release(){
	collider_.release();
}

Uint32 Particle::currentTime() const {
	return currentTime_;
}
