// rectangle.hpp
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"

class Rectangle {
public:
  Rectangle();
  Rectangle(Vec2 const& a, Vec2 const& b);
  Rectangle(Vec2 const& a, Vec2 const& b, Color const& color);
  Rectangle(Vec2 const& a, Vec2 const& b, Color const& color, float thickness);

  float circumference();
  void draw(Window const& w)const;
  void draw(Window const& w, float thickness)const;
  bool is_inside(Vec2 position); 


private:
  float thickness_;
  Vec2 min_;
  Vec2 max_;
  Color color_;

};



#endif // RECTANGLE_HPP
