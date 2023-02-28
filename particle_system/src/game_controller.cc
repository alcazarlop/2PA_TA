
#include "game_controller.h"

GameController::GameController(){
	isRunning_ = 0;
	sceneChanger_ = 0;
}

GameController::GameController(const GameController& copy){
	isRunning_ = copy.isRunning_;
	sceneChanger_ = copy.sceneChanger_;
	emitter_pool_ = copy.emitter_pool_;
}

GameController::~GameController() { 

}

Sint8 GameController::init(){

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
		SDL_Log("SDL_Init() Failed!: %s\n", SDL_GetError());
		return isRunning_ = -1;
	}

	isRunning_ = GameManager::Instance().init(1024, 680);

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(GameManager::Instance().window());
  ImGui_ImplSDLRenderer_Init(GameManager::Instance().renderer());

  cube_.init();
  cube_.set_position(Vec3(GameManager::Instance().width() / 2.0f, GameManager::Instance().height() / 2.0f, 0.0f));
  cube_.set_scale(Vec3(50.0f, 50.0f, 0.0f));

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
					case SDLK_SPACE: 
						if(sceneChanger_ == 0) 
							sceneChanger_ = 1;
						else
							sceneChanger_ = 0;
					break;
				}
			break;
			case SDL_MOUSEBUTTONDOWN:
				emitter_pool_.isBinded_ = false; 
			break;
		}
	}
}

void GameController::update(){

	switch(sceneChanger_){
		case 0:
			for(Uint32 i = 0; i < emitter_pool_.pool_.size(); ++i)
				emitter_pool_.pool_[i]->update();
		break;
		case 1:
			cube_.set_rotation(Vec3((float)(SDL_GetTicks() * 0.0016f),(float)(SDL_GetTicks() * 0.0016f),(float)(SDL_GetTicks() * 0.0016f)));
		break;
	}

}

void GameController::draw(){
 	ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(GameManager::Instance().window());
  ImGui::NewFrame();
	SDL_SetRenderDrawColor(GameManager::Instance().renderer(), 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(GameManager::Instance().renderer());

	SceneManager(&sceneChanger_, &emitter_pool_);
	switch(sceneChanger_){
		case 0:
			for(Uint32 i = 0; i < emitter_pool_.pool_.size(); ++i){
				emitter_pool_.pool_[i]->draw(GameManager::Instance().renderer());
				EmitterManager(emitter_pool_.pool_[i]);
			}
		break;
		case 1:
			cube_.draw(GameManager::Instance().renderer());
		break;
	}


  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(GameManager::Instance().renderer());
}

void GameController::quit(){

	for(Uint32 i = 0; i < emitter_pool_.pool_.size(); ++i){
		emitter_pool_.pool_[i]->release();
		delete emitter_pool_.pool_[i];
	}

  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
	SDL_DestroyRenderer(GameManager::Instance().renderer());
	SDL_DestroyWindow(GameManager::Instance().window());
	IMG_Quit();
	SDL_Quit();
}

Sint8 GameController::loop(){

	SDL_Event eventHandler;
	srand((unsigned int)time(NULL));

	init();
	while(isRunning_){
		input(&eventHandler);
		update();
		draw();
	}

	quit();
	return isRunning_;
}
