// circle.hpp
#include <math.h>
#include "circle.hpp"


Circle::Circle():
  radius_{50.0f},
  color_{0.5f,0.5f,0.5f},
  center_{5.0f,5.0f},
  thickness_{1.0f}{}

Circle::Circle(float r):
  radius_ {r},
  color_{0.5f,0.5f,0.5f},
  center_{5.0f,5.0f},
  thickness_{1.0f}{}

Circle::Circle(float const& r, Color const& color, Vec2 const& center){
  radius_ = r;
  color_ = color;
  center_ = center;
  thickness_ = 1.0f;
}

Circle::Circle(float const& r, Color const& color, Vec2 const& center, float thickness){
  radius_ = r;
  color_ = color;
  center_ = center;
  thickness_ = thickness;
}

float Circle::circumference(){
  // U = 2 * r * pi
  return (2 * radius_ * M_PI); 
}
 
 
float Circle::flaecheinhalt(){
  return (radius_ * radius_ * M_PI);
}

bool Circle::is_inside(Vec2 vec){
  Vec2 rv = vec - center_;
  float distToCenter = sqrt(pow(rv.x,2) + pow(rv.y,2));
  if (distToCenter > radius_){
    return false;
  } else {
    return true;
  }
}

void Circle::draw (Window const& w) const { 
  Vec2 startPt{center_.x, center_.y - radius_};
  
 for (int i = 0; i<100; i++){
    float rot = ((2 * M_PI)/ 100);

    Mat2 rotmat = make_rotation_mat2(rot);
    Vec2 newPt = center_ + (rotmat*(startPt - center_));

    w.draw_line(startPt.x, startPt.y, newPt.x, newPt.y, color_.r_, color_.g_, color_.b_);
    startPt = newPt;
  }
}

void Circle::draw (Window const& w, float thickness) const { 
  Vec2 startPt{center_.x, center_.y - radius_};
  
 for (int i = 0; i<100; i++){
    float rot = ((2 * M_PI)/ 100);
    
    Mat2 rotmat = make_rotation_mat2(rot);
    Vec2 newPt = center_ + (rotmat * (startPt - center_));
   
    w.draw_line(startPt.x, startPt.y, newPt.x, newPt.y, color_.r_, color_.g_, color_.b_, thickness);
    startPt = newPt;
  }
}
