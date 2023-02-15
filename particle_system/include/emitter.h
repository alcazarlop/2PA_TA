//Author: Manuel Alcazar Lopez
#ifndef __EMITTER_H__
#define __EMITTER_H__ 1

#include <SDL.h>
#include <vector>
#include "entity.h"
#include "sprite.h"
#include "path.h"
#include "game_manager.h"

class Emitter {
public:
	Emitter();
	Emitter(const Emitter& copy);
	~Emitter();

	void init(SDL_Renderer* renderer);
	void add(int num);
	void update();
	void draw(SDL_Renderer* renderer);
	void release();

private:
	Sprite* sprite_;
	std::vector<Entity*> pool_;


};

#endif
