#include "window.hpp"
#include <GLFW/glfw3.h>
#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(400,400)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    
    float sec = win.get_time();
    float min = sec / 60;
    float hour = sec / 3600;

    Vec2 v_1 = {100.0f, 300.0f};  
    Vec2 v_2 = {500.0f, 500.0f};
    Vec2 v_3 = {400.0f, 400.0f};  
    Vec2 v_4 = {600.0f, 600.0f};

    Color c_red   = {1.0f, 0.0f, 0.0f};
    Color c_green = {0.0f, 1.0f, 0.0f};
    Color c_blue  = {0.0f, 0.0f, 1.0f};
    Color c_pink  = {0.92f, 0.0f, 0.92f};

    Vec2 center = {200.0f,200.0f};

    Circle my_clock{180.0f, c_green, center};
    my_clock.draw(win, 2.0f);

    
    // float angle = -M_PI * 2 / 60;

    // win.draw_line(center.x, center.y, std::sin(angle * sec) * 200.0f  + center.x, std::cos(angle * sec) * 100.0f + center.y, 0.0f, 0.0f, 0.0f);
    // win.draw_line(center.x, center.y, std::sin(angle * min) * 160.0f  + center.x, std::cos(angle * min) * 60.0f  + center.y, 0.0f, 0.0f, 0.0f);
    // win.draw_line(center.x, center.y, std::sin(angle * hour) * 100.0f + center.x, std::cos(angle * hour) * 40.0f + center.y, 0.0f, 0.0f, 0.0f);

    float const RADIAN = 0.0174532925;

    Vec2 hour_hand{0.0f, -80.0f};
    Vec2 min_hand{0.0f,  -120.0f};
    Vec2 sec_hand{0.0f,  -150.0f};

    Mat2 hour_hand_rot  = make_rotation_mat2(360 / 24 * RADIAN * (sec / 3600));
    Mat2 min_hand_rot   = make_rotation_mat2(360 / 60 * RADIAN * (sec / 60 ));
    Mat2 sec_hand_rot   = make_rotation_mat2(360 / 60 * RADIAN * (sec));

    sec_hand = sec_hand * sec_hand_rot;
    min_hand = min_hand * min_hand_rot;
    hour_hand = hour_hand * hour_hand_rot;

    win.draw_line(center.x, center.y, sec_hand.x + 200.0f, sec_hand.y + 200.0f, 1.0f, 0.0f, 0.0f, 1.0f);
    win.draw_line(center.x, center.y, min_hand.x + 200.0f, min_hand.y + 200.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    win.draw_line(center.x, center.y, hour_hand.x + 200.0f, hour_hand.y + 200.0f, 0.0f, 0.0f, 1.0f, 1.5f);

    win.draw_text(10.0f, 10.0f, 15.0f, std::to_string(sec) + " : ");
    win.draw_text(65.0f, 10.0f, 15.0f, std::to_string(min) + " : ");
    win.draw_text(120.0f, 10.0f, 15.0f, std::to_string(hour));
    win.update();
  }

return 0;
}
