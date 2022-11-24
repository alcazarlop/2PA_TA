
#include "path.h"
#include "matrix_3.h"

Path::Path(){
	position_ = Vec3();
	scale_ = Vec3();
	rotation_ = Vec3();
	vertices_.clear();
}

Path::Path(const Path& copy){
	position_ = copy.position_;
	scale_ = copy.scale_;
	rotation_ = copy.rotation_;
}

Path::~Path(){
	vertices_.clear();
}

void Path::set_position(const Vec3& pos){
	position_ = pos;
}

void Path::set_position(float x, float y, float z){
	position_.x = x;
	position_.y = y;
	position_.z = z;
}

void Path::set_scale(const Vec3& scale){
	scale_ = scale;
}

void Path::set_scale(float x, float y, float z){
	scale_.x = x;
	scale_.y = y;
	scale_.z = z;
}

void Path::set_rotation(const Vec3& rotation){
	rotation_ = rotation;
}

void Path::set_rotation(float x, float y, float z){
	rotation_.x = x;
	rotation_.y = y;
	rotation_.z = z;
}

void Path::rotateX(float x){
	rotation_.x = x;
}

void Path::rotateY(float y){
	rotation_.y = y;
}

void Path::rotateZ(float z){
	rotation_.z = z;
}

Vec3 Path::position() const {
	return position_;
}

Vec3 Path::scale() const {
	return scale_;
}

Vec3 Path::rotation() const {
	return rotation_;
}

void Path::add_vertices(float* array){
	assert(array != NULL || ARRAYSIZE(array) % 3 == 0 || array != nullptr);
	for(Uint32 i = 0; i < ARRAYSIZE(array); ++i)
		vertices_.push_back(array[i]);
}

void Path::add_vertices(float x, float y, float z){
	Vec3 temp = Vec3(x, y, z);
	vertices_.push_back(temp);
}

void Path::add_vertices(const Vec3& vert){
	vertices_.push_back(vert);
}

void Path::add_vertices(Vec3* vert){
	assert(vert != NULL || vert != nullptr);
	for(Uint32 i = 0; i < ARRAYSIZE(vert); ++i)
		vertices_.push_back(vert[i]);
}

void Path::show_raw_vertices(){
	for(Uint32 i = 0; i < vertices_.size(); ++i)
		printf("X[%f] Y[%f] Z[%f]\n", vertices_[i].x, vertices_[i].y, vertices_[i].z);
}

void Path::draw(SDL_Renderer* render){
	if(enabled()){



	}
}