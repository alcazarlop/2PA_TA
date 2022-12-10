
#include "emitter.h"

Emitter::Emitter(){
	emmiter_mode_ = 0;
	particle_pool_.clear();
	set_position(400.0f, 300.0f);
}

Emitter::Emitter(const Emitter& copy){
	emmiter_mode_ = copy.emmiter_mode_;
	particle_pool_ = copy.particle_pool_;
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

void Emitter::init(Uint8 mode, const WindowController& wc){
	for(Uint32 i = 0; i < particle_pool_.size(); ++i){
		switch(mode){
			case 0: smoke(); break;			
			case 1: burst(); break;			
			case 2: firework(); break;			
			default: smoke(); break;			
		}
		particle_pool_[i].init(emitter_params_, wc);
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

void Emitter::smoke(){
	emitter_params_.pos = position();
	emitter_params_.scale = Vec2(10.0f, 10.0f);
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
	emitter_params_.velocity.x = 1.0f;
	emitter_params_.velocity.y = 1.0f;
	emitter_params_.angle = 0.0f;
	emitter_params_.speed = 1.0f;
	emitter_params_.lifeTime = 40;
	emitter_params_.shape = rand()%3;
}

void Emitter::firework(){
	emitter_params_.pos = position();
	emitter_params_.velocity.x = 1.0f;
	emitter_params_.velocity.y = 1.0f;
	emitter_params_.angle = 0.0f;
	emitter_params_.speed = 1.0f;
	emitter_params_.lifeTime = 40;
	emitter_params_.shape = rand()%3;
}