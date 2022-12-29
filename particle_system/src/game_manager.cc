
#include "game_manager.h"

GameManager::GameManager() {
	space_ = NULL;
	stepTime_ = 0.0;
	startTime_ = 0;
	currentTime_ = 0;
}

// GUSTAVO: Singletons do NOT have copy constructors. They are singletons,
// theres is only one instance.
GameManager::GameManager(const GameManager& copy) {
	space_ = copy.space_; 				// Posible error al copiar punteros
	stepTime_ = copy.stepTime_;
	startTime_ = copy.startTime_;
}

GameManager::~GameManager() {}

void GameManager::init(){
	space_ = cpSpaceNew();
	stepTime_ = 1.0 / 60.0;
}

void GameManager::set_gravity(float x, float y){
	cpSpaceSetGravity(space_, cpv(x, y));
}

void GameManager::fixedTime(){
	cpSpaceStep(space_, stepTime_);
}

void GameManager::release(){
	cpSpaceFree(space_);
}

cpSpace* GameManager::space() const {
	return space_;
}

void GameManager::startTime(){
	startTime_ = SDL_GetTicks();
}

Uint32 GameManager::lastTime(){
	return SDL_GetTicks() - startTime_;
}

float GameManager::getFPS(){
	return currentTime_ / (lastTime() / 1000.0f);
}
