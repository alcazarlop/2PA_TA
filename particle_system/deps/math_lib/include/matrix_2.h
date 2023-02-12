#ifndef __MATRIX2_H__
#define __MATRIX2_H__ 1

#include "vector_2.h"

class Mat2 {
public:

	Mat2();
	Mat2(float a[4]);
	Mat2(float value);
	Mat2(const Vec2& a, const Vec2& b); 
	Mat2(const Mat2& copy);
	~Mat2();

	static Mat2 Identity();
	Mat2 Multiply(const Mat2& other) const;
	float Determinant() const;
	Mat2 Adjoint() const;
	Vec2 GetLine(int line) const;
	Vec2 GetColum(int column) const;

	Mat2 Inverse() const;
	Mat2 Transpose() const;

	inline Mat2 operator+(const Mat2& other) const;
	inline void operator+=(const Mat2& other);
	inline Mat2 operator+(float value) const;
	inline void operator+=(float value);
	inline Mat2 operator-(const Mat2& other) const;
	inline void operator-=(const Mat2& other);
	inline Mat2 operator-(float value) const;
	inline void operator-=(float value);

	inline Mat2 operator*(float value) const;
	inline void operator*=(float value);
	inline Mat2 operator/(float value) const;
	inline void operator/=(float value);

	bool operator==(const Mat2& other) const;
	bool operator!=(const Mat2& other) const;
	inline void operator=(const Mat2& other);

	float m[4];
};

inline Mat2::Mat2(){
	m[0] = 0.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;
}

inline Mat2::Mat2(float a[4]){
	m[0] = a[0];
	m[1] = a[1];
	m[2] = a[2];
	m[3] = a[3];
}

inline Mat2::Mat2(float value){
	m[0] = value;
	m[1] = value;
	m[2] = value;
	m[3] = value;
}

inline Mat2::Mat2(const Vec2& a, const Vec2& b){
	m[0] = a.x;
	m[1] = a.y;
	m[2] = b.x;
	m[3] = b.y;
}

inline Mat2::Mat2(const Mat2& copy){
	m[0] = copy.m[0];
	m[1] = copy.m[1];
	m[2] = copy.m[2];
	m[3] = copy.m[3];
}

inline Mat2::~Mat2(){}

inline Mat2 Mat2::operator+(const Mat2& other) const {
	Mat2 result = Mat2();
	result.m[0] += other.m[0];
	result.m[1] += other.m[1];
	result.m[2] += other.m[2];
	result.m[3] += other.m[3];
	return result;
}

inline void Mat2::operator+=(const Mat2& other) {
	this->m[0] += other.m[0];
	this->m[1] += other.m[1];
	this->m[2] += other.m[2];
	this->m[3] += other.m[3];
}

inline Mat2 Mat2::operator+(float value) const {
	Mat2 result = Mat2();
	result.m[0] += value;
	result.m[1] += value;
	result.m[2] += value;
	result.m[3] += value;
	return result;
}

inline void Mat2::operator+=(float value) {
	this->m[0] += value;
	this->m[1] += value;
	this->m[2] += value;
	this->m[3] += value;
}

inline Mat2 Mat2::operator-(const Mat2& other) const {
	Mat2 result = Mat2();
	result.m[0] -= other.m[0];
	result.m[1] -= other.m[1];
	result.m[2] -= other.m[2];
	result.m[3] -= other.m[3];
	return result;
}

inline void Mat2::operator-=(const Mat2& other) {
	this->m[0] -= other.m[0];
	this->m[1] -= other.m[1];
	this->m[2] -= other.m[2];
	this->m[3] -= other.m[3];
}

inline Mat2 Mat2::operator-(float value) const {	
	Mat2 result = Mat2();
	result.m[0] -= value;
	result.m[1] -= value;
	result.m[2] -= value;
	result.m[3] -= value;
	return result;
}

inline void Mat2::operator-=(float value) {
	this->m[0] -= value;
	this->m[1] -= value;
	this->m[2] -= value;
	this->m[3] -= value;
}

inline Mat2 Mat2::operator*(float value) const {
	Mat2 result(*this);
	result.m[0] *= value;
	result.m[1] *= value;
	result.m[2] *= value;
	result.m[3] *= value;
	return result;
}

inline void Mat2::operator*=(float value) {
	this->m[0] *= value;
	this->m[1] *= value;
	this->m[2] *= value;
	this->m[3] *= value;
}

inline Mat2 Mat2::operator/(float value) const {
	float inverse = 1.0f / value;
	Mat2 result(*this);
	result.m[0] *= inverse;
	result.m[1] *= inverse;
	result.m[2] *= inverse;
	result.m[3] *= inverse;
	return result;
}

inline void Mat2::operator/=(float value) {
	float inverse = 1.0f / value;
	this->m[0] *= inverse;
	this->m[1] *= inverse;
	this->m[2] *= inverse;
	this->m[3] *= inverse;
}

inline bool Mat2::operator==(const Mat2& other) const {
	for(int i = 0; i < 4; ++i)
		if(this->m[i] != other.m[i])
			return false;
	return true;
}

inline bool Mat2::operator!=(const Mat2& other) const {
	for(int i = 0; i < 4; ++i)
		if(this->m[i] == other.m[i])
			return false;
	return true;
}

inline void Mat2::operator=(const Mat2& other) {
	this->m[0] = other.m[0];
	this->m[1] = other.m[1];
	this->m[2] = other.m[2];
	this->m[3] = other.m[3];
}

inline Mat2 Mat2::Identity() {
	Mat2 result = Mat2();
	result.m[0] = 1.0f;
	result.m[3] = 1.0f;
	return result;
}

inline float Mat2::Determinant() const {
	return (this->m[0] * this->m[3] - this->m[1] * this->m[2]);
}

inline Mat2 Mat2::Inverse() const {
	Mat2 result = Mat2(); 
	if(this->Determinant() != 0.0f)
		result = this->Adjoint() / this->Determinant();
	return result;
}

inline Mat2 Mat2::Multiply(const Mat2& other) const {
	float multiply[4];

	multiply[0] = (this->m[0] * other.m[0]) + (this->m[1] * other.m[2]);
	multiply[1] = (this->m[0] * other.m[1]) + (this->m[1] * other.m[3]);

	multiply[2] = (this->m[2] * other.m[0]) + (this->m[3] * other.m[2]);
	multiply[3] = (this->m[2] * other.m[1]) + (this->m[3] * other.m[3]);

	return Mat2(multiply);
}

inline Mat2 Mat2::Adjoint() const {
	Mat2 result = Mat2();
	result.m[0] = this->m[3];
	result.m[1] = -this->m[1];
	result.m[2] = -this->m[2];
	result.m[3] = this->m[0];
	return result;
}

inline Mat2 Mat2::Transpose() const {
	float transpose[4] = { 	this->m[0], this->m[2],
													this->m[1], this->m[3] };
	return Mat2(transpose);
}

inline Vec2 Mat2::GetLine(int line) const {
	return Vec2(this->m[line * 2], this->m[line * 2 + 1]);
}

inline Vec2 Mat2::GetColum(int column) const {	
	return Vec2(this->m[column], this->m[column + 2]);
}

#endif
