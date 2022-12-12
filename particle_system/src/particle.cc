
#include "particle.h"

Particle::Particle(){
	params_.pos = Vec2();
	params_.scale = Vec2();
	params_.velocity = Vec2();
	params_.angle = 0.0f;
	params_.speed = 0.0f;
	params_.lifeTime = 0;
	params_.shape = 0;
	params_.physics = 0;
	params_.friction = 0.0f;
	params_.mass = 1.0f;
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
	params_.physics = copy.params_.physics;
	params_.friction = copy.params_.friction;
	params_.mass = copy.params_.mass;
	currentTime_ = copy.currentTime_;
}

Particle::~Particle(){}

void Particle::init(ParticleParams& params){
	this->params_.speed = params.speed;
	this->params_.velocity = params.velocity;
	this->params_.lifeTime = params.lifeTime;
	this->params_.physics = params.physics;
	this->params_.friction = params.friction;
	this->params_.mass = params.mass;

	collider_.init(params.scale.x, 1.0f, GameManager::Instance().space());
	switch(params.shape){
		case 0: path_.loadSquare(); break;
		case 1: path_.loadCircle(); break;
		case 2: path_.loadStar(); break;
		default: path_.loadSquare(); break;
	}

	switch(params.physics){
		case 0:
			path_.set_position(params.pos);
			path_.set_scale(params.scale);
			path_.set_rotation(params.angle);
		break;
		case 1:
			collider_.set_position(params.pos.x, params.pos.y);
			collider_.set_mass(params.mass);
		break;
		default:
			path_.set_position(params.pos);
			path_.set_scale(params.scale);
			path_.set_rotation(params.angle);
		break;
	}
}

void Particle::reset(ParticleParams& params){
	this->params_.speed = params.speed;
	this->params_.velocity = params.velocity;
	this->params_.lifeTime = params.lifeTime;
	this->params_.physics = params.physics;	
	this->params_.friction = params.friction;
	this->params_.mass = params.mass;

	switch(params.physics){
		case 0:
			path_.set_position(params.pos);
			path_.set_rotation(params.angle);
		break;
		case 1:
			collider_.set_position(params.pos.x, params.pos.y);
			collider_.set_mass(params.mass);
			collider_.set_friction(params.friction);
			collider_.set_velocity(0.0f, 0.0f);
		break;
		default:
			path_.set_position(params.pos);
			path_.set_rotation(params.angle);
		break;
	}
	currentTime_ = 0;
}

void Particle::update(){
	switch(params_.physics){
		case 0: 
			path_.set_position(path_.position() + params_.velocity * params_.speed);
		break;
		case 1: collider_.apply_force(params_.velocity.x * params_.speed, params_.velocity.y * params_.speed); break;
		default: 
			path_.set_position(path_.position() + params_.velocity * params_.speed);
		break;
	}
	currentTime_++;
}

void Particle::draw(const WindowController& wc){
	switch(params_.physics){
	case 0: path_.draw(wc); break;
	case 1: collider_.draw(wc.renderer(), path_.vertices()); break;
	default: path_.draw(wc); break;
	}
}

void Particle::release(){
	collider_.release();
}

Uint32 Particle::currentTime() const {
	return currentTime_;
}
