
#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include "matrix_3.h"
#include "vector_2.h"
#include "window_controller.h"

#define ARRAYSIZE(_ARR) ((int)(sizeof(_ARR) / sizeof(*(_ARR)))) 


class Entity {
public:
	Entity();
	Entity(const Entity& copy);
	virtual ~Entity();

	virtual void draw(const WindowController& wc) = 0;

	void set_position(Vec2 pos);
	void set_position(float x, float y);
	void set_scale(Vec2 scale);
	void set_scale(float x, float y);
	void set_rotation(float angle);

	Vec2 position() const;
	Vec2 scale() const;
	float rotation() const;

	void set_enable(bool b);
	bool enabled() const;

	Uint32 id() const;

protected:
	bool enabled_;

	Vec2 position_;
	Vec2 scale_;
	float rotation_;

private:
	Uint32 id_;
	static Uint32 next_id;


};

#endif