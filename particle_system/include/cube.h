///@author Manuel Alcázar López

#ifndef __CUBE_H__
#define __CUBE_H__ 1

#include "entity.h"

// GUSTAVO: Why is this not an Entity?? Why is functionality 
// being re-implemented and re-implemented?
class Cube : public Entity{

public:
	Cube();
	Cube(const Cube& other);
	virtual ~Cube();

	void init() override;
	void draw(SDL_Renderer* render) override;
	void update() override;

private:
	Vec3 points_[8];
};

#endif
