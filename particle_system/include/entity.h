//Author: Pablo Prieto Rodriguez
#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include "matrix_3.h"
#include "vector_2.h"
#include "window_controller.h"

class Entity {
public:
	Entity();
	Entity(const Entity& copy);
	virtual ~Entity();

	virtual void draw(const WindowController& wc) = 0;

/** @brief Entity's position setter with vector
*
* Sets the entity's scale with a Vec2
*
* @param scale A vector that contains the entity's coordinates
*/

	void set_position(Vec2 pos);

/** @brief Entity's position setter with values
*
* Sets the entity's X and Y coordinates
* @param x Coordinate value for X axis
* @param y Coordinate value for Y axis
*/

	void set_position(float x, float y);

/** @brief Entity's scale setter with vector
*
* Sets the entity's scale with a Vec2
*
* @param scale A vector that contains the entity's scale value
*/

	void set_scale(Vec2 scale);

/** @brief Entity's scale setter with values
*
* Sets the entity's scale with values
*
* @param x Scale value in the X axis
* @param y Scale value in the Y axis
*/

	void set_scale(float x, float y);

/** @brief Entity's rotation setter
*
* Sets the entity's rotation angle
*
* @param angle The angle's value
*/

	void set_rotation(float angle);

/** @brief Entity's position getter
*
* Gets the entity's position
*
* @return Entity's actual position
*/
	Vec2 position() const;

/** @brief Entity's scale getter
*
* Gets the entity's scale
*
* @return Entity's actual scale
*/
	Vec2 scale() const;

/** @brief Entity's rotation getter
*
* Gets the entity's angle rotation
*
* @return Entity's actual angle rotation
*/

	float rotation() const;

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

	Vec2 position_;
	Vec2 scale_;
	float rotation_;

private:
	Uint32 id_;
	static Uint32 next_id;


};

#endif