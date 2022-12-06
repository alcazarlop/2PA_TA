 
#ifndef __WINDOW_CONTROLLER_H__
#define __WINDOW_CONTROLLER_H__ 1

#include <SDL.h>

class WindowController {
public:
	WindowController();
	WindowController(const WindowController& copy);
	~WindowController();

	Sint8 init(Uint32 width, Uint32 height);
	void quit();

	SDL_Renderer* renderer() const;
	SDL_Window* window() const;

	Uint32 width() const;
	Uint32 height() const;

private:
	SDL_Renderer* renderer_;
	SDL_Window* window_;

	Uint32 width_;
	Uint32 height_;

};

#endif
