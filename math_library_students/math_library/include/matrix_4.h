
#ifndef __MATRIX4_H__
#define __MATRIX4_H__ 1

#include <math.h>
#include "vector_3.h"
#include "vector_4.h"
#include "matrix_3.h"

class Mat4 {
 public:

  Mat4();
  Mat4(float a[16]);
  Mat4(float value);
  Mat4(const Mat4& copy);
  ~Mat4();

  static Mat4 Identity();
  Mat4 Multiply(const Mat4& other) const;

  float Determinant() const;
  Mat4 Adjoint() const;
  bool GetInverse(Mat4* out) const;
  bool Inverse();

  Mat4 Transpose() const;

  static Mat4 Translate(const Vec3& distance);
  static Mat4 Translate(float x, float y, float z);

  static Mat4 Scale(const Vec3& scale);
  static Mat4 Scale(float x, float y, float z);

  static Mat4 RotateX(float radians);
  static Mat4 RotateY(float radians);
  static Mat4 RotateZ(float radians);

  static Mat4 GetTransform(const Vec3& translate, const Vec3& scale,
                      float rotateX, float rotateY, float rotateZ);

  static Mat4 GetTransform(float trans_x, float trans_y, float trans_z,
                      float scale_x, float scale_y, float scale_Z,
                      float rotateX, float rotateY, float rotateZ);

  Mat4 PerspectiveMatrix(float fov, float aspect,
	  float near, float far) const;

  Mat4 OrthoMatrix(float right, float left, float top, float valueottom,
	  float near, float far) const;

  Vec4 GetColum(int colum) const;
  Vec4 GetLine(int line) const;

  Mat4 operator+(const Mat4& other) const;
  Mat4& operator+=(const Mat4& other);
  Mat4 operator+(float value) const;
  Mat4& operator+=(float value);
  Mat4 operator-(const Mat4& other) const;
  Mat4& operator-=(const Mat4& other);
  Mat4 operator-(float value) const;
  Mat4& operator-=(float value);
  Mat4& operator*=(float value);
  Mat4 operator*(float value) const;
  Mat4& operator/=(float value);
  Mat4 operator/(float value) const;
  bool operator==(const Mat4& other);
  bool operator!=(const Mat4& other);
  void operator=(const Mat4& other);

  static Mat4 ProjectionMatrix();
  Vec4 Mat4TransformVec4(const Vec4& vec);
  Vec3 Mat4TransformVec3(const Vec3& vec);

  float m[16];
};


inline Mat4 Mat4::Identity() {
	Mat4 result = Mat4();
	result.m[0] = 1.0f;
	result.m[5] = 1.0f;
	result.m[10] = 1.0f;
	result.m[15] = 1.0f;
	return result;
}

inline Mat4 Mat4::Multiply(const Mat4& other)const  {
	float multiply[16];

	multiply[0] = (this->m[0] * other.m[0]) + (this->m[1] * other.m[4]) + (this->m[2] * other.m[8]) + (this->m[3] * other.m[12]);
	multiply[1] = (this->m[0] * other.m[1]) + (this->m[1] * other.m[5]) + (this->m[2] * other.m[9]) + (this->m[3] * other.m[13]);
	multiply[2] = (this->m[0] * other.m[2]) + (this->m[1] * other.m[6]) + (this->m[2] * other.m[10]) + (this->m[3] * other.m[14]);
	multiply[3] = (this->m[0] * other.m[3]) + (this->m[1] * other.m[7]) + (this->m[2] * other.m[11]) + (this->m[3] * other.m[15]);

	multiply[4] = (this->m[4] * other.m[0]) + (this->m[5] * other.m[4]) + (this->m[6] * other.m[8]) + (this->m[7] * other.m[12]);
	multiply[5] = (this->m[4] * other.m[1]) + (this->m[5] * other.m[5]) + (this->m[6] * other.m[9]) + (this->m[7] * other.m[13]);
	multiply[6] = (this->m[4] * other.m[2]) + (this->m[5] * other.m[6]) + (this->m[6] * other.m[10]) + (this->m[7] * other.m[14]);
	multiply[7] = (this->m[4] * other.m[3]) + (this->m[5] * other.m[7]) + (this->m[6] * other.m[11]) + (this->m[7] * other.m[15]);

	multiply[8] = (this->m[8] * other.m[0]) + (this->m[9] * other.m[4]) + (this->m[10] * other.m[8]) + (this->m[11] * other.m[12]);
	multiply[9] = (this->m[8] * other.m[1]) + (this->m[9] * other.m[5]) + (this->m[10] * other.m[9]) + (this->m[11] * other.m[13]);
	multiply[10] = (this->m[8] * other.m[2]) + (this->m[9] * other.m[6]) + (this->m[10] * other.m[10]) + (this->m[11] * other.m[14]);
	multiply[11] = (this->m[8] * other.m[3]) + (this->m[9] * other.m[7]) + (this->m[10] * other.m[11]) + (this->m[11] * other.m[15]);

	multiply[12] = (this->m[12] * other.m[0]) + (this->m[13] * other.m[4]) + (this->m[14] * other.m[8]) + (this->m[15] * other.m[12]);
	multiply[13] = (this->m[12] * other.m[1]) + (this->m[13] * other.m[5]) + (this->m[14] * other.m[9]) + (this->m[15] * other.m[13]);
	multiply[14] = (this->m[12] * other.m[2]) + (this->m[13] * other.m[6]) + (this->m[14] * other.m[10]) + (this->m[15] * other.m[14]);
	multiply[15] = (this->m[12] * other.m[3]) + (this->m[13] * other.m[7]) + (this->m[14] * other.m[11]) + (this->m[15] * other.m[15]);

	return Mat4(multiply);
}

