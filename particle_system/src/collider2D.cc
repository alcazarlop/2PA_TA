
#include "collider2D.h"
#include <stdio.h>

Collider2D::Collider2D() {
	shape_ = NULL;
	body_ = NULL;
	radius_ = 0.0f;
	vertices_.clear();
}

Collider2D::Collider2D(const Collider2D& copy) {
	shape_ = copy.shape_;
	body_ = copy.body_;
	radius_ = copy.radius_;
	vertices_ = copy.vertices_;
}

Collider2D::~Collider2D() {}

void Collider2D::initCircle(float radius, float mass, cpSpace* space){
	radius_ = radius;
	cpFloat moment = cpMomentForCircle(mass, 0.0f, radius, cpvzero);
	body_ = cpSpaceAddBody(space, cpBodyNew(mass , moment));
	shape_ = cpSpaceAddShape(space, cpCircleShapeNew(body_, radius, cpvzero));
	cpShapeSetFriction(shape_, 0.7f);

	vertices_.push_back(Vec2(-1.0f, -1.0f));
	vertices_.push_back(Vec2(-1.0f, 1.0f));
	vertices_.push_back(Vec2(1.0f, 1.0f));
	vertices_.push_back(Vec2(1.0f, -1.0f));
}

void Collider2D::release(){
	cpShapeFree(shape_);
	cpBodyFree(body_);
}

void Collider2D::addVertices(Vec2 vec){
	vertices_.push_back(vec);
}

void Collider2D::addVertices(float x, float y){
	vertices_.push_back(Vec2(x, y));
}

void Collider2D::set_position(cpVect pos){
	cpBodySetPosition(body_, pos);
}

void Collider2D::set_position(float x, float y){
	cpBodySetPosition(body_, cpv(x, y));
}

cpVect Collider2D::position() const {
	return cpBodyGetPosition(body_);
}

void Collider2D::draw(SDL_Renderer* renderer){
	Mat3 transform = Mat3::Identity();
	transform = Mat3::Translate((float)cpBodyGetPosition(body_).x,(float)cpBodyGetPosition(body_).y).Multiply(transform);
	transform = Mat3::Scale(radius_, radius_).Multiply(transform);

	std::vector<Vec2> tr_points;
	for(Uint32 i = 0; i < vertices_.size(); ++i){
		tr_points.push_back(transform.Mat3TransformVec2(vertices_[i]));
	}

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for(Uint32 i = 0; i < tr_points.size(); ++i){
		SDL_RenderDrawLineF(renderer, tr_points[i].x, tr_points[i].y, 
																	tr_points[(i + 1) % tr_points.size()].x, 
																	tr_points[(i + 1) % tr_points.size()].y);
	}
}