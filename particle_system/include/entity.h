///@author: Pablo Prieto Rodriguez

#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include <SDL.h>
#include "matrix_4.h"
#include "vector_3.h"

class Entity {
public:
	Entity();
	Entity(const Entity& copy);
	virtual ~Entity();


	virtual void init(Vec3 pos, Vec3 scale) = 0;
	virtual void update() = 0;
	virtual void draw(SDL_Renderer* renderer) = 0;

/** @brief Entity's position setter with vector
*
* Sets the entity's scale with a Vec3
*
* @param scale A vector that contains the entity's coordinates
*/

	void set_position(Vec3 pos);

/** @brief Entity's position setter with values
*
* Sets the entity's X and Y coordinates
* @param x Coordinate value for X axis
* @param y Coordinate value for Y axis
*/

	void set_position(float x, float y, float z);

/** @brief Entity's scale setter with vector
*
* Sets the entity's scale with a Vec3
*
* @param scale A vector that contains the entity's scale value
*/

	void set_scale(Vec3 scale);

/** @brief Entity's scale setter with values
*
* Sets the entity's scale with values
*
* @param x Scale value in the X axis
* @param y Scale value in the Y axis
*/

	void set_scale(float x, float y, float z);

/** @brief Entity's rotation setter
*
* Sets the entity's rotation angle
*
* @param angle The angle's value
*/

	void set_rotation(Vec3 rotation);
	void set_rotation(float x, float y, float z);

/** @brief Entity's position getter
*
* Gets the entity's position
*
* @return Entity's actual position
*/
	Vec3 position() const;

/** @brief Entity's scale getter
*
* Gets the entity's scale
*
* @return Entity's actual scale
*/
	Vec3 scale() const;

/** @brief Entity's rotation getter
*
* Gets the entity's angle rotation
*
* @return Entity's actual angle rotation
*/

	Vec3 rotation() const;

	void set_enable(bool b);
	bool enabled() const;

/** @brief Entity's id getter
*
* Gets the entity's id
*
* @return Entity's id
*/

	Uint32 id() const;

protected:
	bool enabled_;

	Vec3 position_;
	Vec3 scale_;
	Vec3 rotation_;

private:
	Uint32 id_;
	static Uint32 next_id;


};

#endif