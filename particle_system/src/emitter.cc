
#include "emitter.h"

Emitter::Emitter(){
	emitter_mode_ = 0;
	isBound_ = false;
	tex_ = Sprite();
	min_speed_ = 1.0f;
	max_speed_ = 1.0f;
	min_vel_x_ = 1.0f;
	max_vel_x_ = 1.0f;
	min_vel_y_ = 1.0f;
	max_vel_y_ = 1.0f;
	lifeTime_ = 20;
	lerpColor_ = false;
	startColor_ = Vec4(255.0f, 255.0f, 255.0f, 255.0f);
	endColor_ = Vec4(255.0f, 255.0f, 255.0f, 255.0f);
}

Emitter::Emitter(const Emitter& copy){
	position_ = copy.position_;
	emitter_mode_ = copy.emitter_mode_;
	isBound_ = copy.isBound_;
	tex_ = copy.tex_;
	particle_pool_ = copy.particle_pool_;
	emitter_params_ = copy.emitter_params_;
	min_speed_ = copy.min_speed_;
	max_speed_ = copy.max_speed_;
	min_vel_x_ = copy.min_vel_x_;
	max_vel_x_ = copy.max_vel_x_;
	min_vel_y_ = copy.min_vel_y_;
	max_vel_y_ = copy.max_vel_y_;
	lifeTime_ = copy.lifeTime_;
	lerpColor_ = copy.lerpColor_;
	startColor_ = copy.startColor_;
	endColor_ = copy.endColor_;
	particle_mode_ = copy.particle_mode_;
	wc_ = copy.wc_;
}

Emitter::~Emitter(){

}

void Emitter::loadSprite(SDL_Renderer* renderer){
	tex_.loadFromFile("../data/melocoton.png", renderer);
	tex_.set_scale(32.0f, 32.0f);	
}

void Emitter::init(Uint32 size, Uint32 mode, Uint8 particle_mode, const WindowController& wc){
	for(Uint32 i = 0; i < size; ++i){
		Particle particle = Particle();
		particle_pool_.push_back(particle);
		switch(mode){
			case 0: firework(); break;			
			case 1: burst(i); break;
			case 2: custom(); break;
			default: firework(); break;			
		}
		particle_pool_[i].init(emitter_params_, particle_mode, wc);
	}
	emitter_mode_ = mode;
	particle_mode_ = particle_mode;
	wc_ = wc;
}

void Emitter::update(){
	tex_.set_position(position_.x, position_.y);
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		if(particle_pool_[i].currentTime() < emitter_params_.lifeTime){
			particle_pool_[i].update();
		} else {
			switch(emitter_mode_){
				case 0: firework(); break;			
				case 1: burst(i); break;			
				case 2: custom(); break;			
				default: firework(); break;			
			}
			particle_pool_[i].reset(emitter_params_);
		}
	}
}

void Emitter::draw(SDL_Renderer* renderer){
	tex_.draw(wc);
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		// GUSTAVO: This line is crashing when changing the pool size in runtime.
		particle_pool_[i].entity()->draw(wc);
	}
}

Particle::ParticleParams Emitter::params() const {
	return emitter_params_;
}

void Emitter::firework(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(10.0f, 10.0f);
	emitter_params_.velocity.x = MathUtils::RandomFloat(-2.0f, 2.0f);
	emitter_params_.velocity.y = MathUtils::RandomFloat(-5.0f, 0.0f);
	emitter_params_.angle = MathUtils::RandomFloat(0.0f, 6.28f);
	emitter_params_.speed = MathUtils::RandomFloat(1.0f, 3.0f);
	emitter_params_.lifeTime = 50;
	emitter_params_.shape = rand()%3;
	emitter_params_.lerpColor = rand()%2;
	emitter_params_.startColor = Vec4((float)(rand()%255),(float)(rand()%255), (float)(rand()%255), (float)(rand()%255));
	emitter_params_.endColor = Vec4((float)(rand()%255),(float)(rand()%255), (float)(rand()%255), (float)(rand()%255));
}

