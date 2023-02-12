
#include "entity.h"

Uint32 Entity::next_id = 0;

Entity::Entity(){
	enabled_ = true;
	position_ = Vec3();
	scale_ = Vec3();
	rotation_ = Vec3();
	id_ = Entity::next_id;
	Entity::next_id++;
}

Entity::Entity(const Entity& copy){
	enabled_ = copy.enabled_;
	position_ = copy.position_;
	scale_ = copy.scale_;
	rotation_ = copy.rotation_;
	id_ = Entity::next_id;
	Entity::next_id++;
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

void Entity::set_rotation(Vec3 rotation){
	rotation_ = rotation;
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


Uint32 Entity::id() const {
	return id_;
}