#ifndef __VEC2_H__
#define __VEC2_H__ 1

#include <math.h>
#include "math_utils.h"

class Vec2 {
 public:

  Vec2();
  inline Vec2(float x, float y);
  Vec2(const Vec2& copy);
  ~Vec2();

  Vec2 operator+(const Vec2& other) const;
  Vec2 operator+(float value);
  Vec2& operator+=(const Vec2& other);
  Vec2& operator+=(float value);
  Vec2 operator-(const Vec2& other) const;
  Vec2 operator-(float value) const;
  Vec2 operator-() const;
  Vec2& operator-=(const Vec2& other);
  Vec2& operator-=(float value);
  bool operator==(const Vec2& other) const;
  bool operator!=(const Vec2& other) const;
  void operator=(const Vec2& other);
  void operator=(float value);
  Vec2 operator*(float value) const;
  Vec2& operator*=(float value);
  Vec2 operator/(float value) const;
  Vec2& operator/=(float value);

  float Magnitude() const;
  void Normalize();
  Vec2 Normalized() const;

  void Scale(const Vec2 scale);

  float SqrMagnitude() const;
  static float Distance(const Vec2 a, const Vec2 b);

  static float DotProduct(Vec2 a, Vec2 b);

  static Vec2 Lerp(const Vec2 a, const Vec2 b, float t);
  static Vec2 LerpUnclamped(const Vec2 a, const Vec2 b, float t);

  static const Vec2 up;
  static const Vec2 down;
  static const Vec2 right;
  static const Vec2 left;
  static const Vec2 zero;
  static const Vec2 one;

  float x;
  float y;
};

inline Vec2 Vec2::operator+(const Vec2& other) const {
  return Vec2(this->x + other.x, this->y + other.y);
}

inline Vec2 Vec2::operator+(float value) {
  return Vec2(this->x + value, this->y + value);
}

inline Vec2& Vec2::operator+=(const Vec2& other){
  this->x += other.x;
  this->y += other.y;
  return *this;
}

inline Vec2& Vec2::operator+=(float value){
  this->x += value;
  this->y += value;
  return *this;
}

inline Vec2 Vec2::operator-(const Vec2& other) const {
  return Vec2(this->x - other.x, this->y - other.y);
}

inline Vec2 Vec2::operator-(float value) const {
  return Vec2(this->x - value, this->y - value);
}

inline Vec2 Vec2::operator-() const {
  Vec2 result(*this);
  result.x = - result.x;
  result.y = - result.y;
	return result;
}

inline Vec2& Vec2::operator-=(const Vec2& other) {
  this->x -= other.x;
  this->y -= other.y;
  return *this;
}

inline Vec2& Vec2::operator-=(float value){
  this->x -= value;
  this->y -= value;
  return *this;
}

inline bool Vec2::operator==(const Vec2& value) const {
  return (this->x == value.x && this->y == value.y);
}

inline bool Vec2::operator!=(const Vec2& value) const {
  return (this->x != value.x || this->y != value.y);
}

inline void Vec2::operator=(const Vec2& other) {
  this->x = other.x;
  this->y = other.y;
}

inline void Vec2::operator=(float value) {
  this->x = value;
  this->y = value;
}

inline Vec2 Vec2::operator*(float value) const {
	return Vec2(this->x * value, this->y * value);
}

inline Vec2& Vec2::operator*=(float value) {  
  this->x *= value;
  this->y *= value;
  return *this;
}

inline Vec2 Vec2::operator/(float value) const {
  float inverse = 1.0f / value;
	return Vec2(this->x * inverse, this->y * inverse);
}

inline Vec2& Vec2::operator/=(float value) {
	float inverse = 1.0f / value;
  this->x *= inverse;
  this->y *= inverse;
  return *this;
}

inline float Vec2::Magnitude() const {
  return sqrtf(this->x * this->x + this->y * this->y);
}

inline void Vec2::Normalize() { 
  float inverse = 1.0f / Magnitude();
  *this *= inverse;
}

inline Vec2 Vec2::Normalized() const {
	float inverse = 1.0f / Magnitude();
  return Vec2(this->x * inverse, this->y * inverse);
}

inline void Vec2::Scale(const Vec2 scale){
  Vec2(this->x *= scale.x, this->y *= scale.y);
}

inline float Vec2::SqrMagnitude() const {
  return this->x * this->x + this->y * this->y;
}

inline float Vec2::Distance(const Vec2 a, const Vec2 b) {
  return (a - b).Magnitude();
}

inline Vec2 Vec2::Lerp(const Vec2 a, const Vec2 b, float t) {
  t = MathUtils::Clamp(t, 0.0f, 1.0f);
	return Vec2(LerpUnclamped(a, b, t));
}

inline Vec2 Vec2::LerpUnclamped(const Vec2 a, const Vec2 b, float t) {
	return Vec2((a.x + t) * (b.x - a.x), (a.y + t) * (b.y - a.y));
}

inline float Vec2::DotProduct(Vec2 a, Vec2 b) {
	return (a.x * b.x + a.y * b.y);
}

#endif 
