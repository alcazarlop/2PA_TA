
#include "entity.h"

Entity::Entity(){
	enabled_ = true;
	position_ = Vec3();
	scale_ = Vec3();
	rotation_ = Vec3();
}

Entity::Entity(const Entity& copy){
	enabled_ = copy.enabled_;
	position_ = copy.position_;
	scale_ = copy.scale_;
	rotation_ = copy.rotation_;
}

Entity::~Entity() {}

void Entity::set_enable(bool b){
	enabled_ = b;
}

bool Entity::enabled() const {
	return enabled_;
}

void Entity::set_position(Vec3 pos){
	position_ = pos;
}

void Entity::set_position(float x, float y, float z){
	position_.x = x;
	position_.y = y;
	position_.z = z;
}

void Entity::set_scale(Vec3 scale){
	scale_ = scale;
}

void Entity::set_scale(float x, float y, float z){
	scale_.x = x;
	scale_.y = y;
	scale_.z = z;
}

void Entity::set_rotation(Vec3 rot){
	rotation_ = rot;
}

void Entity::set_rotation(float x, float y, float z){
	rotation_.x = x;
	rotation_.y = y;
	rotation_.z = z;
}

void Entity::rotateX(float radians){
	rotation_.x = radians;
}

void Entity::rotateY(float radians){
	rotation_.y = radians;
}

void Entity::rotateZ(float radians){
	rotation_.z = radians;
}

Vec3 Entity::position() const {
	return position_;
}

Vec3 Entity::scale() const {
	return scale_;
}

Vec3 Entity::rotation() const {
	return rotation_;
}