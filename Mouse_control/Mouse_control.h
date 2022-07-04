#include <iostream>
#include <windows.h>
#include <fstream>
#include <winuser.h>
#pragma comment (lib, "User32.lib")

using namespace std; 


enum direction {
    left,
    right,
    up,
    down,
    init
};

class mouse_control{
    private:
    int start_pixel_line1[2] = {500,200};
    //int start_pixel_line2[2];
    int cur_pixel_x; 
    int cur_pixel_y;
    public:

    void move(direction direct, int pixel);
    void left_click();
    void record_pixel(int test_item);
    mouse_control(){

        cur_pixel_x = 0; 
        cur_pixel_y = 0;
        
    }

};

