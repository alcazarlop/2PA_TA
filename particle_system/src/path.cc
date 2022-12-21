#include "path.h"

Path::Path(){
	color_ = Vec4(255.0f, 255.0f, 255.0f, 255.0f);
	switch(rand()%3){
		case 0: loadSquare(); break;
		case 1: loadCircle(); break;
		case 2: loadStar(); break;
	}
}

Path::Path(const Path& copy){
	color_ = copy.color_;
	vertices_ = copy.vertices_;
	position_ = copy.position_;
}

Path::~Path(){

}

void Path::add_vertices(float x, float y){
	vertices_.push_back(Vec2(x, y));
}

void Path::add_vertices(const Vec2& vert){
	vertices_.push_back(vert);
}

void Path::loadSquare(){
	add_vertices(-0.5f, -0.5f);
	add_vertices(-0.5f, 0.5f);
	add_vertices(0.5f, 0.5f);
	add_vertices(0.5f, -0.5f);
}

void Path::loadCircle(){
	Uint32 total_points = 20;
	for(Uint32 i = 0; i < total_points; ++i){
		add_vertices(cosf((6.28f / total_points) * i), sinf((6.28f / total_points) * i));
	}
}

void Path::loadStar(){
	Uint32 total_points = 10;
	for(Uint32 i = 0; i < total_points; ++i){
		if(i%2 == 0){
			add_vertices(cosf((6.28f / total_points) * i) * 1.0f, sinf((6.28f / total_points) * i) * 1.0f);
		} else {
			add_vertices(cosf((6.28f / total_points) * i) * 0.5f, sinf((6.28f / total_points) * i) * 0.5f);
		}
	}
}

void Path::set_color(Vec4 color){
	color_ = color;
}

void Path::draw(const WindowController& wc){
	if(enabled()){
		Mat3 transform = Mat3::Identity();
		transform = Mat3::Translate(position_.x, position_.y).Multiply(transform);
		transform = Mat3::Scale(scale_.x, scale_.y).Multiply(transform);
		transform = Mat3::Rotate(rotation_).Multiply(transform);

		std::vector<Vec2> tr_points;
		for(Uint32 i = 0; i < vertices_.size(); ++i){
			tr_points.push_back(transform.Mat3TransformVec2(vertices_[i]));
		}

		SDL_SetRenderDrawColor(wc.renderer(), (Uint8)color_.x, (Uint8)color_.y, (Uint8)color_.z, (Uint8)color_.w);
		for(Uint32 i = 0; i < tr_points.size(); ++i){
			SDL_RenderDrawLineF(wc.renderer(), tr_points[i].x, tr_points[i].y,
																				 tr_points[(i + 1) % tr_points.size()].x, 
																				 tr_points[(i + 1) % tr_points.size()].y);
		}
	}
}

std::vector<Vec2> Path::vertices() const {
	return vertices_;
}

Vec4 Path::color() const {
	return color_;
}
