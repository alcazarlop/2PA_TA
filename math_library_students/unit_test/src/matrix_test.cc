#include "matrix_3.h"
#include "matrix_4.h"
#include "unit_test_helpers.h"

// Code by Diego Llorens, Lucas Gonzalez and Gustavo Aranda

namespace UnitTest {
	void Mat3Test() {
		
		Test::Start(__FUNCTION__);
		Mat3 test;
		Mat3 another_test;
		Mat3 identity;
		bool worked = false;
		float fv[9] = {  1.0f,  2.0f,  3.0f,  4.0f,  5.0f,  6.0f,  7.0f,  8.0f,  9.0f };
		float fu[9] = { 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f, 90.0f };

		identity.m[0] = 1.0f; identity.m[1] = 0.0f; identity.m[2] = 0.0f;
		identity.m[3] = 0.0f; identity.m[4] = 1.0f; identity.m[5] = 0.0f;
		identity.m[6] = 0.0f; identity.m[7] = 0.0f; identity.m[8] = 1.0f;

		// Check Constructors
		Mat3 con0(fv);
		Assert::AreEqual(con0.m[0], fv[0], "Constructor(float*) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[1], fv[1], "Constructor(float*) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[2], fv[2], "Constructor(float*) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[3], fv[3], "Constructor(float*) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[4], fv[4], "Constructor(float*) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[5], fv[5], "Constructor(float*) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[6], fv[6], "Constructor(float*) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[7], fv[7], "Constructor(float*) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[8], fv[8], "Constructor(float*) Failed 8", __FILE__, __LINE__);
		Mat3 con1(100.0f);
		Assert::AreEqual(con1.m[0], 100.0f, "Constructor(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[1], 100.0f, "Constructor(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[2], 100.0f, "Constructor(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[3], 100.0f, "Constructor(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[4], 100.0f, "Constructor(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[5], 100.0f, "Constructor(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[6], 100.0f, "Constructor(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[7], 100.0f, "Constructor(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(con1.m[8], 100.0f, "Constructor(float) Failed 8", __FILE__, __LINE__);
		Vec3 va = Vec3(fv[0], fv[1], fv[2]);
		Vec3 vb = Vec3(fv[3], fv[4], fv[5]);
		Vec3 vc = Vec3(fv[6], fv[7], fv[8]);
		Mat3 con2 = Mat3(va, vb, vc);
		Assert::AreEqual(con2.m[0], va.x, "Constructor(Vec3,Vec3,Vec3) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[1], va.y, "Constructor(Vec3,Vec3,Vec3) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[2], va.z, "Constructor(Vec3,Vec3,Vec3) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[3], vb.x, "Constructor(Vec3,Vec3,Vec3) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[4], vb.y, "Constructor(Vec3,Vec3,Vec3) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[5], vb.z, "Constructor(Vec3,Vec3,Vec3) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[6], vc.x, "Constructor(Vec3,Vec3,Vec3) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[7], vc.y, "Constructor(Vec3,Vec3,Vec3) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[8], vc.z, "Constructor(Vec3,Vec3,Vec3) Failed 8", __FILE__, __LINE__);
		Mat3 con3;
		con3.m[0] = fv[0]; con3.m[1] = fv[1]; con3.m[2] = fv[2];
		con3.m[3] = fv[3]; con3.m[4] = fv[4]; con3.m[5] = fv[5];
		con3.m[6] = fv[6]; con3.m[7] = fv[7]; con3.m[8] = fv[8];
		Mat3 copy(con3);
		Assert::AreEqual(copy.m[0], fv[0], "Copy constructor Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], fv[1], "Copy constructor Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], fv[2], "Copy constructor Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], fv[3], "Copy constructor Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], fv[4], "Copy constructor Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], fv[5], "Copy constructor Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], fv[6], "Copy constructor Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], fv[7], "Copy constructor Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], fv[8], "Copy constructor Failed 8", __FILE__, __LINE__);

		/////////////////////////
		// ---- OPERATORS ----///
		/////////////////////////

		//-----------------//
		// -- Operator= -- //
		//----------------//
		Mat3 op0;
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		copy = op0;
		Assert::AreEqual(copy.m[0], op0.m[0], "Operator= Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op0.m[1], "Operator= Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op0.m[2], "Operator= Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op0.m[3], "Operator= Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op0.m[4], "Operator= Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op0.m[5], "Operator= Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op0.m[6], "Operator= Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op0.m[7], "Operator= Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op0.m[8], "Operator= Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator+ -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		Mat3 op1;
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		copy = op0 + op1;
		Assert::AreEqual(copy.m[0], op0.m[0] + op1.m[0], "Operator+(Mat3) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op0.m[1] + op1.m[1], "Operator+(Mat3) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op0.m[2] + op1.m[2], "Operator+(Mat3) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op0.m[3] + op1.m[3], "Operator+(Mat3) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op0.m[4] + op1.m[4], "Operator+(Mat3) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op0.m[5] + op1.m[5], "Operator+(Mat3) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op0.m[6] + op1.m[6], "Operator+(Mat3) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op0.m[7] + op1.m[7], "Operator+(Mat3) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op0.m[8] + op1.m[8], "Operator+(Mat3) Failed 8", __FILE__, __LINE__);
		copy = op0 + 10.0f;
		Assert::AreEqual(copy.m[0], op0.m[0] + 10.0f, "Operator+(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op0.m[1] + 10.0f, "Operator+(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op0.m[2] + 10.0f, "Operator+(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op0.m[3] + 10.0f, "Operator+(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op0.m[4] + 10.0f, "Operator+(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op0.m[5] + 10.0f, "Operator+(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op0.m[6] + 10.0f, "Operator+(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op0.m[7] + 10.0f, "Operator+(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op0.m[8] + 10.0f, "Operator+(float) Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator+= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		op0 += op1;
		Assert::AreEqual(op0.m[0], fv[0] + op1.m[0], "Operator+=(Mat3) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1], fv[1] + op1.m[1], "Operator+=(Mat3) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2], fv[2] + op1.m[2], "Operator+=(Mat3) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3], fv[3] + op1.m[3], "Operator+=(Mat3) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4], fv[4] + op1.m[4], "Operator+=(Mat3) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5], fv[5] + op1.m[5], "Operator+=(Mat3) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6], fv[6] + op1.m[6], "Operator+=(Mat3) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7], fv[7] + op1.m[7], "Operator+=(Mat3) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8], fv[8] + op1.m[8], "Operator+=(Mat3) Failed 8", __FILE__, __LINE__);
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		op0 += 10.0f;
		Assert::AreEqual(op0.m[0], fv[0] + 10.0f, "Operator+=(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1], fv[1] + 10.0f, "Operator+=(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2], fv[2] + 10.0f, "Operator+=(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3], fv[3] + 10.0f, "Operator+=(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4], fv[4] + 10.0f, "Operator+=(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5], fv[5] + 10.0f, "Operator+=(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6], fv[6] + 10.0f, "Operator+=(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7], fv[7] + 10.0f, "Operator+=(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8], fv[8] + 10.0f, "Operator+=(float) Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator- -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];		
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		copy = op1 - op0;
		Assert::AreEqual(copy.m[0], op1.m[0] - op0.m[0], "Operator-(Mat3) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op1.m[1] - op0.m[1], "Operator-(Mat3) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op1.m[2] - op0.m[2], "Operator-(Mat3) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op1.m[3] - op0.m[3], "Operator-(Mat3) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op1.m[4] - op0.m[4], "Operator-(Mat3) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op1.m[5] - op0.m[5], "Operator-(Mat3) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op1.m[6] - op0.m[6], "Operator-(Mat3) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op1.m[7] - op0.m[7], "Operator-(Mat3) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op1.m[8] - op0.m[8], "Operator-(Mat3) Failed 8", __FILE__, __LINE__);
		copy = op1 - 10.0f;
		Assert::AreEqual(copy.m[0], op1.m[0] - 10.0f, "Operator-(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op1.m[1] - 10.0f, "Operator-(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op1.m[2] - 10.0f, "Operator-(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op1.m[3] - 10.0f, "Operator-(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op1.m[4] - 10.0f, "Operator-(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op1.m[5] - 10.0f, "Operator-(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op1.m[6] - 10.0f, "Operator-(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op1.m[7] - 10.0f, "Operator-(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op1.m[8] - 10.0f, "Operator-(float) Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator-= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		op1 -= op0;
		Assert::AreEqual(op1.m[0], fu[0] - op0.m[0], "Operator-=(Mat3) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[1], fu[1] - op0.m[1], "Operator-=(Mat3) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[2], fu[2] - op0.m[2], "Operator-=(Mat3) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[3], fu[3] - op0.m[3], "Operator-=(Mat3) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[4], fu[4] - op0.m[4], "Operator-=(Mat3) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[5], fu[5] - op0.m[5], "Operator-=(Mat3) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[6], fu[6] - op0.m[6], "Operator-=(Mat3) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[7], fu[7] - op0.m[7], "Operator-=(Mat3) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[8], fu[8] - op0.m[8], "Operator-=(Mat3) Failed 8", __FILE__, __LINE__);
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		op1 -= 10.0f;
		Assert::AreEqual(op1.m[0], fu[0] - 10.0f, "Operator-=(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[1], fu[1] - 10.0f, "Operator-=(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[2], fu[2] - 10.0f, "Operator-=(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[3], fu[3] - 10.0f, "Operator-=(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[4], fu[4] - 10.0f, "Operator-=(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[5], fu[5] - 10.0f, "Operator-=(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[6], fu[6] - 10.0f, "Operator-=(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[7], fu[7] - 10.0f, "Operator-=(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[8], fu[8] - 10.0f, "Operator-=(float) Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator* -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		copy = op0 * 10.0f;
		Assert::AreEqual(copy.m[0], op0.m[0] * 10.0f, "Operator* Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op0.m[1] * 10.0f, "Operator* Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op0.m[2] * 10.0f, "Operator* Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op0.m[3] * 10.0f, "Operator* Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op0.m[4] * 10.0f, "Operator* Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op0.m[5] * 10.0f, "Operator* Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op0.m[6] * 10.0f, "Operator* Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op0.m[7] * 10.0f, "Operator* Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op0.m[8] * 10.0f, "Operator* Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator*= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		op0 *= 10.0f;
		Assert::AreEqual(op0.m[0], fv[0] * 10.0f, "Operator*= Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1], fv[1] * 10.0f, "Operator*= Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2], fv[2] * 10.0f, "Operator*= Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3], fv[3] * 10.0f, "Operator*= Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4], fv[4] * 10.0f, "Operator*= Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5], fv[5] * 10.0f, "Operator*= Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6], fv[6] * 10.0f, "Operator*= Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7], fv[7] * 10.0f, "Operator*= Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8], fv[8] * 10.0f, "Operator*= Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator/ -- //
		//----------------//
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		copy = op1 / 10.0f;
		Assert::AreEqual(copy.m[0], op1.m[0] / 10.0f, "Operator/ Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1], op1.m[1] / 10.0f, "Operator/ Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2], op1.m[2] / 10.0f, "Operator/ Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3], op1.m[3] / 10.0f, "Operator/ Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4], op1.m[4] / 10.0f, "Operator/ Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5], op1.m[5] / 10.0f, "Operator/ Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6], op1.m[6] / 10.0f, "Operator/ Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7], op1.m[7] / 10.0f, "Operator/ Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8], op1.m[8] / 10.0f, "Operator/ Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator/= - //
		//----------------//
		// fu --> op1
		op1.m[0] = fu[0]; op1.m[1] = fu[1]; op1.m[2] = fu[2];
		op1.m[3] = fu[3]; op1.m[4] = fu[4]; op1.m[5] = fu[5];
		op1.m[6] = fu[6]; op1.m[7] = fu[7]; op1.m[8] = fu[8];
		op1 /= 10.0f;
		Assert::AreEqual(op1.m[0], fu[0] / 10.0f, "Operator/= Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[1], fu[1] / 10.0f, "Operator/= Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[2], fu[2] / 10.0f, "Operator/= Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[3], fu[3] / 10.0f, "Operator/= Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[4], fu[4] / 10.0f, "Operator/= Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[5], fu[5] / 10.0f, "Operator/= Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[6], fu[6] / 10.0f, "Operator/= Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[7], fu[7] / 10.0f, "Operator/= Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[8], fu[8] / 10.0f, "Operator/= Failed 8", __FILE__, __LINE__);

		//-----------------//
		// -- Operator== - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		// fv --> op1
		op1.m[0] = fv[0]; op1.m[1] = fv[1]; op1.m[2] = fv[2];
		op1.m[3] = fv[3]; op1.m[4] = fv[4]; op1.m[5] = fv[5];
		op1.m[6] = fv[6]; op1.m[7] = fv[7]; op1.m[8] = fv[8];
		worked = (op0 == op1);
		Assert::AreEqual(true, worked, "Operator== Failed", __FILE__, __LINE__);
		op0.m[8] = 0.5f; op1.m[8] = 1.5f;
		worked = (op0 == op1);
		Assert::AreEqual(false, worked, "Operator== Failed", __FILE__, __LINE__);

		//-----------------//
		// -- Operator!= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0]; op0.m[1] = fv[1]; op0.m[2] = fv[2];
		op0.m[3] = fv[3]; op0.m[4] = fv[4]; op0.m[5] = fv[5];
		op0.m[6] = fv[6]; op0.m[7] = fv[7]; op0.m[8] = fv[8];
		// fv --> op1
		op1.m[0] = fv[0]; op1.m[1] = fv[1]; op1.m[2] = fv[2];
		op1.m[3] = fv[3]; op1.m[4] = fv[4]; op1.m[5] = fv[5];
		op1.m[6] = fv[6]; op1.m[7] = fv[7]; op1.m[8] = fv[8];
		worked = (op0 != op1);
		Assert::AreEqual(false, worked, "Operator!= Failed", __FILE__, __LINE__);
		op0.m[8] = 0.5f; op1.m[8] = 1.5f;
		worked = (op0 != op1);
		Assert::AreEqual(true, worked, "Operator!= Failed", __FILE__, __LINE__);

		// Check Identity		
		another_test = Mat3::Identity();

		Assert::AreEqual(another_test.m[0], identity.m[0], "Identity() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], identity.m[1], "Identity() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], identity.m[2], "Identity() Failed 2", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[3], identity.m[3], "Identity() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], identity.m[4], "Identity() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], identity.m[5], "Identity() Failed 5", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[6], identity.m[6], "Identity() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], identity.m[7], "Identity() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], identity.m[8], "Identity() Failed 8", __FILE__, __LINE__);

		//Check Multiply		
		// fv --> test
		test.m[0] = fv[0]; test.m[1] = fv[1]; test.m[2] = fv[2];
		test.m[3] = fv[3]; test.m[4] = fv[4]; test.m[5] = fv[5];
		test.m[6] = fv[6]; test.m[7] = fv[7]; test.m[8] = fv[8];
		// fu --> op1
		another_test.m[0] = fu[0]; another_test.m[1] = fu[1]; another_test.m[2] = fu[2];
		another_test.m[3] = fu[3]; another_test.m[4] = fu[4]; another_test.m[5] = fu[5];
		another_test.m[6] = fu[6]; another_test.m[7] = fu[7]; another_test.m[8] = fu[8];		
		
		another_test = another_test.Multiply(test);

		Assert::AreEqual(another_test.m[0], 300.0f, "Multiply() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], 360.0f, "Multiply() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], 420.0f, "Multiply() Failed 2", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[3], 660.0f, "Multiply() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], 810.0f, "Multiply() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], 960.0f, "Multiply() Failed 5", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[6], 1020.0f, "Multiply() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], 1260.0f, "Multiply() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], 1500.0f, "Multiply() Failed 8", __FILE__, __LINE__);

		//Check Determinant
		// fv --> test
		test.m[0] = fv[0]; test.m[1] = fv[1]; test.m[2] = fv[2];
		test.m[3] = fv[3]; test.m[4] = fv[4]; test.m[5] = fv[5];
		test.m[6] = fv[6]; test.m[7] = fv[7]; test.m[8] = fv[8];

		worked = (0.0f == test.Determinant());
		Assert::AreEqual(true, worked, "Determinant() Failed", __FILE__, __LINE__);
		test.m[0] = 9.0f;
		worked = (-24.0f == test.Determinant());
		Assert::AreEqual(true, worked, "Determinant() Failed", __FILE__, __LINE__);

		// Check Transpose
		float ttemp[9] = { 1.0f, 2.0f, 3.0f,
						           0.0f, 1.0f, 0.0f,
						           0.0f, 0.0f, 1.0f };

		float atemp[9] = { 1.0f, 0.0f, 0.0f,
						           2.0f, 1.0f, 0.0f,
						           3.0f, 0.0f, 1.0f };

		test = Mat3(ttemp);
		another_test = Mat3(atemp);

		test = test.Transpose();

		Assert::AreEqual(another_test.m[0], test.m[0], "Transpose() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], "Transpose() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], "Transpose() Failed 2", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[3], test.m[3], "Transpose() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], "Transpose() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], "Transpose() Failed 5", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[6], test.m[6], "Transpose() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], "Transpose() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], "Transpose() Failed 8", __FILE__, __LINE__);

		// Check Adjoint
		another_test = Mat3(Vec3(37.0f, -66.0f, 17.0f), Vec3(-26.0f, -12.0f, 14.0f), Vec3(-23.0f, 54.0f, -43.0f));

		float temp[9] = { 2.0f, 5.0f, 4.0f,
					            3.0f, 5.0f, 7.0f,
					            0.0f, 2.0f, 1.0f };

		float ad_temp[9]{ -9.0f, 3.0f, 15.0f,
											-3.0f, 2.0f, -2.0f,
											 6.0f,-4.0f, -5.0f };

		another_test = Mat3(ad_temp);

		test = Mat3(temp);
		test = test.Adjoint().Transpose();

		Assert::AreEqual(another_test.m[0], test.m[0], "Adjoint() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], "Adjoint() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], "Adjoint() Failed 2", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[3], test.m[3], "Adjoint() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], "Adjoint() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], "Adjoint() Failed 5", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[6], test.m[6], "Adjoint() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], "Adjoint() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], "Adjoint() Failed 8", __FILE__, __LINE__);

		// Check Inverse
		float itemp[9]{ 1.0f,           -0.333333333333f, -1.6666666666666f,
										0.333333333333f,-0.222222222222f,  0.2222222222222f,
									 -0.66666666666f,  0.444444444444f,  0.5555555555555f };

		another_test = Mat3(itemp);
		test = Mat3(temp);

		test.Inverse();

		Assert::AreEqual(another_test.m[0], test.m[0], 0.00000001f, "Inverse() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00000001f, "Inverse() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00000001f, "Inverse() Failed 2", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[3], test.m[3], 0.00000001f, "Inverse() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00000001f, "Inverse() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00000001f, "Inverse() Failed 5", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[6], test.m[6], 0.00000001f, "Inverse() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00000001f, "Inverse() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00000001f, "Inverse() Failed 8", __FILE__, __LINE__);

		// Check Translate
		another_test = Mat3(Vec3(1.0f, 0.0f, 3.0f), Vec3(0.0f, 1.0f, 3.0f), Vec3(0.0f, 0.0f, 1.0f));
		test = test.Translate(3.0f, 3.0f);		

		Assert::AreEqual(another_test.m[0], test.m[0], 0.00001f, "Translate() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00001f, "Translate() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00001f, "Translate() Failed 2", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[3], test.m[3], 0.00001f, "Translate() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00001f, "Translate() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00001f, "Translate() Failed 5", __FILE__, __LINE__);

		Assert::AreEqual(another_test.m[6], test.m[6], 0.00001f, "Translate() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00001f, "Translate() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00001f, "Translate() Failed 8", __FILE__, __LINE__);

		// Check GetColumn		
		test = Mat3(fv);
		worked = test.GetColum(0) == Vec3(1.0f, 4.0f, 7.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);
		worked = test.GetColum(1) == Vec3(2.0f, 5.0f, 8.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);
		worked = test.GetColum(2) == Vec3(3.0f, 6.0f, 9.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);

		// Check GetLine		
		test = Mat3(fv);
		worked = test.GetLine(0) == Vec3(1.0f, 2.0f, 3.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = test.GetLine(1) == Vec3(4.0f, 5.0f, 6.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = test.GetLine(2) == Vec3(7.0f, 8.0f, 9.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);

		Test::End();
	}

	void Mat4Test() {

		Test::Start(__FUNCTION__);

		Mat4 test;
		Mat4 identity;
		Mat4 copy;
		float temp[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
										   0.0f, 1.0f, 0.0f, 0.0f,
										   0.0f, 0.0f, 1.0f, 0.0f,
										   0.0f, 0.0f, 0.0f, 1.0f };
		float fv[16] = {  1.0f,  2.0f,  3.0f,  4.0f,
										  5.0f,  6.0f,  7.0f,  8.0f,
										  9.0f, 10.0f, 11.0f, 12.0f,
										 13.0f, 14.0f, 15.0f, 16.0f };
		float fu[16] = { 17.0f, 18.0f, 19.0f, 20.0f,
										 21.0f, 22.0f, 23.0f, 24.0f,
										 25.0f, 26.0f, 27.0f, 28.0f,
										 29.0f, 30.0f, 31.0f, 32.0f };
		bool worked = false;

		// Load Identity
		identity.m[0] =  temp[0];  identity.m[1] =  temp[1];  identity.m[2] =  temp[2];  identity.m[3] =  temp[3];
		identity.m[4] =  temp[4];  identity.m[5] =  temp[5];  identity.m[6] =  temp[6];  identity.m[7] =  temp[7];
		identity.m[8] =  temp[8];  identity.m[9] =  temp[9];  identity.m[10] = temp[10]; identity.m[11] = temp[11];
		identity.m[12] = temp[12]; identity.m[13] = temp[13]; identity.m[14] = temp[14]; identity.m[15] = temp[15];

		// Check Constructors		
		Mat4 another_test(temp);
		Assert::AreEqual(another_test.m[0], temp[0], 0.00001f, "Constructor(float*) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], temp[1], 0.00001f, "Constructor(float*) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], temp[2], 0.00001f, "Constructor(float*) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[3], temp[3], 0.00001f, "Constructor(float*) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], temp[4], 0.00001f, "Constructor(float*) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], temp[5], 0.00001f, "Constructor(float*) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[6], temp[6], 0.00001f, "Constructor(float*) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], temp[7], 0.00001f, "Constructor(float*) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], temp[8], 0.00001f, "Constructor(float*) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[9], temp[9], 0.00001f, "Constructor(float*) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[10], temp[10], 0.00001f, "Constructor(float*) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[11], temp[11], 0.00001f, "Constructor(float*) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[12], temp[12], 0.00001f, "Constructor(float*) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[13], temp[13], 0.00001f, "Constructor(float*) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[14], temp[14], 0.00001f, "Constructor(float*) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[15], temp[15], 0.00001f, "Constructor(float*) Failed 15", __FILE__, __LINE__);

		Mat4 con0(100.0f);
		Assert::AreEqual(con0.m[0],  100.0f, 0.00001f, "Constructor(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[1],  100.0f, 0.00001f, "Constructor(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[2],  100.0f, 0.00001f, "Constructor(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[3],  100.0f, 0.00001f, "Constructor(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[4],  100.0f, 0.00001f, "Constructor(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[5],  100.0f, 0.00001f, "Constructor(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[6],  100.0f, 0.00001f, "Constructor(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[7],  100.0f, 0.00001f, "Constructor(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[8],  100.0f, 0.00001f, "Constructor(float) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[9],  100.0f, 0.00001f, "Constructor(float) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[10], 100.0f, 0.00001f, "Constructor(float) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[11], 100.0f, 0.00001f, "Constructor(float) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[12], 100.0f, 0.00001f, "Constructor(float) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[13], 100.0f, 0.00001f, "Constructor(float) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[14], 100.0f, 0.00001f, "Constructor(float) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(con0.m[15], 100.0f, 0.00001f, "Constructor(float) Failed 15", __FILE__, __LINE__);
		
		Mat4 con1;
		// fv --> con1
		con1.m[0]  = fv[0];  con1.m[1]  = fv[1];  con1.m[2]  = fv[2];  con1.m[3]  = fv[3];
		con1.m[4]  = fv[4];  con1.m[5]  = fv[5];  con1.m[6]  = fv[6];  con1.m[7]  = fv[7];
		con1.m[8]  = fv[8];  con1.m[9]  = fv[9];  con1.m[10] = fv[10]; con1.m[11] = fv[11];
		con1.m[12] = fv[12]; con1.m[13] = fv[13]; con1.m[14] = fv[14]; con1.m[15] = fv[15];
		Mat4 con2(con1);
		Assert::AreEqual(con2.m[0],  fv[0], 0.00001f,  "Copy Constructor Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[1],  fv[1], 0.00001f,  "Copy Constructor Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[2],  fv[2], 0.00001f,  "Copy Constructor Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[3],  fv[3], 0.00001f,  "Copy Constructor Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[4],  fv[4], 0.00001f,  "Copy Constructor Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[5],  fv[5], 0.00001f,  "Copy Constructor Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[6],  fv[6], 0.00001f,  "Copy Constructor Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[7],  fv[7], 0.00001f,  "Copy Constructor Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[8],  fv[8], 0.00001f,  "Copy Constructor Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[9],  fv[9], 0.00001f,  "Copy Constructor Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[10], fv[10], 0.00001f, "Copy Constructor Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[11], fv[11], 0.00001f, "Copy Constructor Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[12], fv[12], 0.00001f, "Copy Constructor Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[13], fv[13], 0.00001f, "Copy Constructor Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[14], fv[14], 0.00001f, "Copy Constructor Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(con2.m[15], fv[15], 0.00001f, "Copy Constructor Failed 15", __FILE__, __LINE__);

		/////////////////////////
		// ---- OPERATORS ----///
		/////////////////////////

		//-----------------//
		// -- Operator= -- //
		//----------------//
		Mat4 op0;
		// fv --> op0
		op0.m[0] =  fv[0];  op0.m[1] =  fv[1];  op0.m[2] =  fv[2];  op0.m[3] = fv[3];
		op0.m[4] =  fv[4];  op0.m[5] =  fv[5];  op0.m[6] =  fv[6];  op0.m[7] = fv[7];
		op0.m[8] =  fv[8];  op0.m[9] =  fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		copy = op0;
		Assert::AreEqual(copy.m[0],  fv[0], 0.00001f,  "Operator= Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  fv[1], 0.00001f,  "Operator= Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  fv[2], 0.00001f,  "Operator= Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  fv[3], 0.00001f,  "Operator= Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  fv[4], 0.00001f,  "Operator= Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  fv[5], 0.00001f,  "Operator= Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  fv[6], 0.00001f,  "Operator= Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  fv[7], 0.00001f,  "Operator= Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  fv[8], 0.00001f,  "Operator= Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  fv[9], 0.00001f,  "Operator= Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], fv[10], 0.00001f, "Operator= Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], fv[11], 0.00001f, "Operator= Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], fv[12], 0.00001f, "Operator= Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], fv[13], 0.00001f, "Operator= Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], fv[14], 0.00001f, "Operator= Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], fv[15], 0.00001f, "Operator= Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator+ -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		Mat4 op1;
		// fu --> op1
		op1.m[0]  = fu[0];  op1.m[1]  = fu[1];  op1.m[2]  = fu[2];  op1.m[3]  = fu[3];
		op1.m[4]  = fu[4];  op1.m[5]  = fu[5];  op1.m[6]  = fu[6];  op1.m[7]  = fu[7];
		op1.m[8]  = fu[8];  op1.m[9]  = fu[9];  op1.m[10] = fu[10]; op1.m[11] = fu[11];
		op1.m[12] = fu[12]; op1.m[13] = fu[13]; op1.m[14] = fu[14]; op1.m[15] = fu[15];
		copy = op0 + op1;
		Assert::AreEqual(copy.m[0],  op0.m[0]  + op1.m[0],  0.00001f, "Operator+(Mat4) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  op0.m[1]  + op1.m[1],  0.00001f, "Operator+(Mat4) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  op0.m[2]  + op1.m[2],  0.00001f, "Operator+(Mat4) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  op0.m[3]  + op1.m[3],  0.00001f, "Operator+(Mat4) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  op0.m[4]  + op1.m[4],  0.00001f, "Operator+(Mat4) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  op0.m[5]  + op1.m[5],  0.00001f, "Operator+(Mat4) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  op0.m[6]  + op1.m[6],  0.00001f, "Operator+(Mat4) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  op0.m[7]  + op1.m[7],  0.00001f, "Operator+(Mat4) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  op0.m[8]  + op1.m[8],  0.00001f, "Operator+(Mat4) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  op0.m[9]  + op1.m[9],  0.00001f, "Operator+(Mat4) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], op0.m[10] + op1.m[10], 0.00001f, "Operator+(Mat4) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], op0.m[11] + op1.m[11], 0.00001f, "Operator+(Mat4) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], op0.m[12] + op1.m[12], 0.00001f, "Operator+(Mat4) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], op0.m[13] + op1.m[13], 0.00001f, "Operator+(Mat4) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], op0.m[14] + op1.m[14], 0.00001f, "Operator+(Mat4) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], op0.m[15] + op1.m[15], 0.00001f, "Operator+(Mat4) Failed 15", __FILE__, __LINE__);
		copy = op0 + 10.0f;
		Assert::AreEqual(copy.m[0],  op0.m[0]  + 10.0f, 0.00001f, "Operator+(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  op0.m[1]  + 10.0f, 0.00001f, "Operator+(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  op0.m[2]  + 10.0f, 0.00001f, "Operator+(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  op0.m[3]  + 10.0f, 0.00001f, "Operator+(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  op0.m[4]  + 10.0f, 0.00001f, "Operator+(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  op0.m[5]  + 10.0f, 0.00001f, "Operator+(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  op0.m[6]  + 10.0f, 0.00001f, "Operator+(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  op0.m[7]  + 10.0f, 0.00001f, "Operator+(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  op0.m[8]  + 10.0f, 0.00001f, "Operator+(float) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  op0.m[9]  + 10.0f, 0.00001f, "Operator+(float) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], op0.m[10] + 10.0f, 0.00001f, "Operator+(float) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], op0.m[11] + 10.0f, 0.00001f, "Operator+(float) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], op0.m[12] + 10.0f, 0.00001f, "Operator+(float) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], op0.m[13] + 10.0f, 0.00001f, "Operator+(float) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], op0.m[14] + 10.0f, 0.00001f, "Operator+(float) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], op0.m[15] + 10.0f, 0.00001f, "Operator+(float) Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator+= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];		
		// fu --> op1
		op1.m[0] = fu[0];  op1.m[1] = fu[1];  op1.m[2] = fu[2];  op1.m[3] = fu[3];
		op1.m[4] = fu[4];  op1.m[5] = fu[5];  op1.m[6] = fu[6];  op1.m[7] = fu[7];
		op1.m[8] = fu[8];  op1.m[9] = fu[9];  op1.m[10] = fu[10]; op1.m[11] = fu[11];
		op1.m[12] = fu[12]; op1.m[13] = fu[13]; op1.m[14] = fu[14]; op1.m[15] = fu[15];
		op0 += op1;
		Assert::AreEqual(op0.m[0],  fv[0]  + op1.m[0],  0.00001f, "Operator+=(Mat4) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1],  fv[1]  + op1.m[1],  0.00001f, "Operator+=(Mat4) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2],  fv[2]  + op1.m[2],  0.00001f, "Operator+=(Mat4) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3],  fv[3]  + op1.m[3],  0.00001f, "Operator+=(Mat4) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4],  fv[4]  + op1.m[4],  0.00001f, "Operator+=(Mat4) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5],  fv[5]  + op1.m[5],  0.00001f, "Operator+=(Mat4) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6],  fv[6]  + op1.m[6],  0.00001f, "Operator+=(Mat4) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7],  fv[7]  + op1.m[7],  0.00001f, "Operator+=(Mat4) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8],  fv[8]  + op1.m[8],  0.00001f, "Operator+=(Mat4) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[9],  fv[9]  + op1.m[9],  0.00001f, "Operator+=(Mat4) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[10], fv[10] + op1.m[10], 0.00001f, "Operator+=(Mat4) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[11], fv[11] + op1.m[11], 0.00001f, "Operator+=(Mat4) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[12], fv[12] + op1.m[12], 0.00001f, "Operator+=(Mat4) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[13], fv[13] + op1.m[13], 0.00001f, "Operator+=(Mat4) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[14], fv[14] + op1.m[14], 0.00001f, "Operator+=(Mat4) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[15], fv[15] + op1.m[15], 0.00001f, "Operator+=(Mat4) Failed 15", __FILE__, __LINE__);
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		op0 += 10.0f;
		Assert::AreEqual(op0.m[0],  fv[0]  + 10.0f, 0.00001f, "Operator+=(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1],  fv[1]  + 10.0f, 0.00001f, "Operator+=(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2],  fv[2]  + 10.0f, 0.00001f, "Operator+=(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3],  fv[3]  + 10.0f, 0.00001f, "Operator+=(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4],  fv[4]  + 10.0f, 0.00001f, "Operator+=(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5],  fv[5]  + 10.0f, 0.00001f, "Operator+=(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6],  fv[6]  + 10.0f, 0.00001f, "Operator+=(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7],  fv[7]  + 10.0f, 0.00001f, "Operator+=(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8],  fv[8]  + 10.0f, 0.00001f, "Operator+=(float) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[9],  fv[9]  + 10.0f, 0.00001f, "Operator+=(float) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[10], fv[10] + 10.0f, 0.00001f, "Operator+=(float) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[11], fv[11] + 10.0f, 0.00001f, "Operator+=(float) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[12], fv[12] + 10.0f, 0.00001f, "Operator+=(float) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[13], fv[13] + 10.0f, 0.00001f, "Operator+=(float) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[14], fv[14] + 10.0f, 0.00001f, "Operator+=(float) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[15], fv[15] + 10.0f, 0.00001f, "Operator+=(float) Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator- -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];		
		// fu --> op1
		op1.m[0] = fu[0];  op1.m[1] = fu[1];  op1.m[2] = fu[2];  op1.m[3] = fu[3];
		op1.m[4] = fu[4];  op1.m[5] = fu[5];  op1.m[6] = fu[6];  op1.m[7] = fu[7];
		op1.m[8] = fu[8];  op1.m[9] = fu[9];  op1.m[10] = fu[10]; op1.m[11] = fu[11];
		op1.m[12] = fu[12]; op1.m[13] = fu[13]; op1.m[14] = fu[14]; op1.m[15] = fu[15];
		copy = op1 - op0;
		Assert::AreEqual(copy.m[0],  op1.m[0]  - op0.m[0], 0.00001f,  "Operator-(Mat4) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  op1.m[1]  - op0.m[1], 0.00001f,  "Operator-(Mat4) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  op1.m[2]  - op0.m[2], 0.00001f,  "Operator-(Mat4) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  op1.m[3]  - op0.m[3], 0.00001f,  "Operator-(Mat4) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  op1.m[4]  - op0.m[4], 0.00001f,  "Operator-(Mat4) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  op1.m[5]  - op0.m[5], 0.00001f,  "Operator-(Mat4) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  op1.m[6]  - op0.m[6], 0.00001f,  "Operator-(Mat4) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  op1.m[7]  - op0.m[7], 0.00001f,  "Operator-(Mat4) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  op1.m[8]  - op0.m[8], 0.00001f,  "Operator-(Mat4) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  op1.m[9]  - op0.m[9], 0.00001f,  "Operator-(Mat4) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], op1.m[10] - op0.m[10], 0.00001f, "Operator-(Mat4) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], op1.m[11] - op0.m[11], 0.00001f, "Operator-(Mat4) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], op1.m[12] - op0.m[12], 0.00001f, "Operator-(Mat4) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], op1.m[13] - op0.m[13], 0.00001f, "Operator-(Mat4) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], op1.m[14] - op0.m[14], 0.00001f, "Operator-(Mat4) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], op1.m[15] - op0.m[15], 0.00001f, "Operator-(Mat4) Failed 15", __FILE__, __LINE__);
		copy = op1 - 10.0f;
		Assert::AreEqual(copy.m[0],  op1.m[0]  - 10.0f, 0.00001f, "Operator-(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  op1.m[1]  - 10.0f, 0.00001f, "Operator-(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  op1.m[2]  - 10.0f, 0.00001f, "Operator-(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  op1.m[3]  - 10.0f, 0.00001f, "Operator-(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  op1.m[4]  - 10.0f, 0.00001f, "Operator-(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  op1.m[5]  - 10.0f, 0.00001f, "Operator-(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  op1.m[6]  - 10.0f, 0.00001f, "Operator-(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  op1.m[7]  - 10.0f, 0.00001f, "Operator-(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  op1.m[8]  - 10.0f, 0.00001f, "Operator-(float) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  op1.m[9]  - 10.0f, 0.00001f, "Operator-(float) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], op1.m[10] - 10.0f, 0.00001f, "Operator-(float) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], op1.m[11] - 10.0f, 0.00001f, "Operator-(float) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], op1.m[12] - 10.0f, 0.00001f, "Operator-(float) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], op1.m[13] - 10.0f, 0.00001f, "Operator-(float) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], op1.m[14] - 10.0f, 0.00001f, "Operator-(float) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], op1.m[15] - 10.0f, 0.00001f, "Operator-(float) Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator-= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		// fu --> op1
		op1.m[0] = fu[0];  op1.m[1] = fu[1];  op1.m[2] = fu[2];  op1.m[3] = fu[3];
		op1.m[4] = fu[4];  op1.m[5] = fu[5];  op1.m[6] = fu[6];  op1.m[7] = fu[7];
		op1.m[8] = fu[8];  op1.m[9] = fu[9];  op1.m[10] = fu[10]; op1.m[11] = fu[11];
		op1.m[12] = fu[12]; op1.m[13] = fu[13]; op1.m[14] = fu[14]; op1.m[15] = fu[15];
		op1 -= op0;
		Assert::AreEqual(op1.m[0],  fu[0]  - op0.m[0], 0.00001f,  "Operator-=(Mat4) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[1],  fu[1]  - op0.m[1], 0.00001f,  "Operator-=(Mat4) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[2],  fu[2]  - op0.m[2], 0.00001f,  "Operator-=(Mat4) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[3],  fu[3]  - op0.m[3], 0.00001f,  "Operator-=(Mat4) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[4],  fu[4]  - op0.m[4], 0.00001f,  "Operator-=(Mat4) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[5],  fu[5]  - op0.m[5], 0.00001f,  "Operator-=(Mat4) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[6],  fu[6]  - op0.m[6], 0.00001f,  "Operator-=(Mat4) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[7],  fu[7]  - op0.m[7], 0.00001f,  "Operator-=(Mat4) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[8],  fu[8]  - op0.m[8], 0.00001f,  "Operator-=(Mat4) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[9],  fu[9]  - op0.m[9], 0.00001f,  "Operator-=(Mat4) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[10], fu[10] - op0.m[10], 0.00001f, "Operator-=(Mat4) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[11], fu[11] - op0.m[11], 0.00001f, "Operator-=(Mat4) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[12], fu[12] - op0.m[12], 0.00001f, "Operator-=(Mat4) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[13], fu[13] - op0.m[13], 0.00001f, "Operator-=(Mat4) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[14], fu[14] - op0.m[14], 0.00001f, "Operator-=(Mat4) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[15], fu[15] - op0.m[15], 0.00001f, "Operator-=(Mat4) Failed 15", __FILE__, __LINE__);
		// fu --> op1
		op1.m[0] = fu[0];  op1.m[1] = fu[1];  op1.m[2] = fu[2];  op1.m[3] = fu[3];
		op1.m[4] = fu[4];  op1.m[5] = fu[5];  op1.m[6] = fu[6];  op1.m[7] = fu[7];
		op1.m[8] = fu[8];  op1.m[9] = fu[9];  op1.m[10] = fu[10]; op1.m[11] = fu[11];
		op1.m[12] = fu[12]; op1.m[13] = fu[13]; op1.m[14] = fu[14]; op1.m[15] = fu[15];
		op1 -= 10.0f;
		Assert::AreEqual(op1.m[0],  fu[0]  - 10.0f, 0.00001f, "Operator-=(float) Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[1],  fu[1]  - 10.0f, 0.00001f, "Operator-=(float) Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[2],  fu[2]  - 10.0f, 0.00001f, "Operator-=(float) Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[3],  fu[3]  - 10.0f, 0.00001f, "Operator-=(float) Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[4],  fu[4]  - 10.0f, 0.00001f, "Operator-=(float) Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[5],  fu[5]  - 10.0f, 0.00001f, "Operator-=(float) Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[6],  fu[6]  - 10.0f, 0.00001f, "Operator-=(float) Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[7],  fu[7]  - 10.0f, 0.00001f, "Operator-=(float) Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[8],  fu[8]  - 10.0f, 0.00001f, "Operator-=(float) Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[9],  fu[9]  - 10.0f, 0.00001f, "Operator-=(float) Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[10], fu[10] - 10.0f, 0.00001f, "Operator-=(float) Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[11], fu[11] - 10.0f, 0.00001f, "Operator-=(float) Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[12], fu[12] - 10.0f, 0.00001f, "Operator-=(float) Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[13], fu[13] - 10.0f, 0.00001f, "Operator-=(float) Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[14], fu[14] - 10.0f, 0.00001f, "Operator-=(float) Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(op1.m[15], fu[15] - 10.0f, 0.00001f, "Operator-=(float) Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator*= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];		
		op0 *= 10.0f;
		Assert::AreEqual(op0.m[0],  fv[0]  * 10.0f, 0.00001f, "Operator*= Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1],  fv[1]  * 10.0f, 0.00001f, "Operator*= Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2],  fv[2]  * 10.0f, 0.00001f, "Operator*= Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3],  fv[3]  * 10.0f, 0.00001f, "Operator*= Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4],  fv[4]  * 10.0f, 0.00001f, "Operator*= Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5],  fv[5]  * 10.0f, 0.00001f, "Operator*= Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6],  fv[6]  * 10.0f, 0.00001f, "Operator*= Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7],  fv[7]  * 10.0f, 0.00001f, "Operator*= Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8],  fv[8]  * 10.0f, 0.00001f, "Operator*= Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[9],  fv[9]  * 10.0f, 0.00001f, "Operator*= Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[10], fv[10] * 10.0f, 0.00001f, "Operator*= Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[11], fv[11] * 10.0f, 0.00001f, "Operator*= Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[12], fv[12] * 10.0f, 0.00001f, "Operator*= Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[13], fv[13] * 10.0f, 0.00001f, "Operator*= Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[14], fv[14] * 10.0f, 0.00001f, "Operator*= Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[15], fv[15] * 10.0f, 0.00001f, "Operator*= Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator* -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];		
		copy = op0 * 10.0f;
		Assert::AreEqual(copy.m[0],  op0.m[0]  * 10.0f, 0.00001f, "Operator* Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  op0.m[1]  * 10.0f, 0.00001f, "Operator* Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  op0.m[2]  * 10.0f, 0.00001f, "Operator* Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  op0.m[3]  * 10.0f, 0.00001f, "Operator* Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  op0.m[4]  * 10.0f, 0.00001f, "Operator* Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  op0.m[5]  * 10.0f, 0.00001f, "Operator* Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  op0.m[6]  * 10.0f, 0.00001f, "Operator* Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  op0.m[7]  * 10.0f, 0.00001f, "Operator* Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  op0.m[8]  * 10.0f, 0.00001f, "Operator* Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  op0.m[9]  * 10.0f, 0.00001f, "Operator* Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], op0.m[10] * 10.0f, 0.00001f, "Operator* Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], op0.m[11] * 10.0f, 0.00001f, "Operator* Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], op0.m[12] * 10.0f, 0.00001f, "Operator* Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], op0.m[13] * 10.0f, 0.00001f, "Operator* Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], op0.m[14] * 10.0f, 0.00001f, "Operator* Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], op0.m[15] * 10.0f, 0.00001f, "Operator* Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator/= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		op0 /= 10.0f;
		Assert::AreEqual(op0.m[0],  fv[0]  / 10.0f, 0.00001f, "Operator/= Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[1],  fv[1]  / 10.0f, 0.00001f, "Operator/= Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[2],  fv[2]  / 10.0f, 0.00001f, "Operator/= Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[3],  fv[3]  / 10.0f, 0.00001f, "Operator/= Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[4],  fv[4]  / 10.0f, 0.00001f, "Operator/= Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[5],  fv[5]  / 10.0f, 0.00001f, "Operator/= Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[6],  fv[6]  / 10.0f, 0.00001f, "Operator/= Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[7],  fv[7]  / 10.0f, 0.00001f, "Operator/= Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[8],  fv[8]  / 10.0f, 0.00001f, "Operator/= Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[9],  fv[9]  / 10.0f, 0.00001f, "Operator/= Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[10], fv[10] / 10.0f, 0.00001f, "Operator/= Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[11], fv[11] / 10.0f, 0.00001f, "Operator/= Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[12], fv[12] / 10.0f, 0.00001f, "Operator/= Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[13], fv[13] / 10.0f, 0.00001f, "Operator/= Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[14], fv[14] / 10.0f, 0.00001f, "Operator/= Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(op0.m[15], fv[15] / 10.0f, 0.00001f, "Operator/= Failed 15", __FILE__, __LINE__);

		//-----------------//
		// -- Operator/ -- //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		copy = op0 / 10.0f;
		Assert::AreEqual(copy.m[0],  op0.m[0]  / 10.0f, 0.00001f, "Operator/ Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],  op0.m[1]  / 10.0f, 0.00001f, "Operator/ Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],  op0.m[2]  / 10.0f, 0.00001f, "Operator/ Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],  op0.m[3]  / 10.0f, 0.00001f, "Operator/ Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],  op0.m[4]  / 10.0f, 0.00001f, "Operator/ Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],  op0.m[5]  / 10.0f, 0.00001f, "Operator/ Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],  op0.m[6]  / 10.0f, 0.00001f, "Operator/ Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],  op0.m[7]  / 10.0f, 0.00001f, "Operator/ Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],  op0.m[8]  / 10.0f, 0.00001f, "Operator/ Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  op0.m[9]  / 10.0f, 0.00001f, "Operator/ Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], op0.m[10] / 10.0f, 0.00001f, "Operator/ Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], op0.m[11] / 10.0f, 0.00001f, "Operator/ Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], op0.m[12] / 10.0f, 0.00001f, "Operator/ Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], op0.m[13] / 10.0f, 0.00001f, "Operator/ Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], op0.m[14] / 10.0f, 0.00001f, "Operator/ Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], op0.m[15] / 10.0f, 0.00001f, "Operator/ Failed 15", __FILE__, __LINE__);
		
		//-----------------//
		// -- Operator== - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		// fv --> op1		
		op1.m[0]  = fv[0];  op1.m[1]  = fv[1];  op1.m[2]  = fv[2];  op1.m[3] =  fv[3];
		op1.m[4]  = fv[4];  op1.m[5]  = fv[5];  op1.m[6]  = fv[6];  op1.m[7] =  fv[7];
		op1.m[8]  = fv[8];  op1.m[9]  = fv[9];  op1.m[10] = fv[10]; op1.m[11] = fv[11];
		op1.m[12] = fv[12]; op1.m[13] = fv[13]; op1.m[14] = fv[14]; op1.m[15] = fv[15];
		worked = (op0 == op1);
		Assert::AreEqual(true, worked, "Operator== Failed", __FILE__, __LINE__);
		op0.m[15] = 0.5f; op1.m[15] = 1.5f;
		worked = (op0 == op1);
		Assert::AreEqual(false, worked, "Operator== Failed", __FILE__, __LINE__);

		//-----------------//
		// -- Operator!= - //
		//----------------//
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		// fv --> op1		
		op1.m[0] = fv[0];  op1.m[1] = fv[1];  op1.m[2] = fv[2];  op1.m[3] = fv[3];
		op1.m[4] = fv[4];  op1.m[5] = fv[5];  op1.m[6] = fv[6];  op1.m[7] = fv[7];
		op1.m[8] = fv[8];  op1.m[9] = fv[9];  op1.m[10] = fv[10]; op1.m[11] = fv[11];
		op1.m[12] = fv[12]; op1.m[13] = fv[13]; op1.m[14] = fv[14]; op1.m[15] = fv[15];
		worked = (op0 != op1);
		Assert::AreEqual(false, worked, "Operator!= Failed", __FILE__, __LINE__);
		op0.m[15] = 0.5f; op1.m[15] = 1.5f;
		worked = (op0 != op1);
		Assert::AreEqual(true, worked, "Operator!= Failed", __FILE__, __LINE__);


		// Check Identity
		worked = test.Identity() == another_test;
		Assert::AreEqual(true, worked, "Identity() Failed", __FILE__, __LINE__);

		// Check Multiply
		for (int i = 0; i < 15; ++i) { temp[i] = 3.0f; }
		another_test = Mat4(temp);
		test = Mat4(3.0f);
		test = test.Multiply(test.Identity());
		for (int i = 0; i < 15; ++i) {
			Assert::AreEqual(test.m[i], another_test.m[i], "Multiply() Failed", __FILE__, __LINE__);
		}
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];		
		// fu --> op1
		op1.m[0] = fu[0];  op1.m[1] = fu[1];  op1.m[2] = fu[2];  op1.m[3] = fu[3];
		op1.m[4] = fu[4];  op1.m[5] = fu[5];  op1.m[6] = fu[6];  op1.m[7] = fu[7];
		op1.m[8] = fu[8];  op1.m[9] = fu[9];  op1.m[10] = fu[10]; op1.m[11] = fu[11];
		op1.m[12] = fu[12]; op1.m[13] = fu[13]; op1.m[14] = fu[14]; op1.m[15] = fu[15];
    copy = op0.Multiply(op1);
		Assert::AreEqual(copy.m[0],   250.0f, 0.00001f, "Multiply() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[1],   260.0f, 0.00001f, "Multiply() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[2],   270.0f, 0.00001f, "Multiply() Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[3],   280.0f, 0.00001f, "Multiply() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[4],   618.0f, 0.00001f, "Multiply() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[5],   644.0f, 0.00001f, "Multiply() Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[6],   670.0f, 0.00001f, "Multiply() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[7],   696.0f, 0.00001f, "Multiply() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[8],   986.0f, 0.00001f, "Multiply() Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[9],  1028.0f, 0.00001f, "Multiply() Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[10], 1070.0f, 0.00001f, "Multiply() Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[11], 1112.0f, 0.00001f, "Multiply() Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[12], 1354.0f, 0.00001f, "Multiply() Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[13], 1412.0f, 0.00001f, "Multiply() Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[14], 1470.0f, 0.00001f, "Multiply() Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(copy.m[15], 1528.0f, 0.00001f, "Multiply() Failed 15", __FILE__, __LINE__);


		// Check Determinant
		worked = 0.0f == test.Determinant();
		Assert::AreEqual(true, worked, "Determinant() Failed", __FILE__, __LINE__);
		float det_temp[16]{ 4.0f, 5.0f, 8.0f, 2.0f,
							7.0f, 6.0f, 5.0f, 6.0f,
							8.0f, 7.0f, 8.0f, 7.0f,
							1.0f, 2.0f, 4.0f, 2.0f };
		test = Mat4(det_temp);
		worked = -45.0f == test.Determinant();
		Assert::AreEqual(true, worked, "Determinant() Failed", __FILE__, __LINE__);

		// Check Adjoint
		float adj_temp[16]{ 0.0f, -1.0f, 0.0f, 5.0f,
							3.0f, -2.0f, 7.0f, 0.0f,
							-2.0f, 7.0f, -2.0f, -5.0f,
							9.0f, -8.0f, 3.0f, -2.0f };
		another_test = Mat4(adj_temp);
		test = another_test.Adjoint();

		Assert::AreEqual(340.0f, test.m[0], 0.00001f, "Adjoint() Failed 0", __FILE__, __LINE__);
		Assert::AreEqual(-6.0f,  test.m[1], 0.00001f, "Adjoint() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(264.0f, test.m[2], 0.00001f, "Adjoint() Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(190.0f, test.m[3], 0.00001f, "Adjoint() Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(286.0f, test.m[4], 0.00001f, "Adjoint() Failed 1", __FILE__, __LINE__);
		Assert::AreEqual(60.0f,  test.m[5], 0.00001f, "Adjoint() Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(270.0f, test.m[6], 0.00001f, "Adjoint() Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(40.0f,  test.m[7], 0.00001f, "Adjoint() Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(-64.0f, test.m[8], 0.00001f, "Adjoint() Failed 2", __FILE__, __LINE__);
		Assert::AreEqual(186.0f, test.m[9], 0.00001f, "Adjoint() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(-36.0f, test.m[10], 0.00001f, "Adjoint() Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(-70.0f, test.m[11], 0.00001f, "Adjoint() Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(290.0f, test.m[12], 0.00001f, "Adjoint() Failed 3", __FILE__, __LINE__);
		Assert::AreEqual(12.0f,  test.m[13], 0.00001f, "Adjoint() Failed 7", __FILE__, __LINE__);	
		Assert::AreEqual(54.0f,  test.m[14], 0.00001f, "Adjoint() Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(8.0f,   test.m[15], 0.00001f, "Adjoint() Failed 15", __FILE__, __LINE__);

		// Check Transpose
		float trans_temp[16]{ 0.0f, -3.0f,  0.0f, 0.0f,
							 -0.0f,  0.0f,  0.0f, 0.0f,
							  1.0f,  0.0f, -0.0f, 0.0f,
							  15.0f, 0.0f, -0.0f, 0.0f };

		float t_temp[16]{ 0.0f, -0.0f,  1.0f, 15.0f,
							  -3.0f, 0.0f,  0.0f, 0.0f,
							  0.0f,  0.0f, -0.0f, 0.0f,
							  0.0f, 0.0f, -0.0f, 0.0f };
		another_test = Mat4(trans_temp);
		another_test = another_test.Transpose();
		test = Mat4(t_temp);
		for (int i = 0; i < 16; ++i) {
			Assert::AreEqual(another_test.m[i], test.m[i], "Transpose() Failed", __FILE__, __LINE__);
		}

		// Check Inverse
		float inv_emp[16]{ 2.0f,  0.0f,  2.0f, 4.0f,
						   6.0f,  0.0f,  0.0f, 1.0f,
						   0.0f,  0.0f,  2.0f, 4.0f,
						   0.0f,  3.0f,  0.0f, 0.0f };

		float inv_tmp[16]{ 0.5f, -0.0f,  -0.5f, 0.0f,
						   0.0f,   0.0f,  0.0f, 0.333333f,
						   6.0f,  -2.0f, -5.5f, 0.0f,
						   -3.0f,  1.0f,  3.0f, 0.0f };

		another_test = Mat4(inv_tmp);
		test = Mat4(inv_emp);
		Mat4 more = test.Adjoint().Transpose();
		Assert::AreEqual(-6,  more.m[0], 0.00001f, "Adjoint2 Failed 0 ", __FILE__, __LINE__);
		Assert::AreEqual(0,   more.m[1], 0.00001f, "Adjoint2  Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(-72, more.m[2], 0.00001f, "Adjoint2  Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(36,  more.m[3], 0.00001f, "Adjoint2  Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(0,   more.m[4], 0.00001f, "Adjoint2  Failed 1 ", __FILE__, __LINE__);
		Assert::AreEqual(0,   more.m[5], 0.00001f, "Adjoint2  Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(24,  more.m[6], 0.00001f, "Adjoint2  Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(-12, more.m[7], 0.00001f, "Adjoint2  Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(6,		more.m[8], 0.00001f, "Adjoint2  Failed 2 ", __FILE__, __LINE__);
		Assert::AreEqual(0,		more.m[9], 0.00001f, "Adjoint2  Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(66,	more.m[10], 0.00001f, "Adjoint2  Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(-36, more.m[11], 0.00001f, "Adjoint2  Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(0,   more.m[12], 0.00001f, "Adjoint2  Failed 3 ", __FILE__, __LINE__);
		Assert::AreEqual(-4,  more.m[13], 0.00001f, "Adjoint2  Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(0,   more.m[14], 0.00001f, "Adjoint2  Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(0,   more.m[15], 0.00001f, "Adjoint2  Failed 15", __FILE__, __LINE__);

		test.Inverse();

		Assert::AreEqual(another_test.m[0], test.m[0], 0.00001f, "Inverse Failed 0 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00001f, "Inverse Failed 1 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00001f, "Inverse Failed 2 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[3], test.m[3], 0.00001f, "Inverse Failed 3 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00001f, "Inverse Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00001f, "Inverse Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[6], test.m[6], 0.00001f, "Inverse Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00001f, "Inverse Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00001f, "Inverse Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[9], test.m[9], 0.00001f, "Inverse Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[10], test.m[10], 0.00001f, "Inverse Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[11], test.m[11], 0.00001f, "Inverse Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[12], test.m[12], 0.00001f, "Inverse Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[13], test.m[13], 0.00001f, "Inverse Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[14], test.m[14], 0.00001f, "Inverse Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[15], test.m[15], 0.00001f, "Inverse Failed 15", __FILE__, __LINE__);


		// Check Translate
		float translate_temp[16]{ 1.0f, 0.0f, 0.0f, 0.0f,
								  0.0f, 1.0f, 0.0f, 0.0f,
								  0.0f, 0.0f, 1.0f, 0.0f,
								  3.0f, 3.0f, 3.0f, 1.0f };
		another_test = Mat4(translate_temp);
		test = test.Translate(3.0f, 3.0f, 3.0f);
		for (int i = 0; i < 16; i++) {
			Assert::AreEqual(another_test.m[i], test.m[i], "Translate() Failed", __FILE__, __LINE__);
		}

		// Check Scale
		float scale_temp[16]{ 3.0f, 0.0f, 0.0f, 0.0f,
							  0.0f, 3.0f, 0.0f, 0.0f,
							  0.0f, 0.0f, 3.0f, 0.0f,
							  0.0f, 0.0f, 0.0f, 1.0f };
		another_test = Mat4(scale_temp);
		worked = another_test == another_test.Scale(3.0f, 3.0f, 3.0f);
		Assert::AreEqual(true, worked, "Scale() Failed", __FILE__, __LINE__);

		// Check RotateX
		float rotate_x_temp[16]{ 1.0f, 0.0f, 0.0f, 0.0f,
								 0.0f, 0.0f, -1.0f, 0.0f,
								 0.0f, 1.0f, 0.0f, 0.0f,
								 0.0f, 0.0f, 0.0f, 1.0f };
		another_test = Mat4(rotate_x_temp);

		test = test.RotateX(1.57079632679f);
		Assert::AreEqual(another_test.m[0], test.m[0], 0.00001f, "RotateInX() Failed 0 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00001f, "RotateInX() Failed 1 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00001f, "RotateInX() Failed 2 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[3], test.m[3], 0.00001f, "RotateInX() Failed 3 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00001f, "RotateInX() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00001f, "RotateInX() Failed3 5", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[6], test.m[6], 0.00001f, "RotateInX() Failed3 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00001f, "RotateInX() Failed3 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00001f, "RotateInX() Failed3 8", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[9], test.m[9], 0.00001f, "RotateInX() Failed3 9", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[10], test.m[10], 0.00001f, "RotateInX() Failed3 10", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[11], test.m[11], 0.00001f, "RotateInX() Failed3 11", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[12], test.m[12], 0.00001f, "RotateInX() Failed3 12", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[13], test.m[13], 0.00001f, "RotateInX() Failed3 13", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[14], test.m[14], 0.00001f, "RotateInX() Failed3 14", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[15], test.m[15], 0.00001f, "RotateInX() Failed3 15", __FILE__, __LINE__);


		// Check RotateY
		float rotate_y_temp[16]{ 0.0f, 0.0f, 1.0f, 0.0f,
								0.0f, 1.0f, 0.0f, 0.0f,
								-1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f };
		another_test = Mat4(rotate_y_temp);
		test = test.RotateY(1.57079632679f);

		Assert::AreEqual(another_test.m[0], test.m[0], 0.00001f, "RotateInY() Failed 0 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00001f, "RotateInY() Failed 1 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00001f, "RotateInY() Failed 2 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[3], test.m[3], 0.00001f, "RotateInY() Failed 3 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00001f, "RotateInY() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00001f, "RotateInY() Failed3 5", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[6], test.m[6], 0.00001f, "RotateInY() Failed3 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00001f, "RotateInY() Failed3 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00001f, "RotateInY() Failed3 8", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[9], test.m[9], 0.00001f, "RotateInY() Failed3 9", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[10], test.m[10], 0.00001f, "RotateInY() Failed3 10", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[11], test.m[11], 0.00001f, "RotateInY() Failed3 11", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[12], test.m[12], 0.00001f, "RotateInY() Failed3 12", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[13], test.m[13], 0.00001f, "RotateInY() Failed3 13", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[14], test.m[14], 0.00001f, "RotateInY() Failed3 14", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[15], test.m[15], 0.00001f, "RotateInY() Failed3 15", __FILE__, __LINE__);


		// Check RotateZ
		float rotate_z_temp[16]{ 0.0f, -1.0f, 0.0f, 0.0f,
								1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 1.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f };
		another_test = Mat4(rotate_z_temp);
		test = test.RotateZ(1.570796f);
		Assert::AreEqual(another_test.m[0], test.m[0], 0.00001f, "RotateInY() Failed 0 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00001f, "RotateInZ() Failed 1 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00001f, "RotateInZ() Failed 2 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[3], test.m[3], 0.00001f, "RotateInZ() Failed 3 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00001f, "RotateInZ() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00001f, "RotateInZ() Failed3 5", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[6], test.m[6], 0.00001f, "RotateInZ() Failed3 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00001f, "RotateInZ() Failed3 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00001f, "RotateInZ() Failed3 8", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[9], test.m[9], 0.00001f, "RotateInZ() Failed3 9", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[10], test.m[10], 0.00001f, "RotateInZ() Failed3 10", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[11], test.m[11], 0.00001f, "RotateInZ() Failed3 11", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[12], test.m[12], 0.00001f, "RotateInZ() Failed3 12", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[13], test.m[13], 0.00001f, "RotateInZ() Failed3 13", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[14], test.m[14], 0.00001f, "RotateInZ() Failed3 14", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[15], test.m[15], 0.00001f, "RotateInZ() Failed3 15", __FILE__, __LINE__);

		// Check GetTransform
		float transformation_temp[16]{ 0.0f, 0.0f, 3.0f, 0.0f,
									  0.0f, -3.0f, 0.0f, 0.0f,
									  3.0f, 0.0f, 0.0f, 0.0f,
									  9.0f, -9.0f, 9.0f, 1.0f };
		another_test = Mat4(transformation_temp);

		test = test.GetTransform(3.0f, 3.0f, 3.0f,
			3.0f, 3.0f, 3.0f,
			1.570796f, 1.570796f, 1.570796f);

		Assert::AreEqual(another_test.m[0], test.m[0], 0.00001f, "GetTransform() Failed 0 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[1], test.m[1], 0.00001f, "GetTransform() Failed 1 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[2], test.m[2], 0.00001f, "GetTransform() Failed 2 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[3], test.m[3], 0.00001f, "GetTransform() Failed 3 ", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[4], test.m[4], 0.00001f, "GetTransform() Failed 4", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[5], test.m[5], 0.00001f, "GetTransform() Failed 5", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[6], test.m[6], 0.00001f, "GetTransform() Failed 6", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[7], test.m[7], 0.00001f, "GetTransform() Failed 7", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[8], test.m[8], 0.00001f, "GetTransform() Failed 8", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[9], test.m[9], 0.00001f, "GetTransform() Failed 9", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[11], test.m[11], 0.00001f, "GetTransform() Failed 11", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[12], test.m[12], 0.00001f, "GetTransform() Failed 12", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[13], test.m[13], 0.00001f, "GetTransform() Failed 13", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[14], test.m[14], 0.00001f, "GetTransform() Failed 14", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[10], test.m[10], 0.00001f, "GetTransform() Failed 10", __FILE__, __LINE__);
		Assert::AreEqual(another_test.m[15], test.m[15], 0.00001f, "GetTransform() Failed 15", __FILE__, __LINE__);

		// TODO: Check PerspectiveMatrix

		// TODO: Check OrthoMatrix

		// Check GetColum
		test = test.Identity();
		worked = test.GetColum(0) == Vec4(1.0f, 0.0f, 0.0f, 0.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);
		worked = test.GetColum(1) == Vec4(0.0f, 1.0f, 0.0f, 0.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);
		worked = test.GetColum(2) == Vec4(0.0f, 0.0f, 1.0f, 0.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);
		worked = test.GetColum(3) == Vec4(0.0f, 0.0f, 0.0f, 1.0f);
		Assert::AreEqual(true, worked, "GetColum() Failed", __FILE__, __LINE__);
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		worked = op0.GetColum(0) == Vec4(1.0f, 5.0f, 9.0f, 13.0f);
		Assert::AreEqual(true, worked, "GetColumn() Failed", __FILE__, __LINE__);
		worked = op0.GetColum(1) == Vec4(2.0f, 6.0f, 10.0f, 14.0f);
		Assert::AreEqual(true, worked, "GetColumn() Failed", __FILE__, __LINE__);
		worked = op0.GetColum(2) == Vec4(3.0f, 7.0f, 11.0f, 15.0f);
		Assert::AreEqual(true, worked, "GetColumn() Failed", __FILE__, __LINE__);
		worked = op0.GetColum(3) == Vec4(4.0f, 8.0f, 12.0f, 16.0f);
		Assert::AreEqual(true, worked, "GetColumn() Failed", __FILE__, __LINE__);


		// Check GetLine
		test = test.Identity();
		worked = test.GetLine(0) == Vec4(1.0f, 0.0f, 0.0f, 0.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = test.GetLine(1) == Vec4(0.0f, 1.0f, 0.0f, 0.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = test.GetLine(2) == Vec4(0.0f, 0.0f, 1.0f, 0.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = test.GetLine(3) == Vec4(0.0f, 0.0f, 0.0f, 1.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		// fv --> op0
		op0.m[0] = fv[0];  op0.m[1] = fv[1];  op0.m[2] = fv[2];  op0.m[3] = fv[3];
		op0.m[4] = fv[4];  op0.m[5] = fv[5];  op0.m[6] = fv[6];  op0.m[7] = fv[7];
		op0.m[8] = fv[8];  op0.m[9] = fv[9];  op0.m[10] = fv[10]; op0.m[11] = fv[11];
		op0.m[12] = fv[12]; op0.m[13] = fv[13]; op0.m[14] = fv[14]; op0.m[15] = fv[15];
		worked = op0.GetLine(0) == Vec4(1.0f, 2.0f, 3.0f, 4.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = op0.GetLine(1) == Vec4(5.0f, 6.0f, 7.0f, 8.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = op0.GetLine(2) == Vec4(9.0f, 10.0f, 11.0f, 12.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);
		worked = op0.GetLine(3) == Vec4(13.0f, 14.0f, 15.0f, 16.0f);
		Assert::AreEqual(true, worked, "GetLine() Failed", __FILE__, __LINE__);

		Test::End();
	}
};
