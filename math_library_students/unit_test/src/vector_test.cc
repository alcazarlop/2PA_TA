#include "vector_2.h"
#include "vector_3.h"
#include "vector_4.h"
#include "unit_test_helpers.h"

// Code by Diego Llorens, Lucas Gonzalez and Gustavo Aranda

namespace UnitTest {
  
  void Vec2Test() {

	  Test::Start(__FUNCTION__);

    Vec2 test;
    Vec2 another_test = Vec2(1.5f, 2.5f);
    Vec2 copy(another_test);
    bool worked = false;

    // Check constructor
    Assert::AreEqual(1.5f, another_test.x, 0.00001f, "Constructor X Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.5f, another_test.y, 0.00001f, "Constructor Y Failed", __FILE__, __LINE__);
    
    // Check copy constructor    
    Assert::AreEqual(1.5f, copy.x, 0.00001f, "Copy constructor X Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.5f, copy.y, 0.00001f, "Copy constructor Y Failed", __FILE__, __LINE__);

    /////////////////////////
    // ---- OPERATORS ----///
    /////////////////////////

    //-----------------//
    // -- Operator= -- //
    //----------------//    
    test = another_test;
    Assert::AreEqual(1.5f, test.x, 0.00001f, "Operator= X Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.5f, test.y, 0.00001f, "Operator= Y Failed", __FILE__, __LINE__);
    test = 1.3f;
    Assert::AreEqual(1.3f, test.x, 0.00001f, "Operator= X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.3f, test.y, 0.00001f, "Operator= Y Failed", __FILE__, __LINE__);

    //-----------------//
    // -- Operator+ -- //
    //----------------//
    test.x = 1.0f; test.y = 2.0f;
    copy = test + another_test;
    Assert::AreEqual(2.5f, copy.x, 0.00001f, "Operator+(Vec2) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.5f, copy.y, 0.00001f, "Operator+(Vec2) Y Failed", __FILE__, __LINE__);
    copy = another_test + 1.0f;
    Assert::AreEqual(2.5f, copy.x, 0.00001f, "Operator+(float) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.5f, copy.y, 0.00001f, "Operator+(float) Y Failed", __FILE__, __LINE__);
    
    //------------------//
    // -- Operator+= -- //
    //-----------------//
    test.x = 1.0f; test.y = 2.0f;
    test += another_test;
    Assert::AreEqual(2.5f, test.x, 0.00001f, "Operator+=(Vec2) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.5f, test.y, 0.00001f, "Operator+=(Vec2) Y Failed", __FILE__, __LINE__);
    test.x = 1.0f; test.y = 2.0f;
    test += 1.0f;
    Assert::AreEqual(2.0f, test.x, 0.00001f, "Operator+=(float) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.y, 0.00001f, "Operator+=(float) Y Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator- --- //
    //-----------------//
    test.x = 1.0f; test.y = 2.0f;
    copy = another_test - test;
    Assert::AreEqual(0.5f, copy.x, 0.00001f, "Operator-(Vec2) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, copy.y, 0.00001f, "Operator-(Vec2) Y Failed", __FILE__, __LINE__);
    copy = another_test - 1.0f;
    Assert::AreEqual(0.5f, copy.x, 0.00001f, "Operator-(float) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, copy.y, 0.00001f, "Operator-(float) Y Failed", __FILE__, __LINE__);
    copy = -another_test;
    Assert::AreEqual(-1.5f, copy.x, 0.00001f, "Operator-(unitary) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(-2.5f, copy.y, 0.00001f, "Operator-(unitary) Y Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator-= -- //
    //-----------------//
    test.x = 3.0f; test.y = 2.0f;
    test -= another_test;
    Assert::AreEqual( 1.5f, test.x, 0.00001f, "Operator-=(Vec2) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(-0.5f, test.y, 0.00001f, "Operator-=(Vec2) Y Failed", __FILE__, __LINE__);
    test.x = 3.0f; test.y = 2.0f;
    test -= 1.0f;
    Assert::AreEqual(2.0f, test.x, 0.00001f, "Operator-=(float) X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-=(float) Y Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator== -- //
    //-----------------//
    test.x = 1.5f; test.y = 2.5f;
    worked = (test == another_test);
    Assert::AreEqual(true, worked, "Operator== Failed", __FILE__, __LINE__);
    test.x = 0.5f; test.y = 1.5f;
    worked = (test == another_test);
    Assert::AreEqual(false, worked, "Operator== Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator!= -- //
    //-----------------//
    test.x = 1.5f; test.y = 2.5f;
    worked = (test != another_test);
    Assert::AreEqual(false, worked, "Operator!= Failed", __FILE__, __LINE__);
    test.x = 0.5f; test.y = 1.5f;
    worked = (test != another_test);
    Assert::AreEqual(true, worked, "Operator!= Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator* --- //
    //-----------------//
    copy = another_test * 2.0f;
    Assert::AreEqual(3.0f, copy.x, 0.00001f, "Operator* X Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, copy.y, 0.00001f, "Operator* Y Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator*= -- //
    //-----------------//
    copy.x = 1.5f; copy.y = 2.5f;
    copy *= 2.0f;
    Assert::AreEqual(3.0f, copy.x, 0.00001f, "Operator*= X Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, copy.y, 0.00001f, "Operator*= Y Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator/ --- //
    //-----------------//
    test.x = 4.0f; test.y = 6.0f;
    copy = test / 2.0f;
    Assert::AreEqual(2.0f, copy.x, 0.00001f, "Operator* X Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, copy.y, 0.00001f, "Operator* Y Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator/= -- //
    //-----------------//
    copy.x = 4.0f; copy.y = 6.0f;
    copy /= 2.0f;
    Assert::AreEqual(2.0f, copy.x, 0.00001f, "Operator* X Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, copy.y, 0.00001f, "Operator* Y Failed", __FILE__, __LINE__);

    //Check Magnitude function.
    Assert::AreEqual(2.91547585f, another_test.Magnitude(), 0.000001f, "Magnitude Failed", __FILE__, __LINE__);

    //Check Normalize function.
    another_test = Vec2(1.5f, 2.5f);
    another_test.Normalize();
    worked = Vec2(0.51449f, 0.85749f) == another_test;
    Assert::AreEqual(0.51449f, another_test.x, 0.00001f, "Normalize X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.85749f, another_test.y, 0.00001f, "Normalize Y Failed", __FILE__, __LINE__);

    //Check Normalized function.
    another_test = Vec2(1.5f, 2.5f);
    worked = Vec2(0.51449f, 0.85749f) == another_test.Normalized();
    another_test = another_test.Normalized();
    Assert::AreEqual(0.51449f, another_test.x, 0.00001f, "Normalized X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.85749f, another_test.y, 0.00001f, "Normalized Y Failed", __FILE__, __LINE__);

    //Check Scale function.
    another_test = Vec2(1.5f, 2.5f);
    another_test.Scale(Vec2(2.0f, 2.0f));
    worked = Vec2(3.0f, 5.0f) == another_test;
    Assert::AreEqual(true, worked, "Scale Failed", __FILE__, __LINE__);

    //Check SqrMagnitude function.
    another_test = Vec2(1.5f, 0.5f);
    Assert::AreEqual(2.5f, another_test.SqrMagnitude(), "SqrMagnitude Failed", __FILE__, __LINE__);
  
    //Check Distance function.
    another_test = Vec2(0.5f, 1.5f);
    test = Vec2(1.5f, 2.5f);
    Assert::AreEqual(1.414214f, Vec2::Distance(test, another_test), 0.0001f, "Distance failed", __FILE__, __LINE__);

    //Check Lerp function.
    another_test = Vec2(0.5f, 1.5f);
    test = Vec2(1.5f, 2.5f);
    another_test = Vec2::Lerp(another_test, test, 0.7f);
    Assert::AreEqual(1.2f, another_test.x, "X value on Lerp failed", __FILE__, __LINE__);
    Assert::AreEqual(2.2f, another_test.y, "Y value on Lerp failed", __FILE__, __LINE__);
    //Not needed to check LerpUnclamped due to is used on Lerp function.

    //Check Dot Product function.
    test = Vec2(1.5f, 2.5f);
    another_test = Vec2(3.0f, 4.0f);
    Assert::AreEqual(14.5f, Vec2::DotProduct(test, another_test), "Dot Product Failed", __FILE__, __LINE__);

	  Test::End();
  }

  void Vec3Test() {

	  Test::Start(__FUNCTION__);

    Vec3 test;
    Vec3 another_test = Vec3(0.5f, 1.5f, 2.5f);
    Vec3 a = Vec3(5.0f, 3.0f, 2.0f);
    Vec3 b = Vec3(3.0f, 2.0f, 1.0f);

    /////////////////////////
    // ---- OPERATORS ----///
    /////////////////////////

    //-----------------//
    // -- Operator+ -- //
    //----------------//
    test = a + b;
    Assert::AreEqual(8.0f, test.x, 0.00001f, "Operator+(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.z, 0.00001f, "Operator+(Vec3) Failed", __FILE__, __LINE__);    

    test = a + 2.0f;
    Assert::AreEqual(7.0f, test.x, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);    

    //-----------------//
    // -- Operator+= --//
    //----------------//
    test = a;
    test += b;
    Assert::AreEqual(8.0f, test.x, 0.00001f, "Operator+=(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+=(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.z, 0.00001f, "Operator+=(Vec3) Failed", __FILE__, __LINE__);    

    test = a;
    test += 2.0f;
    Assert::AreEqual(7.0f, test.x, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);    

    //-----------------//
    // -- Operator- -- //
    //----------------//
    test = a - b;
    Assert::AreEqual(2.0f, test.x, 0.00001f, "Operator-(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator-(Vec3) Failed", __FILE__, __LINE__);    

    test = a - 2.0f;
    Assert::AreEqual(3.0f, test.x, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.z, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);    

    //-------------------//
    // -- Operator-= -- //
    //------------------//
    test = a;
    test -= b;
    Assert::AreEqual(2.0f, test.x, 0.00001f, "Operator-=(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-=(Vec3) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator-=(Vec3) Failed", __FILE__, __LINE__);    

    test = a;
    test -= 2.0f;
    Assert::AreEqual(3.0f, test.x, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.z, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);    

    //-----------------//
    // -- Operator* -- //
    //----------------//
    test = a * 2.0f;
    Assert::AreEqual(10.0f, test.x, 0.00001f, "Operator* Failed", __FILE__, __LINE__);
    Assert::AreEqual(6.0f, test.y, 0.00001f, "Operator* Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator* Failed", __FILE__, __LINE__);    

    //------------------//
    // -- Operator*= -- //
    //-----------------//
    test = a;
    test *= 2.0f;
    Assert::AreEqual(10.0f, test.x, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);
    Assert::AreEqual(6.0f, test.y, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);    

    //-----------------//
    // -- Operator/ -- //
    //----------------//
    test = a / 2.0f;
    Assert::AreEqual(2.5f, test.x, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, test.y, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);    

    //------------------//
    // -- Operator/= -- //
    //-----------------//
    test = a;
    test /= 2.0f;
    Assert::AreEqual(2.5f, test.x, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, test.y, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);    

    //-----------------//
    // -- Operator= -- //
    //----------------//
    test = a;
    Assert::AreEqual(5.0f, test.x, 0.00001f, "Operator= Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.y, 0.00001f, "Operator= Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, test.z, 0.00001f, "Operator= Failed", __FILE__, __LINE__);    

    //Check Magnitude function.
    Assert::AreEqual(2.95804f, another_test.Magnitude(), 0.00001f, "Magnitude Failed", __FILE__, __LINE__);
    //Check Normalize function.
    another_test = Vec3(0.5f, 1.5f, 2.5f);
    another_test.Normalize();
    Assert::AreEqual(0.16903f, another_test.x, 0.00001f, "Normalize X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.50709f, another_test.y, 0.00001f, "Normalize Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.84515f, another_test.z, 0.00001f, "Normalize Z Failed", __FILE__, __LINE__);

    //Check Normalized function.
    another_test = Vec3(0.5f, 1.5f, 2.5f);
    Assert::AreEqual(0.16903f, another_test.Normalized().x, 0.00001f, "Normalized X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.50709f, another_test.Normalized().y, 0.00001f, "Normalized Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.84515f, another_test.Normalized().z, 0.00001f, "Normalized Z Failed", __FILE__, __LINE__);

    //Check Lerp function.
    another_test = Vec3::Lerp(Vec3(0.0f, 1.0f, 2.0f), Vec3(1.0f, 2.0f, 3.0f), 0.5f);
    Assert::AreEqual(0.5f, another_test.x, 0.1f, "Lerp X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, another_test.y, 0.1f, "Lerp Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.5f, another_test.z, 0.1f, "Lerp Z Failed", __FILE__, __LINE__);
    another_test = Vec3::Lerp(Vec3(0.0f, 1.0f, 2.0f), Vec3(1.0f, 2.0f, 3.0f), 1.5f);
    Assert::AreEqual(1.0f, another_test.x, 0.1f, "Lerp X Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, another_test.y, 0.1f, "Lerp Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, another_test.z, 0.1f, "Lerp Z Failed", __FILE__, __LINE__);
    another_test = Vec3::Lerp(Vec3(0.0f, 1.0f, 2.0f), Vec3(1.0f, 2.0f, 3.0f), -1.0f);
    Assert::AreEqual(0.0f, another_test.x, 0.1f, "Lerp X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, another_test.y, 0.1f, "Lerp Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, another_test.z, 0.1f, "Lerp Z Failed", __FILE__, __LINE__);

    //Check LerpUnclamped function.
    another_test = Vec3::LerpUnclamped(Vec3(0.0f, 1.0f, 2.0f), Vec3(1.0f, 2.0f, 3.0f), 0.5f);
    Assert::AreEqual(0.5f, another_test.x, 0.1f, "LerpUnclamped X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, another_test.y, 0.1f, "LerpUnclamped Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.5f, another_test.z, 0.1f, "LerpUnclamped Z Failed", __FILE__, __LINE__);
    another_test = Vec3::LerpUnclamped(Vec3(0.0f, 1.0f, 2.0f), Vec3(1.0f, 2.0f, 3.0f), 1.5f);
    Assert::AreEqual(1.5f, another_test.x, 0.1f, "LerpUnclamped X Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.5f, another_test.y, 0.1f, "LerpUnclamped Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.5f, another_test.z, 0.1f, "LerpUnclamped Z Failed", __FILE__, __LINE__);
    another_test = Vec3::LerpUnclamped(Vec3(0.0f, 1.0f, 2.0f), Vec3(1.0f, 2.0f, 3.0f), -1.0f);
    Assert::AreEqual(-1.0f, another_test.x, 0.1f, "LerpUnclamped X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, another_test.y, 0.1f, "LerpUnclamped Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, another_test.z, 0.1f, "LerpUnclamped Z Failed", __FILE__, __LINE__);

    //Check Dot Product function.
    test = Vec3(0.5f, 1.5f, 2.5f);
    another_test = Vec3(1.0f, 2.0f, 3.0f);
    Assert::AreEqual(11.0f, Vec3::DotProduct(test, another_test), "Dot Product Failed", __FILE__, __LINE__);

    //Check Angle function
    Assert::AreEqual(2.6714f, Vec3::Angle(Vec3(2, -4, -1), Vec3(0, 5, 2)), 0.0001f, "Angle Failed", __FILE__, __LINE__);

    //Check Cross Product function
    another_test = Vec3::CrossProduct(Vec3(1, 2, 3), Vec3(1, 5, 7));
    Assert::AreEqual(-1.0f, another_test.x, 0.1f, "CrossProduct X Failed", __FILE__, __LINE__);
    Assert::AreEqual(-4.0f, another_test.y, 0.1f, "CrossProduct Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, another_test.z, 0.1f, "CrossProduct Z Failed", __FILE__, __LINE__);

    //Check Distance function
    Assert::AreEqual(10.246951f, Vec3::Distance(Vec3(7, 4, 3), Vec3(17, 6, 2)), 0.000001f, "Distance Failed", __FILE__, __LINE__);

    //Check Reflect function
    another_test = Vec3::Reflect(Vec3(-0.5f, 0.5f, 0), Vec3(-1, 0, 0));
    Assert::AreEqual(0.5f, another_test.x, 0.1f, "Reflect X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, another_test.y, 0.1f, "Reflect Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, another_test.z, 0.1f, "Reflect Z Failed", __FILE__, __LINE__);

    //Check SqrMagnitude function
    another_test = Vec3(1.0f, 2.0f, 3.0f);
    Assert::AreEqual(14.0f, another_test.SqrMagnitude(), 0.1f, "SqrMagnitude Failed", __FILE__, __LINE__);

    //Check Scale function.
    another_test = Vec3(1.0f, 2.0f, 3.0f);
    another_test.Scale(Vec3(2.0f));
    Assert::AreEqual(2.0f, another_test.x, "X value on scale failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, another_test.y, "Y value on scale failed", __FILE__, __LINE__);
    Assert::AreEqual(6.0f, another_test.z, "Z value on scale failed", __FILE__, __LINE__);
	
    Test::End();
  }

  void Vec4Test() {

	  Test::Start(__FUNCTION__);

    Vec4 test;
    Vec4 a = Vec4(5.0f, 3.0f, 2.0f, 1.0f);
    Vec4 b = Vec4(3.0f, 2.0f, 1.0f, 0.0f);

    /////////////////////////
    // ---- OPERATORS ----///
    /////////////////////////

    //-----------------//
    // -- Operator+ -- //
    //----------------//
    test = a + b;
    Assert::AreEqual(8.0f, test.x, 0.00001f, "Operator+(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.z, 0.00001f, "Operator+(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.w, 0.00001f, "Operator+(Vec4) Failed", __FILE__, __LINE__);

    test = a + 2.0f;
    Assert::AreEqual(7.0f, test.x, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.w, 0.00001f, "Operator+(float) Failed", __FILE__, __LINE__);

    //-----------------//
    // -- Operator+= --//
    //----------------//
    test = a;
    test += b;
    Assert::AreEqual(8.0f, test.x, 0.00001f, "Operator+=(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+=(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.z, 0.00001f, "Operator+=(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.w, 0.00001f, "Operator+=(Vec4) Failed", __FILE__, __LINE__);

    test = a;
    test += 2.0f;
    Assert::AreEqual(7.0f, test.x, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(5.0f, test.y, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.w, 0.00001f, "Operator+=(float) Failed", __FILE__, __LINE__);

    //-----------------//
    // -- Operator- -- //
    //----------------//
    test = a - b;
    Assert::AreEqual(2.0f, test.x, 0.00001f, "Operator-(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator-(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.w, 0.00001f, "Operator-(Vec4) Failed", __FILE__, __LINE__);

    test = a - 2.0f;
    Assert::AreEqual(3.0f, test.x, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.z, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(-1.0f, test.w, 0.00001f, "Operator-(float) Failed", __FILE__, __LINE__);

    //-------------------//
    // -- Operator-= -- //
    //------------------//
    test = a;
    test -= b;
    Assert::AreEqual(2.0f, test.x, 0.00001f, "Operator-=(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-=(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator-=(Vec4) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.w, 0.00001f, "Operator-=(Vec4) Failed", __FILE__, __LINE__);

    test = a;
    test -= 2.0f;
    Assert::AreEqual(3.0f, test.x, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.z, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);
    Assert::AreEqual(-1.0f, test.w, 0.00001f, "Operator-=(float) Failed", __FILE__, __LINE__);

    //-----------------//
    // -- Operator* -- //
    //----------------//
    test = a * 2.0f;
    Assert::AreEqual(10.0f, test.x, 0.00001f, "Operator* Failed", __FILE__, __LINE__);
    Assert::AreEqual(6.0f, test.y, 0.00001f, "Operator* Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator* Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, test.w, 0.00001f, "Operator* Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator*= -- //
    //-----------------//
    test = a;
    test *= 2.0f;
    Assert::AreEqual(10.0f, test.x, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);
    Assert::AreEqual(6.0f, test.y, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);
    Assert::AreEqual(4.0f, test.z, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, test.w, 0.00001f, "Operator*= Failed", __FILE__, __LINE__);

    //-----------------//
    // -- Operator/ -- //
    //----------------//
    test = a / 2.0f;
    Assert::AreEqual(2.5f, test.x, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, test.y, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, test.w, 0.00001f, "Operator/ Failed", __FILE__, __LINE__);

    //------------------//
    // -- Operator/= -- //
    //-----------------//
    test = a;
    test /= 2.0f;
    Assert::AreEqual(2.5f, test.x, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.5f, test.y, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, test.w, 0.00001f, "Operator/= Failed", __FILE__, __LINE__);

    //-----------------//
    // -- Operator= -- //
    //----------------//
    test = a;
    Assert::AreEqual(5.0f, test.x, 0.00001f, "Operator= Failed", __FILE__, __LINE__);
    Assert::AreEqual(3.0f, test.y, 0.00001f, "Operator= Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, test.z, 0.00001f, "Operator= Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.w, 0.00001f, "Operator= Failed", __FILE__, __LINE__);



    //Check Magnitude function.
    Assert::AreEqual(6.244998f, a.Magnitude(), 0.00001f, "Magnitude Failed", __FILE__, __LINE__);

    //Check Normalized function.
    Assert::AreEqual(0.800641f, a.Normalized().x, 0.00001f, "Normalized X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.480384f, a.Normalized().y, 0.00001f, "Normalized Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.320256f, a.Normalized().z, 0.00001f, "Normalized Z Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.160128f, a.Normalized().w, 0.00001f, "Normalized W Failed", __FILE__, __LINE__);

    //Check Normalize function.
    test = a;
    test.Normalize();
    Assert::AreEqual(0.800641f, test.x, 0.00001f, "Normalize X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.480384f, test.y, 0.00001f, "Normalize Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.320256f, test.z, 0.00001f, "Normalize Z Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.160128f, test.w, 0.00001f, "Normalize W Failed", __FILE__, __LINE__);

    //Check Scale function.
    test = a;
    test.Scale(b);
    Assert::AreEqual(15.0f, test.x, 0.00001f, "Scale X Failed", __FILE__, __LINE__);
    Assert::AreEqual(6.0f, test.y, 0.00001f, "Scale Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(2.0f, test.z, 0.00001f, "Scale Z Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.w, 0.00001f, "Scale W Failed", __FILE__, __LINE__);

    //Check Distance function
    Assert::AreEqual(2.645751f, Vec4::Distance(a, b), 0.000001f, "Distance Failed", __FILE__, __LINE__);

    // Check Dot Product function.
    Assert::AreEqual(23.0f, Vec4::DotProduct(a, b), "Dot Product Failed", __FILE__, __LINE__);

    //Check Lerp function.
    test = Vec4::Lerp(Vec4(0.0f), Vec4(1), 0.5);
    Assert::AreEqual(0.5f, test.x, 0.1f, "Lerp X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, test.y, 0.1f, "Lerp Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, test.z, 0.1f, "Lerp Z Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.5f, test.w, 0.1f, "Lerp W Failed", __FILE__, __LINE__);
    test = Vec4::Lerp(Vec4(0.0f), Vec4(1), 1.5);
    Assert::AreEqual(1.0f, test.x, 0.1f, "Lerp X Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.y, 0.1f, "Lerp Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.z, 0.1f, "Lerp Z Failed", __FILE__, __LINE__);
    Assert::AreEqual(1.0f, test.w, 0.1f, "Lerp W Failed", __FILE__, __LINE__);
    test = Vec4::Lerp(Vec4(0.0f), Vec4(1), -1);
    Assert::AreEqual(0.0f, test.x, 0.1f, "Lerp X Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.y, 0.1f, "Lerp Y Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.z, 0.1f, "Lerp Z Failed", __FILE__, __LINE__);
    Assert::AreEqual(0.0f, test.w, 0.1f, "Lerp W Failed", __FILE__, __LINE__);    

	  Test::End();
  }
};