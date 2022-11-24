
#include "matrix_2.h"

//Constructors
Mat2::Mat2() {
  m[0] = 0.0f;
  m[1] = 0.0f;
  m[2] = 0.0f;
  m[3] = 0.0f;
}

Mat2::Mat2(float a[4]) {
  m[0] = a[0];
  m[1] = a[1];
  m[2] = a[2];
  m[3] = a[3];
}

Mat2::Mat2(float a) {
  m[0] = a;
  m[1] = a;
  m[2] = a;
  m[3] = a;
}

Mat2::Mat2(const Vec2& a, const Vec2& b) {
  m[0] = a.x;
  m[1] = a.y;
  m[2] = b.x;
  m[3] = b.y;
}

Mat2::Mat2(const Mat2& copy) {
  m[0] = copy.m[0];
  m[1] = copy.m[1];
  m[2] = copy.m[2];
  m[3] = copy.m[3];
}

Mat2::~Mat2() {}
