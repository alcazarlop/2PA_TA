
#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#define ARRAYSIZE(_ARR) ((int)(sizeof(_ARR) / sizeof(*(_ARR)))) 

class Entity {
public:
	Entity();
	Entity(const Entity& copy);
	~Entity();

	void set_enable(bool b);
	bool enabled() const;

private:
	bool enabled_;

};

#endif