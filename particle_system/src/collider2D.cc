
#include "collider2D.h"

Collider2D::Collider2D() {
	shape_ = NULL;
	body_ = NULL;
	radius_ = 0.0f;
}

Collider2D::Collider2D(const Collider2D& copy) {
	shape_ = copy.shape_;
	body_ = copy.body_;
	radius_ = copy.radius_;
}

Collider2D::~Collider2D() {}

void Collider2D::init(float radius, float mass, cpSpace* space){
	radius_ = radius;
	cpFloat moment = cpMomentForCircle(mass, 0.0f, radius, cpvzero);
	body_ = cpSpaceAddBody(space, cpBodyNew(mass , moment));
	shape_ = cpSpaceAddShape(space, cpCircleShapeNew(body_, radius, cpvzero));
	cpShapeSetFriction(shape_, 0.7f);
	cpShapeSetFilter(shape_, filter_);
}

void Collider2D::release(){
	if(NULL != shape_) cpShapeFree(shape_);
	if(NULL != body_) cpBodyFree(body_);
}

void Collider2D::set_position(cpVect pos){
	cpBodySetPosition(body_, pos);
}

void Collider2D::set_position(float x, float y){
	cpBodySetPosition(body_, cpv(x, y));
}

void Collider2D::set_velocity(float x, float y){
	cpBodySetVelocity(body_, cpv(x, y));
}

void Collider2D::apply_force(float x, float y){
	cpBodyApplyImpulseAtWorldPoint(body_, cpv(x, y), position());
}


void Collider2D::set_friction(float value){
	cpShapeSetFriction(shape_, (cpFloat)value);
}

void Collider2D::set_mass(float value){
	cpBodySetMass(body_, (cpFloat)value);
}

cpVect Collider2D::position() const {
	return cpBodyGetPosition(body_);
}

void Collider2D::draw(SDL_Renderer* renderer, std::vector<Vec2> vertices){
	Mat3 transform = Mat3::Identity();
	transform = Mat3::Translate((float)cpBodyGetPosition(body_).x,(float)cpBodyGetPosition(body_).y).Multiply(transform);
	transform = Mat3::Scale(radius_, radius_).Multiply(transform);

	std::vector<Vec2> tr_points;
	for(Uint32 i = 0; i < vertices.size(); ++i){
		tr_points.push_back(transform.Mat3TransformVec2(vertices[i]));
	}

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for(Uint32 i = 0; i < tr_points.size(); ++i){
		SDL_RenderDrawLineF(renderer, tr_points[i].x, tr_points[i].y, 
																	tr_points[(i + 1) % tr_points.size()].x, 
																	tr_points[(i + 1) % tr_points.size()].y);
	}
}