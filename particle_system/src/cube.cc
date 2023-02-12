#include "cube.h"

Cube::Cube(){}

Cube::Cube(const Cube& other){
	position_ = other.position_;
	rotation_ = other.rotation_;
	scale_ = other.scale_;
	for(int i = 0; i < 8; ++i)
		points_[i] = other.points_[i];
}

Cube::~Cube(){}

void Cube::init(){
	points_[0] = {-1.0f, -1.0f, 1.0f};
	points_[1] = {1.0f, -1.0f, 1.0f};
	points_[2] = {1.0f, 1.0f, 1.0f};
	points_[3] = {-1.0f, 1.0f, 1.0f};
	points_[4] = {-1.0f, -1.0f, -1.0f};
	points_[5] = {1.0f, -1.0f, -1.0f};
	points_[6] = {1.0f, 1.0f, -1.0f};
	points_[7] = {-1.0f, 1.0f, -1.0f};
}

void Cube::draw(SDL_Renderer* render){

	Mat4 transform = Mat4::GetTransform(position_, scale_, rotation_.x, rotation_.y, rotation_.z);

	Vec3 tr_points[8];
	for(int i = 0; i < 8; ++i){
		 tr_points[i] = transform.Mat4TransformVec3(points_[i]);
	}

	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

	for(int i = 0; i < 4; ++i){
		SDL_RenderDrawLineF(render, tr_points[i].x, tr_points[i].y,
																tr_points[(i + 1) % 4].x, tr_points[(i + 1) % 4].y);
		SDL_RenderDrawLineF(render, tr_points[i].x, tr_points[i].y,
																tr_points[(i + 4)].x, tr_points[(i + 4)].y);
		SDL_RenderDrawLineF(render, tr_points[(i + 4)].x, tr_points[(i + 4)].y,
																tr_points[((i + 1) % 4) + 4].x, tr_points[((i + 1) % 4) + 4].y);
	}
}
