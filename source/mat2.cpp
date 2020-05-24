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

void Mat2::printMat(){
    std::cout << e_00 << " " << e_10 << std::endl;
    std::cout << e_01 << " " << e_11 << std::endl;
    std::cout << "";
}


Mat2 operator*(Mat2 const& m_1, Mat2 const& m_2){
    // Mat2 m_res{};

    // m_res.e_00 = m_1.e_00 * m_2.e_00 + m_1.e_10 * m_2.e_10;  
    // m_res.e_10 = m_1.e_00 * m_2.e_01 + m_1.e_01 * m_2.e_11;
    // m_res.e_01 = m_1.e_10 * m_2.e_00 + m_1.e_10 * m_2.e_10;
    // m_res.e_11 = m_1.e_10 * m_2.e_01 + m_1.e_11 * m_2.e_11;  

    //return m_res;
    return Mat2{m_1} *=m_2;
}