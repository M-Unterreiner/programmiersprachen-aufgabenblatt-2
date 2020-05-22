#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE("Aufgabe 2.2","[vec2]") {
  Vec2 a{}; 
  SECTION("Default constructor")
  REQUIRE (a.x == Approx(0.0));
  REQUIRE (a.y == Approx(0.0));
  
  Vec2 b{4.2f, 2.3f};
  SECTION("Aggregatsinitialisierung")
  REQUIRE (b.x == Approx(4.2));
  REQUIRE (b.y == Approx(2.3));
} 

TEST_CASE("Aufgabe 2.3", "[vec2]") {
  // Test operators +=, -=, *= and /=
  Vec2 vc1{2.0f, 2.0f};
  Vec2 vc2{1.0f, 1.0f};
  Vec2 vc3{5.0f, 5.0f};

  // Test operator += 
  vc1 += vc2;
  vc2 += vc3;
  REQUIRE (vc1.x == Approx(3.0f));
  REQUIRE (vc1.y == Approx(3.0f));
  REQUIRE (vc2.x == Approx(6.0f));
  REQUIRE (vc2.y == Approx(6.0f));

  // Test operator -= 
  vc1 -= vc2;
  vc2 -= vc3;
  REQUIRE (vc1.x == Approx(-3.0f)); // Hier 
  REQUIRE (vc1.y == Approx(-3.0f));
  REQUIRE (vc2.x == Approx(1.0f));
  REQUIRE (vc2.y == Approx(1.0f));

  // Test operator *= 
  Vec2 vc4{2.0f, 2.0f};
  vc4 *= 2.0f;
  REQUIRE (vc4.x == Approx(4.0f));
  REQUIRE (vc4.y == Approx(4.0f));
  
  // Test operatpr /=
  vc4 /= 2.0f; 
  REQUIRE (vc4.x == Approx(2.0f));
  REQUIRE (vc4.y == Approx(2.0f));
  
  // Test Division with 0
  vc4 /= 0.0f;
  REQUIRE (vc2.x == Approx(vc2.x));
  REQUIRE (vc2.y == Approx(vc2.y));
}

TEST_CASE("Aufgabe 2.4"){
Vec2 vec2_41{1.0f,1.0f};
Vec2 vec2_42{2.0f,2.0f};


// Addition
vec2_41 += vec2_42;
REQUIRE (vec2_41.x == Approx(3.0f));
REQUIRE (vec2_41.y == Approx(3.0f));


// Substraktion
// 3.0f - 2.0f
 vec2_41 -= vec2_42;
REQUIRE (vec2_41.x == Approx(1.0f));
REQUIRE (vec2_41.y == Approx(1.0f));

// Multiplikation
// 1.0f * 2.0f
float s = 2.0f;
vec2_41 *= s;
REQUIRE (vec2_41.x == Approx(2.0f));
REQUIRE (vec2_41.y == Approx(2.0f));

// 2.0f * 2.0f
vec2_41 *= 2.0f;
REQUIRE (vec2_41.x == Approx(4.0f));
REQUIRE (vec2_41.y == Approx(4.0f));

// Division
vec2_41 /= s;
REQUIRE (vec2_41.x == Approx(1.0f));
REQUIRE (vec2_41.y == Approx(1.0f));
}
