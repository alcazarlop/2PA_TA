
#include <SDL.h>
#include "game_controller.h"

int main(int argc, char** argv){
	
	argc = 0;
	argv = NULL;

	GameController game = GameController();
	return game.loop();
}