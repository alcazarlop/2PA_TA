
#include "path.h"

Path::Path(){
	color_.r = 0xFF;
	color_.g = 0xFF;
	color_.b = 0xFF;
	color_.a = 0xFF;
	vertices_.clear();
}

Path::Path(const Path& copy){
	color_.r = copy.color_.r;
	color_.g = copy.color_.g;
	color_.b = copy.color_.b;
	color_.a = copy.color_.a;
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

void Path::set_color(SDL_Color color){
	color_.r = color.r;
	color_.g = color.g;
	color_.b = color.b;
	color_.a = color.a;
}

void Path::lerpUnclampedColor(SDL_Color lerp, float time){
	SDL_Color final_color;
	final_color.r = (Uint8)(color_.r + (lerp.r - color_.r) * time);
	final_color.g = (Uint8)(color_.g + (lerp.g - color_.g) * time);
	final_color.b = (Uint8)(color_.b + (lerp.b - color_.b) * time);
	final_color.a = (Uint8)(color_.a + (lerp.a - color_.a) * time);
	color_ = final_color;
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

		SDL_SetRenderDrawColor(wc.renderer(), color_.r, color_.g, color_.b, color_.a);
		for(Uint32 i = 0; i < tr_points.size(); ++i){
			SDL_RenderDrawLineF(wc.renderer(), tr_points[i].x, tr_points[i].y,
																				 tr_points[(i + 1) % tr_points.size()].x, 
																				 tr_points[(i + 1) % tr_points.size()].y);
		}
	}
}