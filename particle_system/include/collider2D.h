
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

	void set_position(float x, float y);
	void set_position(cpVect pos);
	void set_velocity(float x, float y);

	void apply_force(float x, float y);
	void set_friction(float value);
	void set_mass(float value);

	cpVect position() const;

	void draw(SDL_Renderer* render, std::vector<Vec2> vertices);

private:
	cpBody* body_;
	cpShape* shape_;
	cpShapeFilter filter_;

	float radius_;

};

#endif