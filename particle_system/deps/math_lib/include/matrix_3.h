
#ifndef __MATRIX3_H__
#define __MATRIX3_H__ 1

#include <math.h>
#include "vector_2.h"
#include "vector_3.h"
#include "matrix_2.h"
#include <stdio.h>

class Mat3 {
public:

	Mat3();
	Mat3(float *values_array);
	Mat3(float value);
	Mat3(Vec3 a, Vec3 b, Vec3 c);

	Mat3(const Mat3& copy);
	~Mat3();

	static Mat3 Identity();

	Mat3 Multiply(const Mat3& other) const;

	float Determinant() const;

	Mat3 Adjoint() const;
	bool GetInverse(Mat3& out) const;
	bool Inverse();

	Mat3 Transpose() const;

	static Mat3 Translate(const Vec2& position);
	static Mat3 Translate(float x, float y);
	static Mat3 Scale(const Vec2& scale);
	static Mat3 Scale(float x, float y);
	static Mat3 Rotate(float radians);

	Vec3 GetColum(int colum) const;
	Vec3 GetLine(int line) const;

	inline Mat3 operator+(const Mat3& other) const;
	inline Mat3& operator+=(const Mat3& other);
	inline Mat3 operator+(float value) const;
	inline Mat3& operator+=(float value);
	inline Mat3 operator-(const Mat3& other) const;
	inline Mat3& operator-=(const Mat3& other);
	inline Mat3 operator-(float value) const;
	inline Mat3& operator-=(float value);
	inline Mat3 operator*(float value) const;
	inline Mat3& operator*=(float value);
	inline Mat3 operator/(float value) const;
	inline Mat3& operator/=(float value);
	bool operator==(const Mat3& other) const;
	bool operator!=(const Mat3& other) const;
	inline void operator=(const Mat3& other);

	Vec3 Mat3TransformVec3(const Vec3& v);
	Vec2 Mat3TransformVec2(const Vec2& v);

	float m[9];
};

inline Mat3 Mat3::operator+(const Mat3& other) const {
	Mat3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] += other.m[i];
	return result;
}

inline Mat3& Mat3::operator+=(const Mat3& other) {
	for(int i = 0; i < 9; ++i)
		this->m[i] += other.m[i];
	return *this;
}

inline Mat3 Mat3::operator+(float value) const {
	Mat3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] += value;
	return result;
}

inline Mat3& Mat3::operator+=(float value) {	
	for(int i = 0; i < 9; ++i)
		this->m[i] += value;
	return *this;
}

inline Mat3 Mat3::operator-(const Mat3& other) const {
	Mat3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] -= other.m[i];
	return result;
}

inline Mat3& Mat3::operator-=(const Mat3& other) {
	for(int i = 0; i < 9; ++i)
		this->m[i] -= other.m[i];
	return *this;
}

inline Mat3 Mat3::operator-(float value) const {
	Mat3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] -= value;
	return result;
}

inline Mat3& Mat3::operator-=(float value) {
	for(int i = 0; i < 9; ++i)
		this->m[i] -= value;
	return *this;
}

inline Mat3 Mat3::operator*(float value) const {
	Mat3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] *= value;
	return result;
}

inline Mat3& Mat3::operator*=(float value) {
	for(int i = 0; i < 9; ++i)
		this->m[i] *= value;
	return *this;
}

inline Mat3 Mat3::operator/(float value) const {
	float inverse = 1.0f / value;
	Mat3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] *= inverse;
	return result;
}

inline Mat3& Mat3::operator/=(float value) {
	float inverse = 1.0f / value;
	for(int i = 0; i < 9; ++i)
		this->m[i] *= inverse;
	return *this;
}

inline bool Mat3::operator==(const Mat3& other) const {
	for(int i = 0 ; i < 9; ++i)
		if(this->m[i] != other.m[i])
			return false;
	return true;
}

inline bool Mat3::operator!=(const Mat3& other) const {
	for(int i = 0; i < 9; ++i)
		if(this->m[i] != other.m[i])
			return true;
	return false;
}

inline void Mat3::operator=(const Mat3& other) {
	for(int i = 0; i < 9; ++i)
		this->m[i] = other.m[i];
}

inline Mat3 Mat3::Identity() {
	Mat3 result = Mat3();
	result.m[0] = 1.0f;
	result.m[4] = 1.0f;
	result.m[8] = 1.0f;
	return result;
}

inline float Mat3::Determinant() const {
	return (	m[0] * m[4] * m[8]
	 				+ m[3] * m[7] * m[2]
					+ m[1] * m[5] * m[6]
					- m[6] * m[4] * m[2]
					- m[0] * m[5] * m[7]
					- m[1] * m[3] * m[8]);
}

inline bool Mat3::GetInverse(Mat3& out) const {
	if(this->Determinant() != 0.0f){
		out = this->Adjoint() / this->Determinant();
		return true;
	}
	return false;
}

inline bool Mat3::Inverse() {	
	if(this->Determinant() != 0.0f){
		*this = this->Adjoint().Transpose() / this->Determinant();
		return true;
	}
	return false;
}

