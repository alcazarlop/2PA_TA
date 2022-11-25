
#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include "matrix_4.h"
#include "vector_3.h"
#include "window_controller.h"

#define ARRAYSIZE(_ARR) ((int)(sizeof(_ARR) / sizeof(*(_ARR)))) 


class Entity {
public:
	Entity();
	Entity(const Entity& copy);
	virtual ~Entity();

	virtual void draw(const WindowController& wc) = 0;

	void set_position(Vec3 pos);
	void set_position(float x, float y, float z);
	void set_scale(Vec3 scale);
	void set_scale(float x, float y, float z);
	void set_rotation(Vec3 rot);
	void set_rotation(float x, float y, float z);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	Vec3 position() const;
	Vec3 scale() const;
	Vec3 rotation() const;

	void set_enable(bool b);
	bool enabled() const;

protected:
	bool enabled_;

	Vec3 position_;
	Vec3 scale_;
	Vec3 rotation_;
};

#endif