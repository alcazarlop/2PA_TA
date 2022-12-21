//author Manuel Alcázar López

#ifndef __CUBE_H__
#define __CUBE_H__ 1

#include <SDL.h>
#include "vector_3.h"
#include "matrix_4.h"

class Cube {

public:
	Cube();
	Cube(const Cube& other);
	virtual ~Cube();

	void init();
	void transform();
	void draw(SDL_Renderer* render);

	Vec3 position() const;
	Vec3 rotation() const;
	Vec3 scale() const;

	void set_position(const Vec3& pos);
	void set_rotation(const Vec3& rot);
	void set_scale(const Vec3& scale);

private:
	Vec3 position_;
	Vec3 scale_;
	Vec3 rotation_;

	Mat4 mat_;
	Vec3 points_[8];
};

#endif