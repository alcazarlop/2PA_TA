
#include "emitter.h"

Emitter::Emitter(){
	sprite_ = nullptr;
	currentMode_ = 0;
	currentType_ = 0;
	totalParticles_ = 10;
	params_.emitterMode = 0;
	params_.emitterType = 0;
	params_.emitterSize = 0;
}

Emitter::Emitter(const Emitter& copy){
	sprite_ = copy.sprite_;
	pool_ = copy.pool_;
	currentMode_ = copy.currentMode_;
	currentType_ = copy.currentType_;
	totalParticles_ = copy.totalParticles_;
	params_.emitterMode = copy.params_.emitterMode;
	params_.emitterType = copy.params_.emitterType;
	params_.emitterSize = copy.params_.emitterSize;
}

Emitter::~Emitter(){
	pool_.clear();
}

void Emitter::init(SDL_Renderer* renderer, Vec3 pos, Uint8 mode, Uint8 type){
	sprite_ = new Sprite();
	Uint32 buffer = 0xFFFFFFFF;
	sprite_->loadFromBuffer(32, 32, renderer, &buffer);
	sprite_->set_position(pos.x, pos.y, pos.z);
	currentMode_ = mode;
	currentType_ = type;

	params_.emitterMode = currentMode_;
	params_.emitterType = currentType_;
	params_.emitterSize = totalParticles_;

	for(Uint32 i = 0; i < totalParticles_; ++i){
		add_particle();
	}
}

void Emitter::resize(Uint32 new_size){
	for(Uint32 i = 0; i < pool_.size(); ++i){
		delete pool_[i];		
	}
	pool_.clear();
	totalParticles_ = new_size;
	for(Uint32 i = 0; i < new_size; ++i){
		add_particle();		
	}
}

void Emitter::add_particle(){
	Particle* particle = new Particle();
	particle->init(currentType_);
	pool_.push_back(particle);
	for(Uint32 i = 0; i < totalParticles_; ++i){
		switch(currentMode_){
			case 0: burst(particle, i); break;
			case 1:	firework(particle); break;
			case 2:	smoke(particle); break;
			case 3:	waterfall(particle); break;
			default: burst(pool_[i], i); break;
		}
	}
}

void Emitter::update(){
	for(Uint32 i = 0; i < totalParticles_; ++i){
		if(pool_[i]->params_.lifeTime >= pool_[i]->params_.spawnTime){
			if(pool_[i]->params_.lifeTime < pool_[i]->params_.maxTimeAlive){
				pool_[i]->update();
			}
			else {
				switch(currentMode_){
					case 0:	burst(pool_[i], i); break;
					case 1:	firework(pool_[i]); break;
					case 2:	smoke(pool_[i]); break;
					case 3:	waterfall(pool_[i]); break;
					default: burst(pool_[i], i); break;
				}
			}
		}
		pool_[i]->params_.lifeTime += 0.016f;
	}
}

void Emitter::draw(SDL_Renderer* renderer){
	sprite_->draw(renderer);
	for(Uint32 i = 0; i < totalParticles_; ++i){
		if(pool_[i]->params_.lifeTime >= pool_[i]->params_.spawnTime){
			pool_[i]->entity()->draw(renderer);
		}
	}
}

void Emitter::release(){
	delete sprite_;
	for(Uint32 i = 0; i < totalParticles_; ++i){
		delete pool_[i];
	}
}

void Emitter::burst(Particle* particle, Uint32 index){
	particle->entity()->set_position(sprite_->position() + sprite_->texture()->width() * 0.5f);
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	particle->params_.velocity = Vec3(cosf((6.28f / pool_.size() * index)), sinf((6.28f / pool_.size() * index)), 0.0f);
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.spawnTime = -1.0f;
	particle->params_.maxTimeAlive = 1.0f;
}

void Emitter::firework(Particle* particle){
	particle->entity()->set_position(sprite_->position() + sprite_->texture()->width() * 0.5f);
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	particle->params_.velocity = Vec3(MathUtils::RandomFloat(-1.0f, 1.0f), -1.0f, 0.0f);
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	particle->params_.spawnTime = -1.0f;
	particle->params_.maxTimeAlive = 1.0f;
}

void Emitter::smoke(Particle* particle){
	static int smoke_count = 0;
	particle->entity()->set_position(sprite_->position() + sprite_->texture()->width() * 0.5f);
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	particle->params_.velocity = Vec3(MathUtils::RandomFloat(-0.5, 0.5f), -1.0f, 0.0f);
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	smoke_count == 0 ? particle->params_.spawnTime = 0.0f : particle->params_.spawnTime = MathUtils::RandomFloat(0.5f, 1.0f);
	particle->params_.maxTimeAlive = particle->params_.spawnTime + MathUtils::RandomFloat(0.8f, 1.2f);
	smoke_count++;
}

void Emitter::waterfall(Particle* particle){
	static int waterfall_count = 0;
	particle->entity()->set_position(Vec3(MathUtils::RandomFloat(0.0f, (float)GameManager::Instance().width()), 0.0f, 0.0f));
	particle->entity()->set_rotation(0.0f, 0.0f, MathUtils::RandomFloat(0.0f, 6.28f));
	particle->params_.velocity = Vec3(0.0f, 1.0f, 0.0f);
	particle->params_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->params_.lifeTime = 0.0f;
	waterfall_count == 0 ? particle->params_.spawnTime = 0.0f : particle->params_.spawnTime = MathUtils::RandomFloat(0.5f, 1.0f);
	particle->params_.maxTimeAlive = particle->params_.spawnTime + MathUtils::RandomFloat(2.0f, 4.0f);
	waterfall_count++;
}

void Emitter::set_mode(Uint8 mode){
	currentMode_ = (Uint8)MathUtils::Clamp(mode, 0, 3);
}

void Emitter::set_type(Uint8 type){
	currentType_ = (Uint8)MathUtils::Clamp(type, 0, 1);
}

Uint32 Emitter::size() const {
	return totalParticles_;
}

Uint8 Emitter::mode() const {
	return currentMode_;
}

Uint8 Emitter::type() const {
	return currentType_;
}

Sprite* Emitter::sprite() const {
	return sprite_;
}