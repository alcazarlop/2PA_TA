 
#ifndef __WINDOW_CONTROLLER_H__
#define __WINDOW_CONTROLLER_H__ 1

#include <SDL.h>

class WindowController {
public:
	WindowController();
	WindowController(const WindowController& copy);
	~WindowController();

	Sint8 init();
	void quit();

	SDL_Renderer* renderer() const;
	SDL_Window* window() const;

private:
	SDL_Renderer* renderer_;
	SDL_Window* window_;

};

#endif
