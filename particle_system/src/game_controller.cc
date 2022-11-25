
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

	isRunning_ = wc_.init();

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(wc_.window());
  ImGui_ImplSDLRenderer_Init(wc_.renderer());

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

	for(Uint32 i = 0; i < 24; i+=3)
		test.add_vertices(points[i], points[i + 1], points[i + 2]);
	
	// test.show_raw_vertices();
	test.set_position(100.0f, 100.f, -1.0f);
	test.set_scale(20.0f, 20.0f, 20.0f);

	sp.loadFromFile("../data/melocoton.png", wc_.window());
	sp.set_position(100.0f, 100.0f, 0.0f);

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
		}
	}
}

void GameController::update(){

}

void GameController::draw(){
 ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(wc_.window());
  ImGui::NewFrame();
	SDL_SetRenderDrawColor(wc_.renderer(), 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(wc_.renderer());

	test.draw(wc_);
	ShowImgui(&test);
	// sp.draw(wc_.window());

  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(wc_.renderer());
}

void GameController::quit(){
	sp.release();
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
	SDL_DestroyRenderer(wc_.renderer());
	SDL_DestroyWindow(wc_.window());
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