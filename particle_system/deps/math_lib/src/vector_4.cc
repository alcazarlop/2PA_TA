#include "vector_4.h"

const Vec4 Vec4::one = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
const Vec4 Vec4::zero = Vec4(0.0f, 0.0f, 0.0f, 0.0f);

Vec4::Vec4() { 
  this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
  this->w = 0.0f;
}

Vec4::Vec4(float x, float y, float z, float w) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

Vec4::Vec4(Vec3 a, float w) {
  this->x = a.x;
  this->y = a.y;
  this->z = a.z;
  this->w = w;
}

Vec4::Vec4(float a) {
  this->x = a;
  this->y = a;
  this->z = a;
  this->w = a;
}

Vec4::Vec4(float* values_array) {
  this->x = values_array[0];
  this->y = values_array[1];
  this->z = values_array[2];
  this->w = values_array[3];
}

Vec4::Vec4(const Vec4& other) {
  this->x = other.x;
  this->y = other.y;
  this->z = other.z;
  this->w = other.w;
}

Vec4::~Vec4() { }
