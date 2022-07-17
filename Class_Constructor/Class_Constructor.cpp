#include <iostream>
#include <string.h>
#include <unistd.h>
//#include <windows.h>
#include "header.h"

using namespace std; 

void class_constructor();

int main ()
{

    cout << "hello world" << endl;
    cout << "-------------------------------------------" << endl;
    class_constructor();


sleep(10000);

};


void class_constructor(){

    // 2 different way (shows by rectangle and circle) to initialize the object, same result.
    // restrict the input value to avoid the unexpected value been set.
    // for example, value between 0 - 100 is the limit in this example.
    
    rectangle rec_1(100,-15);
    cout << "rec_1's length = " << rec_1.get_length() << endl;
    cout << "rec_1's width = " << rec_1.get_width() << endl;
    circle cir_1(10000,-15);
    cout << "cir_1's length = " << cir_1.get_radius() << endl;
    cout << "cir_1's width = " << cir_1.get_area() << endl;
    
    
}

