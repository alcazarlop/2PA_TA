
#include "emitter.h"

Emitter::Emitter(){
	sprite_ = nullptr;
	pool_.clear();
	currentMode_ = 0;
	totalParticles_ = 10;
}

Emitter::Emitter(const Emitter& copy){
	sprite_ = copy.sprite_;
	pool_ = copy.pool_;
	currentMode_ = copy.currentMode_;
	totalParticles_ = copy.totalParticles_;
}

Emitter::~Emitter(){
	pool_.clear();
}

void Emitter::init(SDL_Renderer* renderer, Vec3 pos){
	sprite_ = new Sprite();
	Uint32 buffer = 0xFFFFFFFF;
	sprite_->loadFromBuffer(32, 32, renderer, &buffer);
	sprite_->set_position(100.0f, 100.0f, 0.0f);

	for(Uint32 i = 0; i < totalParticles_; ++i){
		add_particle();
	}

}

void Emitter::resize(Uint32 new_size){
	for(Uint32 i = 0; i < pool_.size(); ++i){
		pool_[i]->release();		
	}
	pool_.clear();
	totalParticles_ = new_size;
	for(Uint32 i = 0; i < new_size; ++i){
		add_particle();		
	}
}

void Emitter::add_particle(){
	Particle* particle = new Particle();
	particle->init(1);
	pool_.push_back(particle);
	for(Uint32 i = 0; i < totalParticles_; ++i){
		switch(currentMode_){
			case 0: burst(particle, i); break;
		}
	}
}

void Emitter::update(){
	for(Uint32 i = 0; i < totalParticles_; ++i){
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
	for(Uint32 i = 0; i < totalParticles_; ++i){
		pool_[i]->entity()->draw(renderer);
	}
}

void Emitter::release(){
	delete sprite_;
	for(Uint32 i = 0; i < totalParticles_; ++i){
		pool_[i]->release();
		delete pool_[i];
	}
}

void Emitter::burst(Particle* particle, Uint32 index){
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	particle->params_.velocity = Vec3(cosf((6.28f / pool_.size() * index)), sinf((6.28f / pool_.size() * index)), 0.0f);
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.maxTimeAlive = 1.0f;
}

void Emitter::firework(Particle* particle){
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	// particle->params_.velocity = Vec3();
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.maxTimeAlive = 1.0f;
}

void Emitter::smoke(Particle* particle){
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	// particle->params_.velocity = Vec3();
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.maxTimeAlive = MathUtils::RandomFloat(1.0f, 2.0f);
}

void Emitter::waterfall(Particle* particle){
	particle->entity()->set_position(sprite_->position());
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	// particle->params_.velocity = Vec3();
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.maxTimeAlive = MathUtils::RandomFloat(1.0f, 2.0f);
}