///@author: Pablo Prieto Rodriguez

#ifndef __PATH_H__
#define __PATH_H__ 1

#include <SDL.h>
#include <vector>
#include "vector_4.h"
#include "entity.h"

class Vec3;
class Vec4;
class Mat4;

class Path : public Entity {
public:
	Path();
	Path(const Path& copy);
	virtual ~Path();

	void init(Vec3 pos, Vec3 scale) override;

/** @brief Path add vertices with values
*
* Adds a new vertex with values
*
* @param x Coordinate value for X axis
* @param x Coordinate value for Y axis
*/

	void add_vertices(float x, float y, float z);

/** @brief Path add vertices with a vector
*
* Adds a new vertex with a vector
*
* @param vert Coordinates values for X and Y axis
*/

	void add_vertices(const Vec3& vert);

/** @brief Square shape loader
*
* Adds 4 vertices to create a square
*
*/

	void loadSquare();

/** @brief Circle shape loader
*
* Adds 20 vertices to create a circle
*
*/

	void loadCircle();

/** @brief Star shape loader
*
* Adds 10 vertices to create a star
*
*/

	void loadStar();

	void set_color(Vec4 color);

/** @brief Path Draw
*
* Drawing of figures after applying the transformations
* (translate, scale and rotate) using the entity's vertices_
* variable
*
@param renderer SDL renderer object
*/

	void draw(SDL_Renderer* renderer) override;

	std::vector<Vec3> vertices() const;

	Vec4 color() const;
	void update() override;

private:
	std::vector<Vec3> vertices_;
	Vec4 color_;

};

#endif