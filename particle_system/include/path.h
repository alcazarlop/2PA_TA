
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

	void loadSquare();
	void loadCircle();
	void loadStar();

	void set_color(SDL_Color color);
	void lerpUnclampedColor(SDL_Color lerp, float time);
	void draw(const WindowController& wc) override;

	std::vector<Vec2> vertices() const;

private:
	std::vector<Vec2> vertices_;
	SDL_Color color_;

};

#endif