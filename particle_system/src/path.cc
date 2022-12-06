
#include "path.h"

Path::Path(){
	color[0] = 0xFF;
	color[1] = 0xFF;
	color[2] = 0xFF;
	vertices_.clear();
}

Path::Path(const Path& copy){
	color[0] = copy.color[0];
	color[1] = copy.color[1];
	color[2] = copy.color[2];
	vertices_ = copy.vertices_;
}

Path::~Path(){
	vertices_.clear();
}

void Path::add_vertices(float x, float y){
	vertices_.push_back(Vec2(x, y));
}

void Path::add_vertices(const Vec2& vert){
	vertices_.push_back(vert);
}

void Path::set_color(Uint8 cr, Uint8 cg, Uint8 cb){
	color[0] = cr;
	color[1] = cg;
	color[2] = cb;
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
			// printf("X[%f] Y[%f] Z[%f]\n", tr_points[i].x, tr_points[i].y, tr_points[i].z);
		}

		SDL_SetRenderDrawColor(wc.renderer(), color[0], color[1], color[2], 0xFF);
		for(Uint32 i = 0; i < tr_points.size(); ++i){
			SDL_RenderDrawLineF(wc.renderer(), tr_points[i].x, tr_points[i].y,
																				 tr_points[(i + 1) % tr_points.size()].x, 
																				 tr_points[(i + 1) % tr_points.size()].y);
		}
	}
}