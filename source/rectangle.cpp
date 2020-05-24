#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"

Rectangle::Rectangle():
  min_{0.0f,0.0f},
  max_{1.0f,1.0f},
  thickness_{1.0f}
{}

Rectangle::Rectangle(Vec2 const& a, Vec2 const& b):
  min_{a.x, a.y},
  max_{b.x, b.y},
  thickness_{1.0f}
{}

Rectangle::Rectangle(Vec2 const& a, Vec2 const& b, Color const& color):
  min_{a.x, a.y},
  max_{b.x, b.y},
  color_{color},
  thickness_{1.0f}
{}

Rectangle::Rectangle(Vec2 const& a, Vec2 const& b, Color const& color, float thickness):
  min_{a.x, a.y},
  max_{b.x, b.y},
  color_{color},
  thickness_{thickness}
{}

bool Rectangle::is_inside(Vec2 position){
  if (position.x > min_.x && position.x < max_.x && position.y > min_.y && position.y < max_.y){
    return true;
  } else {
    return false;
  }
}

float Rectangle::circumference(){
  float a = max_.x - min_.x;
  float b = max_.y - min_.y;

  return (2 * a) + (2 * b); 
}
 
void Rectangle::draw(Window const& w) const{
  // startx , starty, endX, endY, r, g, b, thickness
  w.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r_, color_.g_, color_.b_,thickness_); 
  w.draw_line(min_.x, max_.x, max_.x, max_.y, color_.r_, color_.g_, color_.b_,thickness_);
  w.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r_, color_.g_, color_.b_,thickness_);
  w.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r_, color_.g_, color_.b_,thickness_);   
}

void Rectangle::draw(Window const& w, float thickness) const{
  // startx , starty, endX, endY, r, g, b, thickness
  w.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r_, color_.g_, color_.b_,thickness); 
  w.draw_line(min_.x, max_.x, max_.x, max_.y, color_.r_, color_.g_, color_.b_,thickness);
  w.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r_, color_.g_, color_.b_,thickness);
  w.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r_, color_.g_, color_.b_,thickness);   
}