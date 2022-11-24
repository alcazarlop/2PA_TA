#ifndef __VEC3_H__
#define __VEC3_H__ 1

#include "math_utils.h"
#include <math.h>

class Vec3 {

public:
	Vec3();
	Vec3(float value);
	Vec3(float x, float y, float z);
	Vec3(float* values_array);
	Vec3(const Vec3& other);
	~Vec3();

	Vec3 operator+(const Vec3& other) const;
	Vec3 operator+(float value) const;
	Vec3& operator+=(const Vec3& other);
	Vec3& operator+=(float value);
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator-(float value) const;
	Vec3& operator-=(const Vec3& other);
	Vec3& operator-=(float value);
	bool operator==(const Vec3& other) const;
	bool operator!=(const Vec3& other) const;
	void operator=(const Vec3& other);
	void operator=(float value);
	Vec3 operator*(float value) const;
	Vec3& operator*=(float value);
	Vec3 operator/(float value) const;
	Vec3& operator/=(float value);

	float Magnitude() const;
	Vec3 Normalized() const;
	void Normalize();
	float SqrMagnitude() const;
	void Scale(const Vec3& other);

	static Vec3 Lerp(const Vec3& a, const Vec3& b, float t);
	static Vec3 LerpUnclamped(const Vec3& a, const Vec3& b, float t);
	static float DotProduct(const Vec3& a, const Vec3& b);
	static float Angle(const Vec3& a, const Vec3& b);
	static Vec3 CrossProduct(const Vec3& a,const Vec3& b);	
	static float Distance(const Vec3& a, const Vec3& b);
	static Vec3 Reflect(const Vec3& direction, const Vec3& normal);

	static const Vec3 up;
	static const Vec3 down;
	static const Vec3 right;
	static const Vec3 left;
	static const Vec3 forward;
	static const Vec3 back;
	static const Vec3 zero;
	static const Vec3 unit;

	float x;
	float y;
	float z;
};

inline float Vec3::Magnitude() const {
	return sqrtf(SqrMagnitude());
}

inline void Vec3::Normalize() {	
	float inverse = 1.0f / Magnitude();
	*this *= inverse;
}

inline Vec3 Vec3::Normalized() const {
	float inverse = 1.0f / Magnitude();
	return Vec3(this->x * inverse, this->y * inverse, this->z * inverse);
}

inline float Vec3::DotProduct(const Vec3& a, const Vec3& other)  {
	return (a.x * other.x + a.y * other.y + a.z * other.z);
}

inline float Vec3::Angle(const Vec3& a, const Vec3& other)  {
	return acosf(DotProduct(a ,other) / (a.Magnitude() * other.Magnitude()));
}

inline Vec3 Vec3::CrossProduct(const Vec3& a, const Vec3& other)  {
	return Vec3(a.y * other.z - a.z * other.y,
							a.z * other.x - a.x * other.z,
							a.x * other.y - a.y * other.x);
}

inline float Vec3::SqrMagnitude() const {
	return (this->x * this->x + this->y * this->y + this->z * this->z);
}

inline void Vec3::Scale(const Vec3& other) {	
	Vec3(this->x *= other.x, this->y *= other.y, this->z *= other.z);
}

inline Vec3 Vec3::Lerp(const Vec3& a, const Vec3& b, float t) {
	t = MathUtils::Clamp(t, 0.0f, 1.0f);
	return Vec3(LerpUnclamped(a, b, t));
}

inline Vec3 Vec3::LerpUnclamped(const Vec3& a, const Vec3& b, float t) {
	return Vec3((a.x + t) * (b.x - a.x), (a.y + t) * (b.y - a.y), (a.z + t) * (b.z - a.z));
}

inline float Vec3::Distance(const Vec3& a, const Vec3& b) {
	return (a - b).Magnitude();
}

inline Vec3 Vec3::Reflect(const Vec3& direction, const Vec3& normal) {
	return Vec3(direction - normal * (DotProduct(direction, normal) * 2.0f));
}

inline Vec3 Vec3::operator+(const Vec3& other) const {
	return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}

inline Vec3 Vec3::operator+(float value) const {
	return Vec3(this->x + value, this->y + value, this->z + value);
}

inline Vec3& Vec3::operator+=(const Vec3& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

inline Vec3& Vec3::operator+=(float value) {
	this->x += value;
	this->y += value;
	this->z += value;
	return *this;
}

inline Vec3 Vec3::operator-(const Vec3& other) const {
	return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}

inline Vec3 Vec3::operator-(float value) const {
	return Vec3(this->x - value, this->y - value, this->z - value);
}

inline Vec3& Vec3::operator-=(const Vec3& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

inline Vec3& Vec3::operator-=(float value) {
	this->x -= value;
	this->y -= value;
	this->z -= value;
	return *this;
}

inline bool Vec3::operator==(const Vec3& other) const {
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

inline bool Vec3::operator!=(const Vec3& other) const {
	return (this->x != other.x || this->y != other.y || this->z != other.z);
}

inline void Vec3::operator=(const Vec3& other) {	
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

inline void Vec3::operator=(float value) {
	this->x = value;	
	this->y = value;	
	this->z = value;	
}

inline Vec3 Vec3::operator*(float value) const {
	return Vec3(this->x * value, this->y * value, this->z * value);
}

inline Vec3& Vec3::operator*=(float value) {	
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

inline Vec3 Vec3::operator/(float value) const {
	float inverse = 1.0f / value;
	return Vec3(this->x * inverse, this->y * inverse, this->z * inverse);
}

inline Vec3& Vec3::operator/=(float value) {	
	float inverse = 1.0f / value;
	this->x *= inverse;
	this->y *= inverse;
	this->z *= inverse;
	return *this;
}

#endif 
