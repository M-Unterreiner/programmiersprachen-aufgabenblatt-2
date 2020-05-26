#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE("Aufgabe 2.2","[vec2]") {
  SECTION("Default constructor"){
    Vec2 a{}; 
    REQUIRE (a.x == Approx(0.0));
    REQUIRE (a.y == Approx(0.0));
  }

  SECTION("Aggregatsinitialisierung"){
    Vec2 b{4.2f, 2.3f};
    REQUIRE (b.x == Approx(4.2));
    REQUIRE (b.y == Approx(2.3));
  }
} 

TEST_CASE("Aufgabe 2.3", "[vec2]") {
  // Test operators +=, -=, *= and /=
  Vec2 vc1{2.0f, 2.0f};
  Vec2 vc2{1.0f, 1.0f};
  Vec2 vc3{5.0f, 5.0f};
  Vec2 vc4{2.0f, 2.0f};

  SECTION("Test operator +="){
    Vec2 vc1{2.0f, 2.0f};
    Vec2 vc2{1.0f, 1.0f};
    Vec2 vc3{5.0f, 5.0f};

    vc1 += vc2;
    vc2 += vc3;
    REQUIRE (vc1.x == Approx(3.0f));
    REQUIRE (vc1.y == Approx(3.0f));
    REQUIRE (vc2.x == Approx(6.0f));
    REQUIRE (vc2.y == Approx(6.0f));
  }

  SECTION("Test operator -="){
    Vec2 vc1{2.0f, 2.0f};
    Vec2 vc2{1.0f, 1.0f};
    Vec2 vc3{5.0f, 5.0f};

    vc1 -= vc3;
    vc4 -= vc3;
    REQUIRE (vc1.x == Approx(-3.0f));  
    REQUIRE (vc1.y == Approx(-3.0f));
    REQUIRE (vc2.x == Approx(1.0f));
    REQUIRE (vc2.y == Approx(1.0f));
  }

  SECTION("Test operator *="){
    Vec2 vc4{2.0f, 2.0f};

    vc4 *= 2.0f;
    REQUIRE (vc4.x == Approx(4.0f));
    REQUIRE (vc4.y == Approx(4.0f));
  }

  SECTION("Test operator /="){
    Vec2 vc4{2.0f, 2.0f};

    vc4 /= 2.0f; 
    REQUIRE (vc4.x == Approx(1.0f));
    REQUIRE (vc4.y == Approx(1.0f));

    // Test Division with 0
    vc4 /= 0.0f;
    REQUIRE (vc2.x == Approx(vc2.x));
    REQUIRE (vc2.y == Approx(vc2.y));
  }
}

TEST_CASE("Aufgabe 2.4"){

  SECTION("Test operator += in a free function"){
    Vec2 vec2_41{1.0f,1.0f};
    Vec2 vec2_42{2.0f,2.0f};

    vec2_41 += vec2_42;
    REQUIRE (vec2_41.x == Approx(3.0f));
    REQUIRE (vec2_41.y == Approx(3.0f));
  }

  SECTION("Test operator -= in a free function"){
    Vec2 vec2_41{1.0f,1.0f};
    Vec2 vec2_42{2.0f,2.0f};

    vec2_41 -= vec2_42;
    REQUIRE (vec2_41.x == Approx(-1.0f));
    REQUIRE (vec2_41.y == Approx(-1.0f));
  }

  SECTION("Test operator *= in a free function"){
    // 1.0f * 2.0f
    Vec2 vec2_41{1.0f,1.0f};

    float s = 2.0f;
    vec2_41 *= s;
    REQUIRE (vec2_41.x == Approx(2.0f));
    REQUIRE (vec2_41.y == Approx(2.0f));

    // 2.0f * 2.0f
    vec2_41 *= 2.0f;
    REQUIRE (vec2_41.x == Approx(4.0f));
    REQUIRE (vec2_41.y == Approx(4.0f));
  }

  SECTION("Test operator /= in a free function"){
    Vec2 vec2_41{1.0f,1.0f};

    float s = 2.0f;
    vec2_41 /= s;
    REQUIRE (vec2_41.x == Approx(0.5f));
    REQUIRE (vec2_41.y == Approx(0.5f));
  }

}