inline float Mat4::Determinant() const {

 	float det_0[9] = { this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_1[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_2[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[7], this->m[11], this->m[15] };

  float det_3[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14] };

  return (  this->m[0] * Mat3(det_0).Determinant() - this->m[1] * Mat3(det_1).Determinant() 
          + this->m[2] * Mat3(det_2).Determinant() - this->m[3] * Mat3(det_3).Determinant());
}

inline Mat4 Mat4::Adjoint() const { 
	
	float det_0[9] = { this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_1[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_2[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[7], this->m[11], this->m[15] };

  float det_3[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14] };

  float det_4[9] = { this->m[1], this->m[9], this->m[13],
                     this->m[2], this->m[10], this->m[14],
                     this->m[3], this->m[11], this->m[15] };

  float det_5[9] = { this->m[0], this->m[8], this->m[12],
                     this->m[2], this->m[10], this->m[14],
                     this->m[3], this->m[11], this->m[15] };

  float det_6[9] = { this->m[0], this->m[8], this->m[12],
                     this->m[1], this->m[9], this->m[13],
                     this->m[3], this->m[11], this->m[15] };

  float det_7[9] = { this->m[0], this->m[8], this->m[12],
                     this->m[1], this->m[9], this->m[13],
                     this->m[2], this->m[10], this->m[14] };  

  float det_8[9] = { this->m[1], this->m[5], this->m[13],
                     this->m[2], this->m[6], this->m[14],
                     this->m[3], this->m[7], this->m[15] };

  float det_9[9] = { this->m[0], this->m[4], this->m[12],
                     this->m[2], this->m[6], this->m[14],
                     this->m[3], this->m[7], this->m[15] };

  float det_10[9] = { this->m[0], this->m[4], this->m[12],
                     this->m[1], this->m[5], this->m[13],
                     this->m[3], this->m[7], this->m[15] };

  float det_11[9] = { this->m[0], this->m[4], this->m[12],
                     this->m[1], this->m[5], this->m[13],
                     this->m[2], this->m[6], this->m[14] };  

  float det_12[9] = { this->m[1], this->m[5], this->m[9],
                     this->m[2], this->m[6], this->m[10],
                     this->m[3], this->m[7], this->m[11] };

  float det_13[9] = { this->m[0], this->m[4], this->m[8],
                     this->m[2], this->m[6], this->m[10],
                     this->m[3], this->m[7], this->m[11] };

  float det_14[9] = { this->m[0], this->m[4], this->m[8],
                     this->m[1], this->m[5], this->m[9],
                     this->m[3], this->m[7], this->m[11] };

  float det_15[9] = { this->m[0], this->m[4], this->m[8],
                     this->m[1], this->m[5], this->m[9],
                     this->m[2], this->m[6], this->m[10] };

  float array[16] = { Mat3(det_0).Determinant(), -Mat3(det_4).Determinant(), Mat3(det_8).Determinant(), -Mat3(det_12).Determinant(),
                      -Mat3(det_1).Determinant(), Mat3(det_5).Determinant(), -Mat3(det_9).Determinant(), Mat3(det_13).Determinant(),
                      Mat3(det_2).Determinant(), -Mat3(det_6).Determinant(), Mat3(det_10).Determinant(), -Mat3(det_14).Determinant(),
                      -Mat3(det_3).Determinant(), Mat3(det_7).Determinant(),- Mat3(det_11).Determinant(), Mat3(det_15).Determinant() };  

  return Mat4(array);
}

inline bool Mat4::Inverse() {
	if(this->Determinant() != 0.0f){
		*this = this->Adjoint() / this->Determinant();	
		return true;
	}
	return false;
}

inline bool Mat4::GetInverse(Mat4* out) const {
	if(this->Determinant() != 0.0f){
		*out = this->Adjoint() / this->Determinant();	
		return true;
	}
	return false;
}

inline Mat4 Mat4::Transpose() const {
	float transpose[16] = { this->m[0], this->m[4], this->m[8], this->m[12],
													this->m[1], this->m[5], this->m[9], this->m[13],
													this->m[2], this->m[6], this->m[10], this->m[14],
													this->m[3], this->m[7], this->m[11], this->m[15] };
		
	return Mat4(transpose);
}

inline Mat4 Mat4::Translate(const Vec3& distance){
	Mat4 result = Identity();
	result.m[12] = distance.x;
	result.m[13] = distance.y;
	result.m[14] = distance.z;
	return result;
}

inline Mat4 Mat4::Translate(float x, float y, float z){
	Mat4 result = Identity();
	result.m[12] = x;
	result.m[13] = y;
	result.m[14] = z;
	return result;
}

inline Mat4 Mat4::Scale(const Vec3& scale){
	Mat4 result = Identity();
	result.m[0] = scale.x;
	result.m[5] = scale.y;
	result.m[10] = scale.z;
	return result;
}

inline Mat4 Mat4::Scale(float x, float y, float z){
	Mat4 result = Identity();
	result.m[0] = x;
	result.m[5] = y;
	result.m[10] = z;
	return result;
}

inline Mat4 Mat4::RotateX(float radians){
	Mat4 result = Identity();
	result.m[5] = cosf(radians);
	result.m[6] = -sinf(radians);
	result.m[9] = sinf(radians);
	result.m[10] = cosf(radians);
	return result;
}

inline Mat4 Mat4::RotateY(float radians){
	Mat4 result = Identity();
	result.m[0] = cosf(radians);
	result.m[2] = sinf(radians);
	result.m[8] = -sinf(radians);
	result.m[10] = cosf(radians);
	return result;
}

inline Mat4 Mat4::RotateZ(float radians) {
	Mat4 result = Identity();
	result.m[0] = cosf(radians);
	result.m[1] = -sinf(radians);
	result.m[4] = sinf(radians);
	result.m[5] = cosf(radians);
	return result;
}

inline Mat4 Mat4::GetTransform(	const Vec3& translate,
																const Vec3& scale,
																float rotateX, float rotateY, float rotateZ)   {

	Mat4 result = result.Identity();
  Mat4 translation;
  Mat4 scalation;
  Mat4 rotation;

  rotation = rotation.RotateX(rotateX).Multiply(rotation.RotateY(rotateY).Multiply(rotation.RotateZ(rotateZ)));
  result = translation.Translate(translate.x, translate.y, translate.z).Multiply(rotation.Multiply(scalation.Scale(scale.x, scale.y, scale.z)));
  
  return result;
}

inline Mat4 Mat4::GetTransform(	float trans_x, float trans_y, float trans_z,
																float scale_x, float scale_y, float scale_z,
																float rotateX, float rotateY, float rotateZ)  {

	Mat4 result = result.Identity();
  Mat4 translation;
  Mat4 scalation;
  Mat4 rotation;

  rotation = rotation.RotateX(rotateX).Multiply(rotation.RotateY(rotateY).Multiply(rotation.RotateZ(rotateZ)));
  result = translation.Translate(trans_x, trans_y, trans_z).Multiply(rotation.Multiply(scalation.Scale(scale_x, scale_y, scale_z)));
  
  return result;
}

inline Vec4 Mat4::GetColum(int column) const {
	return Vec4(this->m[column], this->m[column + 4], this->m[column + 8], this->m[column + 12]);
}

inline Vec4 Mat4::GetLine(int line) const {
	return Vec4(this->m[line * 4], this->m[line * 4 + 1], this->m[line * 4 + 2], this->m[line * 4 + 3]);
}

inline Mat4 Mat4::PerspectiveMatrix(float fov, float aspect,
	float near, float far) const {

	fov = 0.0f;
	aspect = 0.0f;
	near = 0.0f;
	far = 0.0f;

	return Mat4();
}

inline Mat4 Mat4::OrthoMatrix(float right, float left, float top, float valueottom,
	float near, float far) const {

	right = 0.0f;
	left = 0.0f;
	top = 0.0f;
	valueottom = 0.0f;
	near = 0.0f;
	far = 0.0f;

	return Mat4();
}

inline Mat4 Mat4::operator+(const Mat4& other) const {
	Mat4 result(*this);
	for(int i = 0; i < 16; ++i)
		result.m[i] += other.m[i];
	return result;
}

inline Mat4& Mat4::operator+=(const Mat4& other) {
	for(int i = 0; i < 16; ++i)
		this->m[i] += other.m[i];
	return *this;
}

inline Mat4 Mat4::operator+(float value) const {
	Mat4 result(*this);
	for(int i = 0; i < 16; ++i)
		result.m[i] += value;
	return result;
}

inline Mat4& Mat4::operator+=(float value) {	
	for(int i = 0; i < 16; ++i)
		this->m[i] += value;
	return *this;
}

inline Mat4 Mat4::operator-(const Mat4& other) const {
	Mat4 result(*this);
	for(int i = 0; i < 16; ++i)
		result.m[i] -= other.m[i];
	return result;
}

inline Mat4& Mat4::operator-=(const Mat4& other) {
	for(int i = 0; i < 16; ++i)
		this->m[i] -= other.m[i];
	return *this;
}

inline Mat4 Mat4::operator-(float value) const {
	Mat4 result(*this);
	for(int i = 0; i < 16; ++i)
		result.m[i] -= value;
	return result;
}

inline Mat4& Mat4::operator-=(float value) {
	for(int i = 0; i < 16; ++i)
		this->m[i] -= value;
	return *this;
}

inline Mat4& Mat4::operator*=(float value) {
	for(int i = 0; i < 16; ++i)
		this->m[i] *= value;
	return *this;
}

inline Mat4 Mat4::operator*(float value) const {
	Mat4 result(*this);
	for(int i = 0; i < 16; ++i)
		result.m[i] *= value;
	return result;
}

inline Mat4& Mat4::operator/=(float value) {
	float inverse = 1.0f / value;
	for(int i = 0; i < 16; ++i)
		this->m[i] *= inverse;
	return *this;
}

inline Mat4 Mat4::operator/(float value) const {
	float inverse = 1.0f / value;
	Mat4 result(*this);
	for(int i = 0; i < 16; ++i)
		result.m[i] *= inverse;
	return result;
}

inline bool Mat4::operator==(const Mat4& other) {
	for(int i = 0; i < 16; ++i)
		if(this->m[i] != other.m[i])
			return false;
	return true;
}

inline bool Mat4::operator!=(const Mat4& other) {
	for(int i = 0; i < 16; ++i)
		if(this->m[i] != other.m[i])
			return true;
	return false;
}

inline void Mat4::operator=(const Mat4& other) {
	for(int i = 0; i < 16; ++i)
		this->m[i] = other.m[i];
}

inline Mat4 Mat4::ProjectionMatrix(){
	float projection[16] = {	1.0f, 0.0f, 0.0f, 0.0f,
														0.0f, 1.0f, 0.0f, 0.0f,
														0.0f, 0.0f, 1.0f, 0.0f,
														0.0f, 0.0f, 1.0f, 0.0f };
	return Mat4(projection);
}

inline Vec4 Mat4::Mat4TransformVec4(const Vec4& v){
	Vec4 temp;

	temp.x = m[0] * v.x + m[4] * v.y + m[8] * v.z + m[12] * v.w;
	temp.y = m[1] * v.x + m[5] * v.y + m[9] * v.z + m[13] * v.w;
	temp.z = m[2] * v.x + m[6] * v.y + m[10] * v.z + m[14] * v.w;
	temp.w = m[3] * v.x + m[7] * v.y + m[11] * v.z + m[15] * v.w;

	return temp;
}

inline Vec3 Mat4::Mat4TransformVec3(const Vec3& vec){
	Vec4 temp;
	temp.x = vec.x;
	temp.y = vec.y;
	temp.z = vec.z;
	temp.w = 1.0f;

	Vec4 result = Mat4TransformVec4(temp);
	result.x /= result.w;
	result.y /= result.y;
	result.z /= result.z;

	return Vec3(result.x, result.y, result.z);

}


#endif
