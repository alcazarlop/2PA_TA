
#include "entity.h"

Entity::Entity(){
	enabled_ = true;
}

Entity::Entity(const Entity& copy){
	enabled_ = copy.enabled_;
}

Entity::~Entity() {}

void Entity::set_enable(bool b){
	enabled_ = b;
}

bool Entity::enabled() const {
	return enabled_;
}