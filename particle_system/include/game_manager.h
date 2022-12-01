#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include <SDL.h>
#include <chipmunk.h>

class GameManager {
public:	
	~GameManager();

	static GameManager& Instance() {
		static GameManager* instance = new GameManager();
		return *instance;
	}

	void init();
	void set_gravity(float x, float y);
	void fixedTime();
	void release();

	cpSpace* space() const;

private:
	GameManager();
	GameManager(const GameManager& copy);

	cpSpace* space_;
	cpFloat stepTime_;

};

#endif