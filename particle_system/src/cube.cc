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

void Cube::init(Vec3 pos, Vec3 scale){
	set_position(pos);
	set_scale(scale);
	points_[0] = {-1.0f, -1.0f, 1.0f};
	points_[1] = {1.0f, -1.0f, 1.0f};
	points_[2] = {1.0f, 1.0f, 1.0f};
	points_[3] = {-1.0f, 1.0f, 1.0f};
	points_[4] = {-1.0f, -1.0f, -1.0f};
	points_[5] = {1.0f, -1.0f, -1.0f};
	points_[6] = {1.0f, 1.0f, -1.0f};
	points_[7] = {-1.0f, 1.0f, -1.0f};
}

void Cube::update(){
	set_rotation(Vec3((float)(SDL_GetTicks() * 0.0016f),(float)(SDL_GetTicks() * 0.0016f),(float)(SDL_GetTicks() * 0.0016f)));
}

void Cube::draw(SDL_Renderer* render){

	Mat4 mat_ = mat_.Identity();
	mat_ = Mat4::Translate(position_.x, position_.y, 0.0f).Multiply(mat_);
	mat_ = Mat4::Scale(scale_.x, scale_.y, scale_.z).Multiply(mat_);
	mat_ = Mat4::ProjectionMatrix().Multiply(mat_);
	mat_ = Mat4::Translate(0.0f, 0.0f, position_.z).Multiply(mat_);
	mat_ = Mat4::RotateX(rotation_.x).Multiply(mat_);
	mat_ = Mat4::RotateY(rotation_.y).Multiply(mat_);
	mat_ = Mat4::RotateZ(rotation_.z).Multiply(mat_);

	Vec3 tr_points[8];
	for(int i = 0; i < 8; ++i){
		 tr_points[i] = mat_.Mat4TransformVec3(points_[i]);
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
