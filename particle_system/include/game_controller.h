//Author: Manuel Alcazar Lopez
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__ 1

#include <SDL.h>
#include <time.h>
#include "SDL_image.h"
#include "window_controller.h"
#include "game_manager.h"
#include "emitter_pool.h"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "imgui_controller.h"

class GameController {

public:
	GameController();
	GameController(const GameController& copy);
	~GameController();


/** @brief Application's Initialization
*
* Initializes all the application's parameters for it to start correctly
*
* @return Value that determinates that the game is running
*/

	Sint8 init();

/** @brief Game Input
*
* Receives and manages the user's inputs
*
*
* @param e SDL event object to detect an event
*/

	void input(SDL_Event* e);

/** @brief Application's update
*
* Manages the updating of the application's elements variables
*
*/

	void update();

/** @brief Application's draw
*
* Manages the drawing of the application's elements
*
*/

	void draw();

/** @brief Application's quit
*
* Manages the quitting functions to end the application correctly
*
*/

	void quit();

/** @brief Application's loop
*
* Manages the loop of the application, getting the input,
* updating the values and drawing the elements
*
*/

	Sint8 loop();

private:
	Sint8 isRunning_;
	WindowController wc_;
	GameManager& gm_ = GameManager::Instance();

	EmitterPool emitter_pool_;
};

#endif