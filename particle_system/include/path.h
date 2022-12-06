
#ifndef __PATH_H__
#define __PATH_H__ 1

#include <SDL.h>
#include <vector>
#include "entity.h"

class Vec2;
class Mat3;
class WindowController;

class Path : public Entity {
public:
	Path();
	Path(const Path& copy);
	virtual ~Path();

	void add_vertices(float x, float y);
	void add_vertices(const Vec2& vert);

	void set_color(Uint8 cr, Uint8 cg, Uint8 cb);
	void draw(const WindowController& wc) override;

private:
	std::vector<Vec2> vertices_;
	Uint8 color[3];

};

#endif