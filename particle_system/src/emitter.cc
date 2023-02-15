
#include "emitter.h"

Emitter::Emitter(){
	sprite_ = nullptr;
	pool_.clear();
	currentMode_ = 0;
}

Emitter::Emitter(const Emitter& copy){
	sprite_ = copy.sprite_;
	pool_ = copy.pool_;
	currentMode_ = copy.currentMode_;
}

Emitter::~Emitter(){
	pool_.clear();
}

void Emitter::init(SDL_Renderer* renderer, Vec3 pos){
	sprite_ = new Sprite();
	Uint32 buffer = 0xFFFFFFFF;
	sprite_->loadFromBuffer(32, 32, renderer, &buffer);
	sprite_->set_position(100.0f, 100.0f, 0.0f);
}

void Emitter::add_particle(){
	Particle* particle = new Particle();
	particle->init(0);
	pool_.push_back(particle);
	for(unsigned int i = 0; i < pool_.size(); ++i){
		switch(currentMode_){
			case 0: burst(particle, i); break;
		}
	}
}

void Emitter::update(){
	for(unsigned int i = 0; i < pool_.size(); ++i){
		if(pool_[i]->params_.lifeTime < pool_[i]->params_.maxTimeAlive){
			pool_[i]->update();
			pool_[i]->params_.lifeTime += 0.016f;
		}
		else {
			switch(currentMode_){
				case 0:	burst(pool_[i], i); break;
			}
		}
	}
}

void Emitter::draw(SDL_Renderer* renderer){
	sprite_->draw(renderer);
	for(unsigned int i = 0; i < pool_.size(); ++i){
		pool_[i]->draw(renderer);
	}
}

void Emitter::release(){
	delete sprite_;
	for(unsigned int i = 0; i < pool_.size(); ++i){
		pool_[i]->release();
		delete pool_[i];
	}
}

void Emitter::burst(Particle* particle, Uint32 index){
	particle->entity()->set_scale(10.0f, 10.0f, 10.0f);
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	particle->params_.velocity = Vec3(cosf((6.28f / pool_.size() * index)), sinf((6.28f / pool_.size() * index)), 0.0f);
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.maxTimeAlive = 1.0f;
}

void Emitter::firework(Particle* particle){
	particle->entity()->set_scale(10.0f, 10.0f, 10.0f);
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
}

void Emitter::smoke(Particle* particle){
	particle->entity()->set_scale(10.0f, 10.0f, 10.0f);
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
}

void Emitter::waterfall(Particle* particle){
	particle->entity()->set_scale(10.0f, 10.0f, 10.0f);
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
}