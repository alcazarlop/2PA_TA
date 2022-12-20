//Author: Pablo Prieto Rodriguez

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

/** @brief Application's Manager Initialization
*
* Initializes all the application manager's parameters for it to start correctly
*
*/

	void init();

/** @brief Application's Gravity set
*
* Sets the gravity used in the application using Chipmunk
*
*/

	void set_gravity(float x, float y);

/** @brief Fixed Time setter
*
* Sets the fixed time used in the application using Chipmunk
*
*/

	void fixedTime();

/** @brief Application's Manager release
*
* Releases the Chipmunk's Space
*
*/
	void release();

/** @brief Application's Start Time Initializations
*
* Gets the application's start time
*
*/

	void startTime();

/** @brief Application's Last Time getter
*
* Gets the application's last time
*
* @return Last time value
*/

	Uint32 lastTime();

/** @brief Application's FPS getter
*
* Gets the application's Frames per Second
*
* @return Application's current FPS
*/

	float getFPS();

/** @brief Application's Space Getter
*
* Gets the application's space used in Chipmunk
*
* @return Application's space
*/

	cpSpace* space() const;
	Uint32 currentTime_;

private:
	GameManager();
	GameManager(const GameManager& copy);

	cpSpace* space_;
	cpFloat stepTime_;
	Uint32 startTime_;

};

#endif