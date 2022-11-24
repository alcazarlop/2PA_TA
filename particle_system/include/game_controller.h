
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__ 1

#include <SDL.h>
#include "SDL_image.h"
#include "path.h"
#include "sprite.h"

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
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	Path test;
	Sprite sp;

};

#endif