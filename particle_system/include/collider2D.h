//Author: Manuel Alcazar Lopez
#ifndef __COLLIDER2D_H__
#define __COLLIDER2D_H__ 1

#include <SDL.h>
#include <chipmunk.h>
#include <vector>
#include <math.h>
#include "vector_2.h"
#include "matrix_3.h"

class Collider2D {
public:
	Collider2D();
	Collider2D(const Collider2D& copy);
	~Collider2D();

/** @brief 2D Collider initialization
*
* Initializes all the chipmunks' 2D collider parameters
*
* @param radius Value for the radius_ variable
* @param mass Value used to initialize the body_ variable
* @param space Chipmunk space object used to initialize the body_ and shape_ variables
*/

	void init(float radius, float mass, cpSpace* space);

/** @brief 2D Collider Release
*
* Releases the body_ and shape_ variables
*
*/

	void release();

/** @brief Collider position setter with values
*
* Sets the collider's position with a Chipmunk function,
* given the coordinates values
*
* @param x Coordinates value in the X axis
* @param y Coordinates value in the Y axis
*
*/

	void set_position(float x, float y);

/** @brief Collider position setter with CpVect
*
* Sets the collider's position with a Chipmunk function,
* given a Chipmunk Vector
*
* @param pos Chipmunk vector that contains the new position values
*
*/

	void set_position(cpVect pos);

/** @brief Collider velocity setter
*
* Sets the collider's velocity in each axis
* using chipmunk
*
* @param x Velocity value in the X axis
* @param y Velocity value in the Y axis
*
*/

	void set_velocity(float x, float y);

/** @brief Collider force applier
*
* Applies an impulse to a Collider's body
*
* @param x Impulse value in the X axis
* @param y Impulse value in the Y axis
*
*/

	void apply_force(float x, float y);

/** @brief Collider friction setter
*
* Sets friction value to a Collider's shape
*
* @param value Friction value to set to the collider
*
*/

	void set_friction(float value);

/** @brief Collider mass setter
*
* Sets mass value to a Collider's body
*
* @param value Friction value to set to the collider
*
*/

	void set_mass(float value);

/** @brief Collider position getter
*
* Gets the Collider's current position
*
* @return Collider's actual position
*
*/

	cpVect position() const;

/** @brief Collider's draw
*
* Draws a collider after applying the transformations
* (translate, scale and rotate) with given vertices
*
* @param renderer SDL renderer used for the SLD drawing functions
* @param vertices Vector which contains the vertices to draw
*
*/

	void draw(SDL_Renderer* render, std::vector<Vec2> vertices);

private:
	cpBody* body_;
	cpShape* shape_;
	cpShapeFilter filter_;

	float radius_;

};

#endif