void Emitter::burst(Uint32 index){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(10.0f, 10.0f);
	emitter_params_.velocity.x = cosf((6.28f / particle_pool_.size() * index));
	emitter_params_.velocity.y = sinf((6.28f / particle_pool_.size() * index));
	emitter_params_.angle =  MathUtils::RandomFloat(0.0f, 6.28f);
	emitter_params_.speed = MathUtils::RandomFloat(2.0f, 3.0f);
	emitter_params_.lifeTime = 100;
	emitter_params_.shape = rand()%3;
	emitter_params_.lerpColor = rand()%2;
	emitter_params_.startColor = Vec4((float)(rand()%255),(float)(rand()%255), (float)(rand()%255), (float)(rand()%255));
	emitter_params_.endColor = Vec4((float)(rand()%255),(float)(rand()%255), (float)(rand()%255), (float)(rand()%255));
}

void Emitter::custom(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(10.0f, 10.0f);
	emitter_params_.velocity.x = MathUtils::RandomFloat(min_vel_x_, max_vel_x_);
	emitter_params_.velocity.y = MathUtils::RandomFloat(min_vel_y_, max_vel_y_);
	emitter_params_.angle = MathUtils::RandomFloat(0.0f, 6.28f);;
	emitter_params_.speed = MathUtils::RandomFloat(min_speed_, max_speed_);
	emitter_params_.lifeTime = lifeTime_;
	emitter_params_.shape = rand()%3;
	emitter_params_.lerpColor = lerpColor_;
	emitter_params_.startColor = startColor_;
	emitter_params_.endColor = endColor_;
}

void Emitter::set_particle_velocity_x(float min, float max){
	min_vel_x_ = min;
	max_vel_x_ = max;
}

void Emitter::set_particle_velocity_y(float min, float max){
	min_vel_y_ = min;
	max_vel_y_ = max;
}

void Emitter::set_particle_speed(float min, float max){
	min_speed_ = min;
	max_speed_ = max;
}

void Emitter::set_particle_lifetime(Uint32 time){
	lifeTime_ = time;
}

void Emitter::set_lerpColor(bool b){
	lerpColor_ = b;
}

void Emitter::set_startColor(Vec4 color){
	startColor_ = color;
}

void Emitter::set_endColor(Vec4 color){
	endColor_ = color;
}

void Emitter::set_random_velocity_x(){
	min_vel_x_ = MathUtils::RandomFloat(-10.0f, max_vel_y_);
	max_vel_x_ = MathUtils::RandomFloat(min_vel_y_, 10.0f);
}

void Emitter::set_random_velocity_y(){
	min_vel_y_ = MathUtils::RandomFloat(-10.0f, max_vel_y_);
	max_vel_y_ = MathUtils::RandomFloat(min_vel_y_, 10.0f);
}

void Emitter::set_random_speed(){
	min_speed_ = MathUtils::RandomFloat(-5.0f, 5.0f);
	max_speed_ = MathUtils::RandomFloat(1.0f, 5.0f);
}

void Emitter::set_random_lifetime(){
	lifeTime_ = 10 + rand()%120;
}

void Emitter::set_random_lerpColor(){
	lerpColor_ = rand()%2;
}

void Emitter::set_random_startColor(){
	startColor_ = Vec4((float)(rand()%255),(float)(rand()%255), (float)(rand()%255), (float)(rand()%255));
}

void Emitter::set_random_endColor(){
	endColor_ = Vec4((float)(rand()%255),(float)(rand()%255), (float)(rand()%255), (float)(rand()%255));
}

void Emitter::set_pool_size(Uint32 new_size){
	if(new_size > particle_pool_.size()){
		for(Uint32 i = particle_pool_.size(); i < new_size; ++i){
			Particle particle = Particle();
			particle_pool_.push_back(particle);		
		}
		init(new_size, emitter_mode_, particle_mode_, wc_);
	} 
	else if(new_size < particle_pool_.size()){
		Uint32 res = particle_pool_.size() - new_size;
		for(Uint32 i = 0; i < res; ++i){
			particle_pool_.pop_back();
		}
	} 
}

void Emitter::set_mode(Uint32 mode){
	emitter_mode_ = MathUtils::Clamp(mode, 0, 2);
}
