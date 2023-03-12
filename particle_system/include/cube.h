///@author Manuel Alcázar López

#ifndef __CUBE_H__
#define __CUBE_H__ 1

#include "entity.h"

class Cube : public Entity{

public:
	Cube();
	Cube(const Cube& other);
	virtual ~Cube();

/** @brief Cube's initialization
*
* Initializes all the cube's parameters for it to start correctly
*
* @return pos A vec3 which contains the cube's position
* @return scale which contains the cube's scale
*/
	void init(Vec3 pos, Vec3 scale) override;

/** @brief Cube draw
*
* Drawing of the cube after applying the transformations
* (translate, scale and rotate).
*
*@param renderer SDL renderer object
*/
	void draw(SDL_Renderer* render) override;

/** @brief Cube's update
*
* Updates the cube's rotation animation
*
*/
	void update() override;

private:
	Vec3 points_[8];
};

#endif
