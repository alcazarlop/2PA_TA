
#include "particle.h"

Particle::Particle(){
	velocity_ = Vec2();
	originalPosition_ = Vec2();
	lifeTime_ = 0;
	currentTime_ = 0;
}

Particle::Particle(const Particle& copy){
	velocity_ = copy.velocity_;
	originalPosition_ = copy.originalPosition_;
	lifeTime_ = copy.lifeTime_;
	currentTime_ = copy.currentTime_;
}

Particle::~Particle(){}

void Particle::init(float posx, float posy){
	// velocity_.x = ((5.0f - -5.0f) * ((float)rand() / (float)RAND_MAX)) + -5.0f;
	// velocity_.y = ((-10.0f - -5.0f) * ((float)rand() / (float)RAND_MAX)) + -5.0f;

	float speed = ((5.0f - -5.0f) * ((float)rand() / (float)RAND_MAX)) + -5.0f;
	velocity_.x = cosf(6.28f / (float)(rand()%30) * speed) * 4.0f;
	velocity_.y = sinf(6.28f / (float)(rand()%30) * speed) * 4.0f;

	float scale = (float)(10 + rand()%30);
	set_scale(scale, scale);
	set_position(posx, posy);
	set_rotation((float)(rand()%360));
	originalPosition_ = position();

	lifeTime_ = 100;

	set_color(rand()%256, rand()%256, rand()%256);

	switch(rand()%3){
		case 0: load_square(); break;
		case 1: load_circle(); break;
		case 2: load_star(); break;
	}
}

void Particle::softInit(){
	// velocity_.x = ((5.0f - -5.0f) * ((float)rand() / (float)RAND_MAX)) + -5.0f;
	// velocity_.y = ((-10.0f - -5.0f) * ((float)rand() / (float)RAND_MAX)) + -5.0f;

	float speed = ((5.0f - -5.0f) * ((float)rand() / (float)RAND_MAX)) + -5.0f;
	velocity_.x = cosf(6.28f / (float)(rand()%30) * speed) * 4.0f;
	velocity_.y = sinf(6.28f / (float)(rand()%30) * speed) * 4.0f;

	set_rotation((float)(rand()%360));
	set_position(originalPosition_);

	currentTime_ = 0;
	// lifeTime_ = rand()%100;


	set_color(rand()%256, rand()%256, rand()%256);
}

void Particle::load_square(){
	add_vertices(-0.5f, -0.5f);
	add_vertices(-0.5f, 0.5f);
	add_vertices(0.5f, 0.5f);
	add_vertices(0.5f, -0.5f);
}

void Particle::load_circle(){
	Uint32 total_points = 20;
	for(Uint32 i = 0; i < total_points; ++i){
		add_vertices(cosf((6.28f / total_points) * i), sinf((6.28f / total_points) * i));
	}
}

void Particle::load_star(){
	Vec2 radius = scale();
	set_scale(1.0f, 1.0f);
	Uint32 total_points = 10;
	for(Uint32 i = 0; i < total_points; ++i){
		if(i%2 == 0){
			add_vertices(cosf((6.28f / total_points) * i) * radius.x, sinf((6.28f / total_points) * i) * radius.y);
		} else {
			add_vertices(cosf((6.28f / total_points) * i) * (radius.x * 0.5f), sinf((6.28f / total_points) * i) * (radius.y * 0.5f));
		}
	}
}

void Particle::update(){
	if(currentTime_ < lifeTime_){
		set_position(position() + velocity_);
		currentTime_++;
	} else {
		softInit();
	}
}