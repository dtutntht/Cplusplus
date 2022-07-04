// for data IO
#include <iostream>
// for Sleep function
#include <windows.h>
// for file IO
#include <fstream>
// for file delete
#include <cstdio>
// for mouse control
#include "mouse.cpp"


using std::cout ; using std::ofstream ; using std::endl ; using std ::string ; using std::fstream ;
void test ();

class mouse_control mouse;

int main (){

    cout << "hello world" << endl;
    test();
    cout << "DONE!" << endl;
    Sleep(100000000);

}


void test (){
    
    int test_total = 23;
    int test_line_array[10];
    int test_per_line = 5;
    int test_full_line = test_total / test_per_line;
    int test_modulus = test_total % test_per_line;
    //distribute the test count to per line of GUI tool.
    int i;
    for (i=0;i<test_full_line;i++) {
        test_line_array[i] = 5;
    }
    test_line_array[test_full_line] = test_modulus;

    mouse.move(direction::init,0);

    int test_cnt;
    for (i=0;i<=test_full_line;i++) {

        for (test_cnt=1;test_cnt<=test_line_array[i];test_cnt++) {
            mouse.left_click();
            mouse.move(direction::down,10);
            mouse.record_pixel(test_cnt);
            Sleep(500);
        }
        cout << "Loop : " << i << "Complete" << endl;
        mouse.move(direction::up,50);
        mouse.move(direction::right,10);
        
    }
}

