// mat2.cpp
#include <iostream>
#include <cmath>
#include "mat2.hpp"
#include "vec2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m){
    float temp_00 = e_00; // lo
    float temp_01 = e_01; // ro  
    float temp_10 = e_10; // lu
    float temp_11 = e_11; // ru
    
    e_00 = temp_00 * m.e_00 + temp_10 * m.e_01;  
    e_01 = temp_01 * m.e_00 + temp_11 * m.e_01;
    e_10 = temp_00 * m.e_10 + temp_10 * m.e_11;
    e_11 = temp_01 * m.e_10 + temp_11 * m.e_11;  

    return *this;
}

float Mat2::det()const {
    return (e_00 * e_11) - (e_10 * e_01);
}

void Mat2::printMat(){
    std::cout << e_00 << " " << e_10 << std::endl;
    std::cout << e_01 << " " << e_11 << std::endl;
    std::cout << "";
}


Mat2 operator*(Mat2 const& m_1, Mat2 const& m_2){
    return Mat2{m_1} *=m_2;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
    // TODO: Test
    float x = m.e_00 * v.x + m.e_10 * v.y;
    float y = m.e_01 * v.x + m.e_11 * v.y;
    Vec2 result{x, y};
    return result;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v){
    // TODO: Test
    return {v*m};
}

Mat2 inverse (Mat2 const & m){
    // TODO: test
    if (m.det() == 0)
    {
        Mat2 invMat;

        // swap the Positiion and put the negatives
        invMat.e_00 = 1 / m.det() * m.e_11;
        invMat.e_01 = 1 / m.det() * m.e_01 * (-1);
        invMat.e_10 = 1 / m.det() * m.e_10 * (-1);
        invMat.e_11 = 1 / m.det() * m.e_00;

        return invMat;
    }
    else
    {
        std::cout << "Inverse is not possible";
        return m;
    }
}

Mat2 transpose (Mat2 const & m){
    // TODO: test

    Mat2 transMat;

    transMat.e_00 = m.e_00;
    transMat.e_01 = m.e_10;
    transMat.e_10 = m.e_01;
    transMat.e_11 = m.e_11;
    return transMat;
}

Mat2 make_rotation_mat2 (float phi){
    // TODO: test
    return Mat2{std::cos(phi), -std::sin(phi), std::sin(phi), std::cos(phi)};
}