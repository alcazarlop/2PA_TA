#ifndef __VEC4_H__
#define __VEC4_H__ 1

#include <math.h>
#include "vector_3.h"
#include "math_utils.h"

class Vec4 {
public:

	Vec4();
	Vec4(float x, float y, float z, float w);
	Vec4(Vec3 a, float w);
	Vec4(float a);
	Vec4(float* values_array);
	Vec4(const Vec4& other);
	~Vec4();
	
	Vec4 operator+(const Vec4& other) const;
	Vec4 operator+(float value) const;
	void operator+=(const Vec4& other);
	void operator+=(float value);
	Vec4 operator-(const Vec4& other) const;
	Vec4 operator-(float value) const;
	void operator-=(const Vec4& other);
	void operator-=(float value);

	Vec4 operator*(float value) const;
	void operator*=(float value);
	Vec4 operator/(float value) const;
	void operator/=(float value);
	bool operator==(const Vec4& other);
	bool operator!=(const Vec4& other);
	void operator=(const Vec4& other);

	float Magnitude() const;
	void Normalize();
	Vec4 Normalized() const;
	void Scale(Vec4 scale);
	float SqrMagnitude() const;

	static float Distance(const Vec4& a, const Vec4& b);
	static float DotProduct(Vec4 a, Vec4 b);
	static Vec4 Lerp(const Vec4& a, const Vec4& b, float t);	

	static const Vec4 one;
	static const Vec4 zero;

	float x;
	float y;
	float z;
	float w;

};


inline float Vec4::Magnitude() const{
	return sqrtf(SqrMagnitude());
}

inline void Vec4::Normalize() {	
	float inverse = 1.0f / Magnitude();
	*this *= inverse;
}

inline Vec4 Vec4::Normalized() const {
	float inverse = 1.0f / Magnitude();
	return Vec4(this->x * inverse, this->y * inverse, this->z * inverse, this->w * inverse);
}

inline void Vec4::Scale(Vec4 scale) {	
	Vec4(this->x *= scale.x, this->y *= scale.y, this->z *= scale.z, this->w *= scale.w);
}

inline float Vec4::SqrMagnitude() const {
	return (x * x + y * y + z * z + w * w);
}

inline float Vec4::Distance(const Vec4& a, const Vec4& b) {
	return (a - b).Magnitude();
}

inline float Vec4::DotProduct(Vec4 a, Vec4 b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

inline Vec4 Vec4::Lerp(const Vec4& a, const Vec4& b, float t) {	
	t = MathUtils::Clamp(t, 0.0f, 1.0f);
	return Vec4((a.x + t) * (b.x - a.x), (a.y + t) * (b.y - a.y), (a.z + t) * (b.z - a.z), (a.w + t) * (b.w - a.w));
}

inline Vec4 Vec4::operator+(const Vec4& other) const{
	return Vec4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

inline Vec4 Vec4::operator+(float value) const{
	return Vec4(this->x + value, this->y + value, this->z + value, this->w + value);
}

inline void Vec4::operator+=(const Vec4& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
}

inline void Vec4::operator+=(float value) {
	this->x += value;
	this->y += value;
	this->z += value;
	this->w += value;
}

inline Vec4 Vec4::operator-(const Vec4& other) const{
	return Vec4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

inline Vec4 Vec4::operator-(float value) const{
	return Vec4(this->x - value, this->y - value, this->z - value, this->w - value);
}

inline void Vec4::operator-=(const Vec4& other) {	
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
}

inline void Vec4::operator-=(float value) {
	this->x -= value;
	this->y -= value;
	this->z -= value;
	this->w -= value;
}

inline Vec4 Vec4::operator*(float value) const{
	return Vec4(this->x * value, this->y * value, this->z * value, this->w * value);
}

inline void Vec4::operator*=(float value) {
	this->x *= value;
	this->y *= value;
	this->z *= value;
	this->w *= value;
}

inline Vec4 Vec4::operator/(float value) const{
	float inverse = 1.0f / value;
	return Vec4(this->x * inverse, this->y * inverse, this->z * inverse, this->w * inverse);
}

inline void Vec4::operator/=(float value) {
	float inverse = 1.0f / value;
	this->x *= inverse;
	this->y *= inverse;
	this->z *= inverse;
	this->w *= inverse;
}

inline bool Vec4::operator==(const Vec4& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
}
inline bool Vec4::operator!=(const Vec4& other) {
	return (this->x != other.x || this->y != other.y || this->z != other.z || this->w != other.w);
}
inline void Vec4::operator=(const Vec4& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
}

#endif 
