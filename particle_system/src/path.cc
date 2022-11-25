
#include "path.h"
#include "matrix_3.h"

Path::Path(){
	vertices_.clear();
}

Path::Path(const Path& copy){
	vertices_ = copy.vertices_;
}

Path::~Path(){
	vertices_.clear();
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

void Path::draw(const WindowController& wc){
	if(enabled()){
		Mat4 transform = Mat4::Identity();
		transform = Mat4::Translate(position_.x, position_.y, 0.0f).Multiply(transform);
		transform = Mat4::Scale(scale_).Multiply(transform);
		transform = Mat4::ProjectionMatrix().Multiply(transform);
		transform = Mat4::Translate(0.0f, 0.0f, position_.z).Multiply(transform);
		transform = Mat4::RotateX(rotation_.x).Multiply(transform);
		transform = Mat4::RotateY(rotation_.y).Multiply(transform);
		transform = Mat4::RotateZ(rotation_.z).Multiply(transform);

		Vec3 tr_points[8];
		for(int i = 0; i < 8; ++i){
			tr_points[i] = transform.Mat4TransformVec3(vertices_[i]);
			// printf("X[%f] Y[%f] Z[%f]\n", tr_points[i].x, tr_points[i].y, tr_points[i].z);
		}

		SDL_SetRenderDrawColor(wc.renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		for(int i = 0; i < 4; ++i){
			SDL_RenderDrawLineF(wc.renderer(), tr_points[i].x, tr_points[i].y,
																				 tr_points[(i + 1) % 4].x, tr_points[(i + 1) % 4].y);
			SDL_RenderDrawLineF(wc.renderer(), tr_points[i].x, tr_points[i].y,
																				 tr_points[(i + 4)].x, tr_points[(i + 4)].y);
			SDL_RenderDrawLineF(wc.renderer(), tr_points[(i + 4)].x, tr_points[(i + 4)].y,
																				 tr_points[((i + 1) % 4) + 4].x, tr_points[((i + 1) % 4) + 4].y);
		}
	}
}