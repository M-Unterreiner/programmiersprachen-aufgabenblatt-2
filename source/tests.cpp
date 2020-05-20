#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE("2.2","[vec2]") {
  Vec2 a{}; 
  REQUIRE (a.x == Approx(0.0));
  REQUIRE (a.y == Approx(0.0));
  
  Vec2 b{4.2f, 2.3f};
  REQUIRE (b.x == Approx(4.2));
  REQUIRE (b.y == Approx(2.3));
} 