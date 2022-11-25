
#ifndef __PATH_H__
#define __PATH_H__ 1

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <SDL.h>
#include "entity.h"
#include "vector_3.h"
#include "matrix_4.h"

class WindowController;

class Path : public Entity{
public:
	Path();
	Path(const Path& copy);
	virtual ~Path();

	void add_vertices(float* array);
	void add_vertices(float x, float y, float z);
	void add_vertices(const Vec3& vert);
	void add_vertices(Vec3* verts);

	void show_raw_vertices();

	void draw(const WindowController& wc) override;

private:
	std::vector<Vec3> vertices_;

};

#endif