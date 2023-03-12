//Author: Pablo Prieto Rodriguez

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include <SDL.h>
#include "vector_3.h"

class GameManager {
public:	
	~GameManager();

	static GameManager& Instance() {
		static GameManager* instance = new GameManager();
		return *instance;
	}

/** @brief Application's singleton initialization
*
* Initializes the application's singleton 
*
* @return width Application's window width
* @return height Application's window height
*/
	Sint8 init(Uint32 width, Uint32 height);

/** @brief Application's exit
*
* Destroys the application's window and renderer
*
*/
	void quit();

	SDL_Renderer* renderer() const;
	SDL_Window* window() const;

	Uint32 width() const;
	Uint32 height() const;

	void setMouseState();
	int mouseX() const;
	int mouseY() const;


/** @brief Circular collision
*
* Calculates if a circular collision takes place
*
* @return p1 A vec3 that contains first object's position
* @return p2 A vec3 that contains second object's position
* @return r1 A float value that contains first object's radius
* @return r2 A float value that contains second object's radius
*/
	bool CircularCollision(Vec3 p1, Vec3 p2, float r1, float r2);

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