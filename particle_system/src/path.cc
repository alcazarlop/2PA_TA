#include "path.h"

Path::Path(){
	color_ = Vec4(255.0f, 255.0f, 255.0f, 255.0f);
}

Path::Path(const Path& copy){
	position_ = copy.position_;
	rotation_ = copy.rotation_;
	scale_ = copy.scale_;
	color_ = copy.color_;
	vertices_ = copy.vertices_;
}

Path::~Path(){
	Entity::~Entity();
}

void Path::init(){
	switch(rand()%3){
		case 0: loadSquare(); break;
		case 1: loadCircle(); break;
		case 2: loadStar(); break;
		default: loadSquare(); break;
	}
}

void Path::add_vertices(float x, float y, float z){
	vertices_.push_back(Vec3(x, y, z));
}

void Path::add_vertices(const Vec3& vert){
	vertices_.push_back(vert);
}

void Path::loadSquare(){
	add_vertices(-1.0f, -1.0f, 0.0f);
	add_vertices(-1.0f, 1.0f, 0.0f);
	add_vertices(1.0f, 1.0f, 0.0f);
	add_vertices(1.0f, -1.0f, 0.0f);
}

void Path::loadCircle(){
	Uint32 total_points = 20;
	for(Uint32 i = 0; i < total_points; ++i){
		add_vertices(cosf((6.28f / total_points) * i), sinf((6.28f / total_points) * i), 0.0f);
	}
}

void Path::loadStar(){
	Uint32 total_points = 10;
	for(Uint32 i = 0; i < total_points; ++i){
		if(i%2 == 0){
			add_vertices(cosf((6.28f / total_points) * i) * 1.8f, sinf((6.28f / total_points) * i) * 1.8f, 0.0f);
		} else {
			add_vertices(cosf((6.28f / total_points) * i) * 0.9f, sinf((6.28f / total_points) * i) * 0.9f, 0.0f);
		}
	}
}

void Path::set_color(Vec4 color){
	color_ = color;
}

void Path::update() {}

void Path::draw(SDL_Renderer* renderer){
	if(enabled()){
		Mat4 transform = Mat4::Identity();
		transform = Mat4::Translate(position_).Multiply(transform);
		transform = Mat4::Scale(scale_).Multiply(transform);
		transform = Mat4::RotateX(rotation_.x).Multiply(transform);
		transform = Mat4::RotateY(rotation_.y).Multiply(transform);
		transform = Mat4::RotateZ(rotation_.z).Multiply(transform);

		std::vector<Vec3> tr_points;
		for(Uint32 i = 0; i < vertices_.size(); ++i){
			tr_points.push_back(transform.Mat4TransformVec3(vertices_[i]));
		}

		SDL_SetRenderDrawColor(renderer, (Uint8)color_.x, (Uint8)color_.y, (Uint8)color_.z, (Uint8)color_.w);
		for(Uint32 i = 0; i < tr_points.size(); ++i){
			SDL_RenderDrawLineF(renderer, tr_points[i].x, tr_points[i].y,
																				 tr_points[(i + 1) % tr_points.size()].x, 
																				 tr_points[(i + 1) % tr_points.size()].y);
		}
	}
}

std::vector<Vec3> Path::vertices() const {
	return vertices_;
}

Vec4 Path::color() const {
	return color_;
}
