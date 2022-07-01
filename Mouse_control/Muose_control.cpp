// for data IO
#include <iostream>
// for Sleep function
#include <windows.h>
// for file IO
#include <fstream>
// for file delete
#include <cstdio>
// for mouse control
#include <winuser.h>
#include "Mouse_control.h"
#pragma comment (lib, "User32.lib")


using std::cout ; using std::ofstream ; using std::endl ; using std ::string ; using std::fstream ;
void test ();

int main (){
    
    cout << "hello world" << endl;
    test();

    Sleep(100000000);

}

class mouse_control mouse;

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

void mouse_control::move(){
    cur_pixel_y += 100;
    SetCursorPos(cur_pixel_x,cur_pixel_y);
    
}

void  mouse_control::left_click(){
    mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void test (){
    
    int test_total = 20;
    int test_per_line[5];
    //distribute the test count to per line of GUI tool.


    int test_cnt;

    for (test_cnt=1;test_cnt<=test_total;test_cnt++) {
        mouse.move();
        mouse.left_click();
        mouse.record_pixel(test_cnt);
        Sleep(1000);
    }

}

