
#include "emitter.h"

Emitter::Emitter(){
	currentMode_ = 0;
	totalParticles_ = 10;
	e_params_.emitterMode = 0;
	e_params_.emitterSize = 0;
}

Emitter::Emitter(const Emitter& copy){
	pool_ = copy.pool_;
	currentMode_ = copy.currentMode_;
	totalParticles_ = copy.totalParticles_;
	e_params_ = copy.e_params_;
}

Emitter::~Emitter(){
	for(Uint32 i = 0; i < totalParticles_; ++i){
		delete pool_[i];
	}
	pool_.clear();
	Path::~Path();
}

void Emitter::init(Vec3 pos, Vec3 scale){
	Path::init(pos, scale);
	e_params_.emitterMode = currentMode_;
	e_params_.emitterSize = totalParticles_;
}

void Emitter::resize(Uint32 new_size, Texture* texture){
	for(Uint32 i = 0; i < pool_.size(); ++i){
		delete pool_[i];		
	}
	pool_.clear();
	totalParticles_ = new_size;
	for(Uint32 i = 0; i < new_size; ++i){
		add_particle(texture);		
	}
}

void Emitter::add_particle(Texture* texture){
	Particle* particle = new Particle();
	particle->set_texture(texture);
	for(Uint32 i = 0; i < totalParticles_; ++i){
		switch(currentMode_){
			case 0: burst(particle, i); break;
			case 1:	firework(particle); break;
			case 2:	smoke(particle); break;
			case 3:	waterfall(particle); break;
			default: burst(particle, i); break;
		}
	}
	particle->init(position(), Vec3(1.0f, 1.0f, 0.0f));
	pool_.push_back(particle);
}

void Emitter::update(){
	for(Uint32 i = 0; i < totalParticles_; ++i){
		pool_[i]->update();
		if(!pool_[i]->enabled()){
			if(currentMode_ != 3) pool_[i]->set_position(position());
			else pool_[i]->set_position(Vec3(MathUtils::RandomFloat(0.0f, (float)GameManager::Instance().width()), 0.0f, 0.0f));
			pool_[i]->set_enable(true);
		}
	}
}

void Emitter::draw(SDL_Renderer* renderer){
	Path::draw(renderer);
	for(Uint32 i = 0; i < pool_.size(); ++i){
		pool_[i]->draw(renderer);
	}
}

void Emitter::burst(Particle* particle, Uint32 index){
	particle->set_position(position());
	particle->startParams_.velocity = Vec3(cosf((6.28f / pool_.size() * index)), sinf((6.28f / pool_.size() * index)), 0.0f);
	particle->startParams_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->startParams_.lifeTime = 0.0f;
	particle->startParams_.spawnTime = -1.0f;
	particle->startParams_.maxTimeAlive = 1.0f;
}

void Emitter::firework(Particle* particle){
	particle->set_position(position());
	particle->startParams_.velocity = Vec3(MathUtils::RandomFloat(-1.0f, 1.0f), -1.0f, 0.0f);
	particle->startParams_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->startParams_.lifeTime = 0.0f;
	particle->startParams_.spawnTime = -1.0f;
	particle->startParams_.maxTimeAlive = 1.0f;
}

void Emitter::smoke(Particle* particle){
	static int smoke_count = 0;
	particle->set_position(position());
	particle->startParams_.velocity = Vec3(MathUtils::RandomFloat(-0.5, 0.5f), -1.0f, 0.0f);
	particle->startParams_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->startParams_.lifeTime = 0.0f;
	smoke_count == 0 ? particle->startParams_.spawnTime = 0.0f : particle->startParams_.spawnTime = MathUtils::RandomFloat(0.5f, 1.0f);
	particle->startParams_.maxTimeAlive = particle->startParams_.spawnTime + MathUtils::RandomFloat(0.8f, 1.2f);
	smoke_count++;
}

void Emitter::waterfall(Particle* particle){
	static int waterfall_count = 0;
	particle->set_position(Vec3(MathUtils::RandomFloat(0.0f, (float)GameManager::Instance().width()), 0.0f, 0.0f));
	particle->startParams_.velocity = Vec3(0.0f, 1.0f, 0.0f);
	particle->startParams_.speed = MathUtils::RandomFloat(2.0f, 5.0f);
	particle->startParams_.lifeTime = 0.0f;
	waterfall_count == 0 ? particle->startParams_.spawnTime = 0.0f : particle->startParams_.spawnTime = MathUtils::RandomFloat(0.5f, 1.0f);
	particle->startParams_.maxTimeAlive = particle->startParams_.spawnTime + MathUtils::RandomFloat(2.0f, 4.0f);
	waterfall_count++;
}

void Emitter::set_mode(Uint8 mode){
	currentMode_ = (Uint8)MathUtils::Clamp(mode, 0, 3);
}

Uint32 Emitter::particle_number() const {
	return totalParticles_;
}

Uint8 Emitter::mode() const {
	return currentMode_;
}
