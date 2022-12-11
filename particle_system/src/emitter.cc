
#include "emitter.h"

Emitter::Emitter(){
	emmiter_mode_ = 0;
	particle_pool_.clear();
	set_position(400.0f, 300.0f);
	min_speed_ = 1.0f;
	max_speed_ = 1.0f;
	min_vel_x_ = 0.0f;
	max_vel_x_ = 0.0f;
	min_vel_y_ = 0.0f;
	max_vel_y_ = 0.0f;
	scale_x_ = 10.0f;
	scale_y_ = 10.0f;
	angle_ = 0.0f;
}

Emitter::Emitter(const Emitter& copy){
	emmiter_mode_ = copy.emmiter_mode_;
	particle_pool_ = copy.particle_pool_;
	min_speed_ = copy.min_speed_;
	max_speed_ = copy.max_speed_;
	min_vel_x_ = copy.min_vel_x_;
	max_vel_x_ = copy.max_vel_x_;
	min_vel_y_ = copy.min_vel_y_;
	max_vel_y_ = copy.max_vel_y_;
	scale_x_ = copy.scale_x_;
	scale_y_ = copy.scale_y_;
	angle_ = copy.angle_;
}

Emitter::~Emitter(){
	particle_pool_.clear();
}

void Emitter::loadPool(Uint32 pool_size){
	for(Uint32 i = 0; i < pool_size; ++i){
		Particle particle = Particle();
		particle_pool_.push_back(particle);
	}
}

void Emitter::init(Uint8 mode){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		switch(mode){
			case 0: smoke(); break;			
			case 1: burst(); break;			
			case 2: firework(); break;			
			default: smoke(); break;			
		}
		particle_pool_[i].init(emitter_params_);
	}
}

void Emitter::update(){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		if(particle_pool_[i].currentTime() < emitter_params_.lifeTime){
			particle_pool_[i].update();
		} else {
			smoke();
			particle_pool_[i].reset(emitter_params_);
		}
	}
}

void Emitter::draw(const WindowController& wc){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		particle_pool_[i].draw(wc);
	}
}

void Emitter::release(){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		particle_pool_[i].release();
	}
}

Particle::ParticleParams Emitter::params() const {
	return emitter_params_;
}

void Emitter::smoke(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(scale_x_, scale_y_);
	emitter_params_.velocity.x = MathUtils::RandomFloat(-1.0f, 1.0f);
	emitter_params_.velocity.y = (float)(-5 + rand()%5);
	emitter_params_.angle = MathUtils::RandomFloat(0.0f, 6.28f);
	emitter_params_.speed = 1.0f;
	emitter_params_.lifeTime = 40;
	emitter_params_.shape = rand()%3;
	emitter_params_.type = 0;
}

void Emitter::burst(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(scale_x_, scale_y_);
	emitter_params_.velocity.x = MathUtils::RandomFloat(min_vel_x_, max_vel_x_);
	emitter_params_.velocity.y = MathUtils::RandomFloat(min_vel_y_, max_vel_y_);
	emitter_params_.angle = angle_;
	emitter_params_.speed = MathUtils::RandomFloat(min_speed_, max_speed_);
	emitter_params_.lifeTime = lifeTime_;
	emitter_params_.shape = shape_;
}

void Emitter::firework(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(scale_x_, scale_y_);
	emitter_params_.velocity.x = MathUtils::RandomFloat(min_vel_x_, max_vel_x_);
	emitter_params_.velocity.y = MathUtils::RandomFloat(min_vel_y_, max_vel_y_);
	emitter_params_.angle = angle_;
	emitter_params_.speed = MathUtils::RandomFloat(min_speed_, max_speed_);
	emitter_params_.lifeTime = lifeTime_;
	emitter_params_.shape = shape_;
}

void Emitter::set_particle_scale(float sx, float sy){
	scale_x_ = sx;
	scale_y_ = sy;
}

void Emitter::set_particle_velocity_x(float min, float max){
	min_vel_x_ = MathUtils::Clamp(min, -15.0f, max_vel_x_);
	max_vel_x_ = MathUtils::Clamp(max, min_vel_x_, 15.0f);
}

void Emitter::set_particle_velocity_y(float min, float max){
	min_vel_y_ = MathUtils::Clamp(min, -15.0f, max_vel_y_);
	max_vel_y_ = MathUtils::Clamp(max, min_vel_y_, 15.0f);
}

void Emitter::set_particle_angle(float angle){
	angle_ = angle;
}

void Emitter::set_particle_speed(float min, float max){
	min_speed_ = MathUtils::Clamp(min, 1.0f, max_speed_);
	max_speed_ = MathUtils::Clamp(max, min_speed_, 8.0f);
}

void Emitter::set_particle_lifetime(Uint8 time){
	lifeTime_ = time;
}

void Emitter::set_particle_shape(Uint8 shape){
	shape_ = shape;
}

void Emitter::set_physics(Uint8 type){
 	type_ = type;
}

void Emitter::set_random_shape(){
	shape_ = rand()%3;
}

void Emitter::set_random_lifetime(Uint32 r){
	lifeTime_ = rand()%r;
}

void Emitter::set_random_angle(){

}