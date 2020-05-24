// mat2.hpp

#ifndef MAT2_HPP
#define MAT2_HPP

#include <array>
#include "vec2.hpp"

struct Mat2 {

// matrix layout :
// e_00     e_10
// e_01     e_11

    float e_00 = 1.0f;
    float e_10 = 0.0f;
    float e_01 = 0.0f;
    float e_11 = 1.0f;

// TODO (in mat2.cpp) Definition v. operator *=
    Mat2& operator*=(Mat2 const& m);

// Mat2& printMat(Mat2 const& m);
    void printMat();
};

// TODO (in mat2.cpp) Definition v. operator*
Mat2 operator*(Mat2 const& m_1, Mat2 const& m_2);
// 
// Vec2 operator*(Mat2 const& m, Vec2 const& v);
// Vec2 operator*(Vec2 const& v, Mat2 const& m);

#endif // MAT2_HPP
