// circle.hpp
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "window.hpp"
#include "color.hpp"
#include "vec2.hpp"
#include "mat2.hpp"


class Circle {
public: 
  Circle();
  Circle(float r);
  Circle(float const& r, Color const& color, Vec2 const& center);
  Circle(float const& r, Color const& color, Vec2 const& center, float thickness);

  float circumference(); 
  float flaecheinhalt();
  void draw(Window const& w) const;
  void draw(Window const& w, float thickness) const;
  bool is_inside(Vec2 vec);

private:    
  float radius_;
  float thickness_;
  Color color_;
  Vec2 center_; 
};

#endif // CIRCLE_HPP
