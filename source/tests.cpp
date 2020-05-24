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
    REQUIRE (mat1.e_01 == Approx(9.0f));
    REQUIRE (mat1.e_10 == Approx(16.0f));
    REQUIRE (mat1.e_11 == Approx(23.0f));
  }

  SECTION ("Test operator *= as a memberfunction"){  
    Mat2 mat1{1.0f,2.0f,3.0f,4.0f};
    Mat2 mat2{4.0f,5.0f,1.0f,2.0f};

    mat1.printMat();
    mat2.printMat();
    mat1 *= mat2;
    mat1.printMat();
    
    REQUIRE (mat1.e_00 == Approx(6.0f));
    REQUIRE (mat1.e_01 == Approx(9.0f));
    REQUIRE (mat1.e_10 == Approx(16.0f));
    REQUIRE (mat1.e_11 == Approx(23.0f)); 
  }
  
  SECTION ("Test operator *= as a free function"){  
    Mat2 mat1{1.0f,2.0f,3.0f,4.0f};
    Mat2 mat2{4.0f,5.0f,1.0f,2.0f};
    std::cout << "############## *= Free function"; 
    mat1.printMat();
    mat2.printMat();  
    mat1 *= mat2;
    mat1.printMat();

    REQUIRE (mat1.e_00 == Approx(6.0f));
    REQUIRE (mat1.e_01 == Approx(9.0f));
    REQUIRE (mat1.e_10 == Approx(16.0f));
    REQUIRE (mat1.e_11 == Approx(23.0f));
  }
}