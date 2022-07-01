#include <iostream>
#include <windows.h>
#include <fstream>
#include <winuser.h>
#pragma comment (lib, "User32.lib")

using namespace std; 


class mouse_control{
    private:
    int start_pixel_line1[2];
    int start_pixel_line2[2];
    int cur_pixel_x; 
    int cur_pixel_y;
    public:
    void move();
    void left_click();
    void record_pixel(int test_item);
    mouse_control(){
        int start_pixel_line1[2] = {500, 0};
        int start_pixel_line2[2] = {800, 0};
        cur_pixel_x = 0; 
        cur_pixel_y = 0;
        
    }

};

