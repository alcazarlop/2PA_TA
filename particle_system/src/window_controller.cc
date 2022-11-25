
#include "window_controller.h"

WindowController::WindowController(){
	window_ = NULL;
	renderer_ = NULL;
}

WindowController::WindowController(const WindowController& copy){
	window_ = copy.window_;
	renderer_ = copy.renderer_;
}

WindowController::~WindowController(){}

Sint8 WindowController::init(){

	window_ = SDL_CreateWindow("Particle System", SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED, 1024, 720, SDL_WINDOW_RESIZABLE);
	if(window_ == NULL){
		SDL_Log("SDL_CreateWindow() Failed!: %s", SDL_GetError());
		return -1;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if(renderer_ == NULL){
		SDL_Log("SDL_CreateRenderer() Failed!: %s", SDL_GetError());
		return -1;
	}

	return 1;
}

void WindowController::quit(){
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}

SDL_Window* WindowController::window() const {
	return window_;
}

SDL_Renderer* WindowController::renderer() const {
	return renderer_;
}