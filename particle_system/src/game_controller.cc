
#include "game_controller.h"

GameController::GameController(){
	isRunning_ = 0;
	window_ = NULL;
	renderer_ = NULL;
}

GameController::GameController(const GameController& copy){
	isRunning_ = copy.isRunning_;
	window_ = copy.window_;
	renderer_ = copy.renderer_;
}

GameController::~GameController() {}

Sint8 GameController::init(){

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
		SDL_Log("SDL_Init() Failed!: %s\n", SDL_GetError());
		return isRunning_ = -1;
	}

	window_ = SDL_CreateWindow("Particle System", SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED, 1024, 720, SDL_WINDOW_RESIZABLE);
	if(window_ == NULL){
		SDL_Log("SDL_CreateWindow() Failed!: %s", SDL_GetError());
		return isRunning_ = -1;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if(renderer_ == NULL){
		SDL_Log("SDL_CreateRenderer() Failed!: %s", SDL_GetError());
		return isRunning_ = -1;
	}

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	float points[24] = {
									-1.0f, -1.0f, 1.0f,
									-1.0f, 1.0f, 1.0f,
									1.0f, 1.0f, 1.0f,
									1.0f, -1.0f, 1.0f,

									-1.0f, -1.0f, -1.0f,
									-1.0f, 1.0f, -1.0f,
									1.0f, 1.0f, -1.0f,
									1.0f, -1.0f, -1.0f,
								};

	// for(Uint32 i = 0; i < 24; i+=3)
	// 	test.add_vertices(points[i], points[i + 1], points[i + 2]);
	
	// // test.show_raw_vertices();
	// test.set_position(100.0f, 100.f, 10.0f);
	// test.set_scale(20.0f, 20.0f, 20.0f);

	sp.loadFromFile("../data/melocoton.png", renderer_);
	sp.set_position(100.0f, 100.0f);

	return isRunning_ = 1;
}

void GameController::input(SDL_Event* e){
	while(SDL_PollEvent(e)){
		switch(e->type){
			case SDL_QUIT: isRunning_ = 0; break;
			case SDL_KEYDOWN:
				switch(e->key.keysym.sym){
					case SDLK_ESCAPE: isRunning_ = 0; break; 
				}
			break;
		}
	}
}

void GameController::update(){

}

void GameController::draw(){
	SDL_SetRenderDrawColor(renderer_, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(renderer_);

	// test.draw(renderer_);
	sp.draw(renderer_);

	SDL_RenderPresent(renderer_);
}

void GameController::quit(){
	sp.release();
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	IMG_Quit();
	SDL_Quit();
}

Sint8 GameController::loop(){

	init();
	SDL_Event eventHandler;

	while(isRunning_){
		input(&eventHandler);
		update();
		draw();
	}

	quit();
	return isRunning_;
}