
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__ 1

#include <SDL.h>
#include "SDL_image.h"
#include "window_controller.h"
#include "path.h"
#include "sprite.h"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "imgui_controller.h"

class GameController {

public:
	GameController();
	GameController(const GameController& copy);
	~GameController();

	Sint8 init();
	void input(SDL_Event* e);
	void update();
	void draw();
	void quit();

	Sint8 loop();

private:
	Sint8 isRunning_;
	WindowController wc_;

	Path test;
	Sprite sp;

};

#endif