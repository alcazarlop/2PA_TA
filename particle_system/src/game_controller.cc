
#include "game_controller.h"

GameController::GameController(){
	isRunning_ = 0;
	wc_ = WindowController();
}

GameController::GameController(const GameController& copy){
	isRunning_ = copy.isRunning_;
	wc_ = copy.wc_;
}

GameController::~GameController() {}

Sint8 GameController::init(){

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
		SDL_Log("SDL_Init() Failed!: %s\n", SDL_GetError());
		return isRunning_ = -1;
	}

	isRunning_ = wc_.init(1024, 680);

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(wc_.window());
  ImGui_ImplSDLRenderer_Init(wc_.renderer());

	gm_.init();
	gm_.set_gravity(0.0f, 1.0f);

	return isRunning_ = 1;
}

void GameController::input(SDL_Event* e){
	while(SDL_PollEvent(e)){
		ImGui_ImplSDL2_ProcessEvent(e);
		switch(e->type){
			case SDL_QUIT: isRunning_ = 0; break;
			case SDL_KEYDOWN:
				switch(e->key.keysym.sym){
					case SDLK_ESCAPE: isRunning_ = 0; break; 
				}
			break;
			case SDL_MOUSEBUTTONDOWN: 
				if(emitter_pool_.pool_.size() != 0){
					emitter_pool_.pool_.back().isBound_ = false;
				}
			break;
		}
	}
}

void GameController::update(){

	gm_.fixedTime();


	for(Uint32 i = 0; i < emitter_pool_.pool_.size(); ++i){
		emitter_pool_.pool_[i].update();
	}

	gm_.currentTime_++;
}

void GameController::draw(){
 	ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(wc_.window());
  ImGui::NewFrame();
	SDL_SetRenderDrawColor(wc_.renderer(), 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(wc_.renderer());

	EmitterPoolManager(&emitter_pool_, wc_.renderer());

	for(Uint32 i = 0; i < emitter_pool_.pool_.size(); ++i){
		emitter_pool_.pool_[i].draw(wc_);
	}

  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(wc_.renderer());
}

void GameController::quit(){
	gm_.release();

  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
	SDL_DestroyRenderer(wc_.renderer());
	SDL_DestroyWindow(wc_.window());
	IMG_Quit();
	SDL_Quit();
}

Sint8 GameController::loop(){

	SDL_Event eventHandler;
	srand((unsigned int)time(NULL));

	init();
	gm_.startTime();

	while(isRunning_){
		input(&eventHandler);
		update();
		draw();
	}

	quit();
	return isRunning_;
}