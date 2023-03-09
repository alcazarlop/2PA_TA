//Author: Pablo Prieto Rodriguez

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include <SDL.h>

class GameManager {
public:	
	~GameManager();

	static GameManager& Instance() {
		static GameManager* instance = new GameManager();
		return *instance;
	}

	Sint8 init(Uint32 width, Uint32 height);
	void quit();

	SDL_Renderer* renderer() const;
	SDL_Window* window() const;

	Uint32 width() const;
	Uint32 height() const;

	void setMouseState();
	int mouseX() const;
	int mouseY() const;

	bool BoxCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

private:
	GameManager();
	GameManager(const GameManager& copy);

	SDL_Renderer* renderer_;
	SDL_Window* window_;

	Uint32 width_;
	Uint32 height_;

	int mouseX_;
	int mouseY_;
	
};

#endif