
#ifndef __PATH_H__
#define __PATH_H__ 1

#include <SDL.h>
#include <vector>
#include "entity.h"

class Vec3;
class Mat4;
class WindowController;

class Path : public Entity {
public:
	Path();
	Path(const Path& copy);
	virtual ~Path();

	void add_vertices(float x, float y, float z);
	void add_vertices(const Vec3& vert);

	void set_color(Uint8 cr, Uint8 cg, Uint8 cb, Uint8 ca);
	void draw(const WindowController& wc) override;

private:
	std::vector<Vec3> vertices_;
	Uint8 r, g, b, a;

};

#endif