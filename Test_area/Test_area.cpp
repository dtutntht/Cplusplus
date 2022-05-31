#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
// #include <termios.h>  This is for Linux
using namespace std; 




int main ()
{
    
    cout << "hello world" << endl;
    cout << endl;
    int a = 100;
    int b = 0;
    int c = 50;
    b &= ~a ;
    cout << b << endl; 
    char x = 'x';
    char y = 'y';
    x |= y;
    cout << x << endl;
    cout << endl;
    string dev[4]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyACM0","/dev/ttyUSB0"};
    cout << dev[0] << endl;
    printf("device is: %s\n", dev[0].c_str());

    Sleep(10000000);
}