inline Mat3 Mat3::Translate(const Vec2& mov_vector) {	
	Mat3 result = Identity();
	result.m[6] = mov_vector.x;
	result.m[7] = mov_vector.y;
	return result;
}

inline Mat3 Mat3::Translate(float x, float y) {
	Mat3 result = Identity();
	result.m[6] = x;
	result.m[7] = y;
	return result;
}

inline Mat3 Mat3::Scale(const Vec2& scale){
	Mat3 result = Identity();
	result.m[0] = scale.x;
	result.m[4] = scale.y;
	return result;
}

inline Mat3 Mat3::Scale(float x, float y){
	Mat3 result = Identity();
	result.m[0] = x;
	result.m[4] = y;
	return result;
}

inline Mat3 Mat3::Rotate(float radians){
	Mat3 result = Identity();
	result.m[0] = cosf(radians);
	result.m[1] = -sinf(radians);
	result.m[3] = sinf(radians);
	result.m[4] = cosf(radians);
	return result;
}

inline Mat3 Mat3::Multiply(const Mat3& other) const {
	float multiply[9];

	multiply[0] = (this->m[0] * other.m[0]) + (this->m[1] * other.m[3]) + (this->m[2] * other.m[6]);
	multiply[1] = (this->m[0] * other.m[1]) + (this->m[1] * other.m[4]) + (this->m[2] * other.m[7]);
	multiply[2] = (this->m[0] * other.m[2]) + (this->m[1] * other.m[5]) + (this->m[2] * other.m[8]);

	multiply[3] = (this->m[3] * other.m[0]) + (this->m[4] * other.m[3]) + (this->m[5] * other.m[6]);
	multiply[4] = (this->m[3] * other.m[1]) + (this->m[4] * other.m[4]) + (this->m[5] * other.m[7]);
	multiply[5] = (this->m[3] * other.m[2]) + (this->m[4] * other.m[5]) + (this->m[5] * other.m[8]);

	multiply[6] = (this->m[6] * other.m[0]) + (this->m[7] * other.m[3]) + (this->m[8] * other.m[6]);
	multiply[7] = (this->m[6] * other.m[1]) + (this->m[7] * other.m[4]) + (this->m[8] * other.m[7]);
	multiply[8] = (this->m[6] * other.m[2]) + (this->m[7] * other.m[5]) + (this->m[8] * other.m[8]);

	return Mat3(multiply);
}

inline Mat3 Mat3::Adjoint() const {

	float det_0[4] = { this->m[4], this->m[5], this->m[7], this->m[8] };
	float det_1[4] = { this->m[3], this->m[5], this->m[6], this->m[8] };
	float det_2[4] = { this->m[3], this->m[4], this->m[6], this->m[7] };

	float det_3[4] = { this->m[1], this->m[2], this->m[7], this->m[8] };
	float det_4[4] = { this->m[0], this->m[2], this->m[6], this->m[8] };
	float det_5[4] = { this->m[0], this->m[1], this->m[6], this->m[7] };

	float det_6[4] = { this->m[1], this->m[2], this->m[4], this->m[5] };
	float det_7[4] = { this->m[0], this->m[2], this->m[3], this->m[5] };
	float det_8[4] = { this->m[0], this->m[1], this->m[3], this->m[4] };

	float array[9] = { Mat2(det_0).Determinant(), -Mat2(det_1).Determinant(), Mat2(det_2).Determinant(),
										 -Mat2(det_3).Determinant(), Mat2(det_4).Determinant(), -Mat2(det_5).Determinant(),
										 Mat2(det_6).Determinant(), -Mat2(det_7).Determinant(), Mat2(det_8).Determinant() };
	return Mat3(array);
}

inline Mat3 Mat3::Transpose() const {
	float transpose[9] = { 	this->m[0], this->m[3], this->m[6],
													this->m[1], this->m[4], this->m[7],
													this->m[2], this->m[5], this->m[8] };
	return Mat3(transpose);
}

inline Vec3 Mat3::GetColum(int colum) const {
	return Vec3(this->m[colum], this->m[colum + 3], this->m[colum + 6]);
}

inline Vec3 Mat3::GetLine(int line) const {
	return Vec3(this->m[line * 3], this->m[line * 3 + 1], this->m[line * 3 + 2]);
}

inline Vec3 Mat3::Mat3TransformVec3(const Vec3& v) {
	Vec3 tmp;
	tmp.x = m[0] * v.x + m[3] * v.y + m[6] * v.z;
	tmp.y = m[1] * v.x + m[4] * v.y + m[7] * v.z;
	tmp.z = m[2] * v.x + m[5] * v.y + m[8] * v.z;
	return tmp;
}

inline Vec2 Mat3::Mat3TransformVec2(const Vec2& v){
	Vec3 tmp;
	tmp.x = v.x;
	tmp.y = v.y;
	tmp.z = 1.0f;

	Vec3 result = Mat3TransformVec3(tmp);
	result.x /= result.z;
	result.y /= result.z;

	return Vec2(result.x, result.y);
}

#endif 