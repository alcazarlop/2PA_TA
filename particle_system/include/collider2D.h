
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

	void initCircle(float radius, float mass, cpSpace* space);
	void release();

	void addVertices(Vec2 vec);
	void addVertices(float x, float y);

	void set_position(float x, float y);
	void set_position(cpVect pos);

	cpVect position() const;

	void draw(SDL_Renderer* render);

private:
	cpBody* body_;
	cpShape* shape_;

	float radius_;
	std::vector<Vec2> vertices_;

};

#endif