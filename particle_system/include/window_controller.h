//Author: Manuel Alcazar Lopez
#ifndef __WINDOW_CONTROLLER_H__
#define __WINDOW_CONTROLLER_H__ 1

#include <SDL.h>

class WindowController {
public:
	WindowController();
	WindowController(const WindowController& copy);
	~WindowController();

/** @brief Application's window initialization
*
* Initializes all the needed parameters to start the
* application's window correctly using SDL functions
*
* @return Value that determinates that the game is running
* @param width Int value that corresponds with the window's width
* @param height Int value that corresponds with the window's height
*/

	Sint8 init(Uint32 width, Uint32 height);

/** @brief  Window destroy
*
* Manages the destruction of the WindowController's window
*
*/

	void quit();

/** @brief Window Renderer getter
*
* Gets the sdl renderer object from WindowController
*
* @return The WindowController's sdl renderer
*/

	SDL_Renderer* renderer() const;

/** @brief Window getter
*
* Gets the sdl window object from WindowController
*
* @return The WindowController's sdl window object
*/

	SDL_Window* window() const;

/** @brief Window width getter
*
* Gets the Window width
*
* @return Window width value
*/

	Uint32 width() const;

/** @brief Window height getter
*
* Gets the Window height
*
* @return Window height value
*/

	Uint32 height() const;

private:
	SDL_Renderer* renderer_;
	SDL_Window* window_;

	Uint32 width_;
	Uint32 height_;

};

#endif
