
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
	gm_.set_gravity(100.0f, 100.0f);

	// coll.initCircle(5.0f, 1.0f, gm_.space());
	// coll2.initCircle(10.0f, 1.0f, gm_.space());

	// coll.set_position(100.f, 100.0f);
	// coll2.set_position(100.0f, 200.0f);

	for(Uint32 i = 0; i < kParticlePool; ++i){
		particle[i].init((float)(wc_.width() >> 1), (float)(wc_.height() >> 1));
	}

	//SDL_GetMouseState(int* x, int* y);


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
					case SDLK_SPACE: break;
				}
			break;
		}
	}
}

void GameController::update(){

	gm_.fixedTime();

	for(Uint32 i = 0; i < kParticlePool; ++i)
		particle[i].update();

}

void GameController::draw(){
 	ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(wc_.window());
  ImGui::NewFrame();
	SDL_SetRenderDrawColor(wc_.renderer(), 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(wc_.renderer());

	// coll.draw(wc_.renderer());
	// coll2.draw(wc_.renderer());
	// PathWindow(&test);

	for(Uint32 i = 0; i < kParticlePool; ++i)
		particle[i].draw(wc_);

  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(wc_.renderer());
}

void GameController::quit(){
	// coll.release();
	// coll2.release();

	gm_.release();
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
	SDL_DestroyRenderer(wc_.renderer());
	SDL_DestroyWindow(wc_.window());
	IMG_Quit();
	SDL_Quit();
}

Sint8 GameController::loop(){

	srand((unsigned int)time(NULL));

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