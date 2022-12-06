
#include "window_controller.h"

WindowController::WindowController(){
	window_ = NULL;
	renderer_ = NULL;
	width_ = 0;
	height_ = 0;
}

WindowController::WindowController(const WindowController& copy){
	window_ = copy.window_;
	renderer_ = copy.renderer_;
	width_ = copy.width_;
	height_ = copy.height_;
}

WindowController::~WindowController(){}

Sint8 WindowController::init(Uint32 width, Uint32 height){

	window_ = SDL_CreateWindow("Particle System", SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
	if(window_ == NULL){
		SDL_Log("SDL_CreateWindow() Failed!: %s", SDL_GetError());
		return -1;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if(renderer_ == NULL){
		SDL_Log("SDL_CreateRenderer() Failed!: %s", SDL_GetError());
		return -1;
	}

	width_ = width;
	height_ = height;

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

Uint32 WindowController::width() const {
	return width_;
}

Uint32 WindowController::height() const {
	return height_;
}