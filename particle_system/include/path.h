
#ifndef __PATH_H__
#define __PATH_H__ 1

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <SDL.h>
#include "entity.h"
#include "vector_3.h"
#include "matrix_4.h"

class Path : public Entity{
public:
	Path();
	Path(const Path& copy);
	~Path();

	void set_position(const Vec3& pos);
	void set_position(float x, float y, float z);

	void set_scale(const Vec3& scale);
	void set_scale(float x, float y, float z);

	void set_rotation(const Vec3& rot);
	void set_rotation(float x, float y, float z);

	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);

	Vec3 position() const;
	Vec3 scale() const;
	Vec3 rotation() const;

	void add_vertices(float* array);
	void add_vertices(float x, float y, float z);
	void add_vertices(const Vec3& vert);
	void add_vertices(Vec3* verts);

	void show_raw_vertices();

	void draw(SDL_Renderer* render);

private:
	Vec3 position_;
	Vec3 rotation_;
	Vec3 scale_;

	std::vector<Vec3> vertices_;

};

#endif