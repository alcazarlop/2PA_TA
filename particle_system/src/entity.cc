
#include "entity.h"

Uint32 Entity::next_id = 0;

Entity::Entity(){
	enabled_ = true;
	position_ = Vec2();
	scale_ = Vec2();
	rotation_ = 0.0f;
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

void Entity::set_position(Vec2 pos){
	position_ = pos;
}

void Entity::set_position(float x, float y){
	position_.x = x;
	position_.y = y;
}

void Entity::set_scale(Vec2 scale){
	scale_ = scale;
}

void Entity::set_scale(float x, float y){
	scale_.x = x;
	scale_.y = y;
}

void Entity::set_rotation(float angle){
	rotation_ = angle;
}

Vec2 Entity::position() const {
	return position_;
}

Vec2 Entity::scale() const {
	return scale_;
}

float Entity::rotation() const {
	return rotation_;
}

Uint32 Entity::id() const {
	return id_;
}