TEST_CASE("2.5 Matrixmultiplikation"){
  SECTION ("Test operator *= as a memberfunction"){  
    Mat2 mat1{1.0f,2.0f,3.0f,4.0f};
    Mat2 mat2{4.0f,5.0f,1.0f,2.0f};

    mat1 *= mat2;
    REQUIRE (mat1.e_00 == Approx(6.0f));
    REQUIRE (mat1.e_01 == Approx(16.0f));
    REQUIRE (mat1.e_10 == Approx(9.0f));
    REQUIRE (mat1.e_11 == Approx(23.0f));
  }

  SECTION ("Test operator *= as a memberfunction"){  
    Mat2 mat1{1.0f,2.0f,3.0f,4.0f};
    Mat2 mat2{4.0f,5.0f,1.0f,2.0f};

    mat1 *= mat2;
    
    REQUIRE (mat1.e_00 == Approx(6.0f));
    REQUIRE (mat1.e_01 == Approx(16.0f));
    REQUIRE (mat1.e_10 == Approx(9.0f));
    REQUIRE (mat1.e_11 == Approx(23.0f)); 
  }
  
  SECTION ("Test operator *= as a free function"){  
    Mat2 mat1{1.0f,2.0f,3.0f,4.0f};
    Mat2 mat2{4.0f,5.0f,1.0f,2.0f};

    mat1 *= mat2;

    REQUIRE (mat1.e_00 == Approx(6.0f));
    REQUIRE (mat1.e_01 == Approx(16.0f));
    REQUIRE (mat1.e_10 == Approx(9.0f));
    REQUIRE (mat1.e_11 == Approx(23.0f));
  }

  SECTION("Free function."){
    Mat2 m_1{};
    Mat2 m_2{1, 2, 3, 4};
    Mat2 m_3{-1, 2, -3, 4};
    Mat2 m_4{1.5, 0.5, 2.0, 2.5};

    Mat2 m_5 = m_1 * m_2;
    Mat2 m_6 = m_3 * m_4;
    Mat2 m_7 = m_2 * m_3;

    REQUIRE(m_5.e_00 == 1);
    REQUIRE(m_5.e_10 == 2);
    REQUIRE(m_5.e_01 == 3);
    REQUIRE(m_5.e_11 == 4);

    REQUIRE(m_6.e_00 == Approx(2.5f));
    REQUIRE(m_6.e_01 == Approx(3.5f));
    REQUIRE(m_6.e_10 == Approx(4.5f));
    REQUIRE(m_6.e_11 == Approx(8.5f));

    REQUIRE(m_7.e_00 == -7);
    REQUIRE(m_7.e_10 == 10);
    REQUIRE(m_7.e_01 == -15);
    REQUIRE(m_7.e_11 == 22);
  }
};

TEST_CASE("2.6 Matrixmultiplikation"){
  SECTION("Matrix multiplikation with vector"){
    Mat2 m_a{};
    Mat2 m_b{1, 2, 3, 4};
    Mat2 m_c{-1, -2, -3, -4};

    Vec2 v_a{-1, -2};
    Vec2 v_b{2.0, 3.0};

    Vec2 v_c, v_d, v_e, v_f;

    v_c = v_a * m_a;
    REQUIRE(v_c.x == -1);
    REQUIRE(v_c.y == -2);

    v_d = v_b * m_b;
    REQUIRE(v_d.x == Approx(8.0f));
    REQUIRE(v_d.y == Approx(18.0f));

    v_e = m_c * v_a;
    REQUIRE(v_e.x == 5);
    REQUIRE(v_e.y == 11);

    v_f = m_b * v_b;
    REQUIRE(v_f.x == Approx(8.0f));
    REQUIRE(v_f.y == Approx(18.0f));
  }

  SECTION("Mat2_det")
  {
    Mat2 m_a{};
    Mat2 m_b{1, 2, 3, 4};
    Mat2 m_c{-1, -2, -3, -4};
    Mat2 m_d{1.2, 2.3, 2.4, 4.5};

    REQUIRE(m_a.det() == 1);
    REQUIRE(m_b.det() == -2);
    REQUIRE(m_c.det() == -2);
    REQUIRE(m_d.det() == Approx(-0.12f));
  }

  SECTION("Mat2_inv"){
    Mat2 m_a{};
    Mat2 m_b{1, 2, 3, 4};
    Mat2 m_c{0.0, 1.5, 0.0, 1.6};

    Mat2 m_d = inverse(m_a);
    REQUIRE(m_d.e_00 == 1);
    REQUIRE(m_d.e_01 == 0);
    REQUIRE(m_d.e_10 == 0);
    REQUIRE(m_d.e_11 == 1);

  }

  SECTION("Mat2_tra"){
    Mat2 m_a{};
    Mat2 m_c{0.0, 1.5, 0.0, 1.6};

    Mat2 m_d = transpose(m_a);
    REQUIRE(m_d.e_00 == 1);
    REQUIRE(m_d.e_01 == 0);
    REQUIRE(m_d.e_10 == 0);
    REQUIRE(m_d.e_11 == 1);
  }

};
