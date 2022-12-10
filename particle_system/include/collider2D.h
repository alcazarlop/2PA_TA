
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

	void init(float radius, float mass, cpSpace* space);
	void release();

	void loadSquare();
	void loadCircle();
	void loadStar();

	void add_vertices(Vec2 vec);
	void add_vertices(float x, float y);

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