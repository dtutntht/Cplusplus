// for data IO
#include <iostream>

// for file IO
#include <fstream>
// for file delete
#include <cstdio>
// for mouse control
#include <winuser.h>
#include "Mouse_control.h"
#pragma comment (lib, "User32.lib")


void mouse_control::record_pixel(int test_item){
    string log_name("tmp.txt");
    fstream logger;
    logger.open(log_name, std::ios_base::app);
    if (! logger.is_open()) {
        cout << "Failed to open output file : " << log_name << endl;
    } else {
        logger << "Test_item_" << test_item << " : x = " << cur_pixel_x << ", y = " << cur_pixel_y << endl;
    }
    logger.close();

}

void mouse_control::move(direction direct, int pixel){
    
    switch(direct){
        case direction::left:
        cur_pixel_x -= pixel;
        break;
        case direction::right:
        cur_pixel_x += pixel;
        break;
        case direction::up:
        cur_pixel_y -= pixel;
        break;
        case direction::down:
        cur_pixel_y += pixel;
        break;
        case direction::init:
        cout << start_pixel_line1[0];
        cout << start_pixel_line1[1];
        cur_pixel_x = start_pixel_line1[0];
        cur_pixel_y = start_pixel_line1[1];
        break;
    }
    
    SetCursorPos(cur_pixel_x,cur_pixel_y);
    
}

void  mouse_control::left_click(){
    mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP,0,0,0,0);
    //mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);
}