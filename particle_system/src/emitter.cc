
#include "emitter.h"

Emitter::Emitter(){
	particle_pool_.clear();
	emitter_mode_ = 0;
	set_position(400.0f, 300.0f);
	min_speed_ = 1.0f;
	max_speed_ = 1.0f;
	min_vel_x_ = 1.0f;
	max_vel_x_ = 1.0f;
	min_vel_y_ = 1.0f;
	max_vel_y_ = 1.0f;
	scale_x_ = 10.0f;
	scale_y_ = 10.0f;
	angle_ = 0.0f;
	lifeTime_ = 20;
	shape_ = 0;
	physics_ = 0;
	friction_ = 0.0f;
	mass_ = 1.0f;
}

Emitter::Emitter(const Emitter& copy){
	particle_pool_ = copy.particle_pool_;
	emitter_mode_ = copy.emitter_mode_;
	min_speed_ = copy.min_speed_;
	max_speed_ = copy.max_speed_;
	min_vel_x_ = copy.min_vel_x_;
	max_vel_x_ = copy.max_vel_x_;
	min_vel_y_ = copy.min_vel_y_;
	max_vel_y_ = copy.max_vel_y_;
	scale_x_ = copy.scale_x_;
	scale_y_ = copy.scale_y_;
	angle_ = copy.angle_;
	lifeTime_ = copy.lifeTime_;
	shape_ = copy.shape_;
	physics_ = copy.physics_;
	friction_ = copy.friction_;
	mass_ = copy.mass_;
}

Emitter::~Emitter(){
	particle_pool_.clear();
}

void Emitter::loadPool(Uint32 size){
	for(Uint32 i = 0; i < size; ++i){
		Particle particle = Particle();
		particle_pool_.push_back(particle);
	}
}

void Emitter::init(Uint8 mode){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		switch(mode){
			case 0: smoke(); break;			
			case 1: burst(i); break;			
			case 2: custom(); break;			
			default: custom(); break;			
		}
		particle_pool_[i].init(emitter_params_);
	}
	emitter_mode_ = mode;
}

void Emitter::update(){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		if(particle_pool_[i].currentTime() < emitter_params_.lifeTime){
			particle_pool_[i].update();
		} else {
			switch(emitter_mode_){
				case 0: smoke(); break;			
				case 1: burst(i); break;			
				case 2: custom(); break;			
				default: custom(); break;			
			}
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
	emitter_params_.velocity.x = MathUtils::RandomFloat(-2.0f, 2.0f);
	emitter_params_.velocity.y = MathUtils::RandomFloat(-5.0f, 0.0f);
	emitter_params_.angle = MathUtils::RandomFloat(0.0f, 6.28f);
	emitter_params_.speed = MathUtils::RandomFloat(1.0f, 3.0f);
	emitter_params_.lifeTime = 50;
	emitter_params_.shape = rand()%3;
	emitter_params_.physics = physics_;
	emitter_params_.friction = friction_;
	emitter_params_.mass = mass_;
}

void Emitter::burst(Uint32 index){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(scale_x_, scale_y_);
	emitter_params_.velocity.x = cosf((6.28f / particle_pool_.size() * index));
	emitter_params_.velocity.y = sinf((6.28f / particle_pool_.size() * index));
	emitter_params_.angle =  MathUtils::RandomFloat(0.0f, 6.28f);
	emitter_params_.speed = MathUtils::RandomFloat(2.0f, 3.0f);
	emitter_params_.lifeTime = 100;
	emitter_params_.shape = rand()%3;
	emitter_params_.physics = physics_;
	emitter_params_.friction = friction_;
	emitter_params_.mass = mass_;
}

void Emitter::custom(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(scale_x_, scale_y_);
	emitter_params_.velocity.x = MathUtils::RandomFloat(min_vel_x_, max_vel_x_);
	emitter_params_.velocity.y = MathUtils::RandomFloat(min_vel_y_, max_vel_y_);
	emitter_params_.angle = angle_;
	emitter_params_.speed = MathUtils::RandomFloat(min_speed_, max_speed_);
	emitter_params_.lifeTime = lifeTime_;
	emitter_params_.shape = shape_;
	emitter_params_.physics = physics_;
	emitter_params_.friction = friction_;
	emitter_params_.mass = mass_;
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

void Emitter::set_physics(Uint8 physics){
 	physics_ = physics;
 	if(physics_){
 		for(Uint32 i = 0; i < particle_pool_.size(); ++i){
 			switch(emitter_mode_){
				case 0: smoke(); break;
				case 1: burst(i); break;
				case 2: custom(); break;
				default: custom(); break;
			}
 			particle_pool_[i].reset(emitter_params_);
 		}
 	}
}

void Emitter::set_friction(float value){
	friction_ = MathUtils::Clamp(value, 0.0f, 100.0f);
}

void Emitter::set_mass(float value){
	mass_ = MathUtils::Clamp(value, 1.0f, 100.0f);
}

void Emitter::set_random_shape(){
	shape_ = rand()%3;
}

void Emitter::set_random_lifetime(Uint32 r){
	lifeTime_ = (Uint8)MathUtils::Clamp(r, rand()%30, rand()%60);
}

void Emitter::set_random_angle(){
	angle_ = MathUtils::RandomFloat(0.0f, 6.28f);
}

void Emitter::set_pool_size(Uint32 new_size){
	if(new_size > particle_pool_.size()){
		for(Uint32 i = particle_pool_.size(); i < new_size; ++i){
			Particle particle = Particle();
			particle_pool_.push_back(particle);		
		}
		init(emitter_mode_);
	} 
	else if(new_size < particle_pool_.size()){
		Uint32 res = particle_pool_.size() - new_size;
		for(Uint32 i = 0; i < res; ++i){
			particle_pool_.pop_back();
		}
	} 
}