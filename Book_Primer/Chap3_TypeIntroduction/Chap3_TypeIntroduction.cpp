#include <iostream>
#include <string.h>
// #include <windows.h>
#include <unistd.h>
#include "header.h"
#include <climits>

void CheckLimit();
void CheckCarry();
void CheckChar();
void Exercise();
using namespace std; 

int main(){

    cout << "Hello World!" << endl;
    cout << "-------------------------------------" << endl;
    CheckLimit();
    cout << "-------------------------------------" << endl;
    CheckCarry();
    cout << "-------------------------------------" << endl;
    CheckChar();
    cout << "-------------------------------------" << endl;
    Exercise();
    sleep(1000);
}

void CheckLimit(){

    int i_max=INT_MAX;
    int i_min=INT_MIN;
    unsigned int ui_max=UINT_MAX;
    //unsigned int ui_min=UINT_MIN;    
    cout << "i_max = " << i_max << endl;
    cout << "i_min = " << i_min << endl;
    cout << "ui_max = " << ui_max << endl;
    //cout << "ui_min = " << ui_min << endl;
    i_max=i_max+1;
    i_min=i_min-1;
    ui_max=ui_max+1;
    cout << "Altered i_max = " << i_max << endl;
    cout << "Altered i_min = " << i_min << endl;
    cout << "Altered ui_max = " << ui_max << endl;
    i_max=i_max+1;
    i_min=i_min-1;
    ui_max=ui_max+1;
    cout << "Altered2 i_max = " << i_max << endl;
    cout << "Altered2 i_min = " << i_min << endl;
    cout << "Altered2 ui_max = " << ui_max << endl;
    
}

void CheckCarry(){

    int dec_42=42;
    int oct_42=042;
    int hex_42=0x42;
    cout << "Decimal 42 : " << dec_42 << endl;
    cout << "Octal 42 : " << oct_42 << endl;
    cout << "Hexadecimal 42 : " << hex_42 << endl;
    
    // using iostream operator "dec", "hex" and "oct" to change the output of cout.

    int num_42=42;
    cout << oct;
    cout << "42 in oct mode : " << num_42 << endl;
    cout << hex;
    cout << "42 in hex mode : " << num_42 << endl;
    cout << dec;
    cout << "42 in dec mode : " << num_42 << endl;

}

void CheckChar(){
    
    char ch = 'M';
    cout << "char : " << ch << endl;
    int i = ch;
    cout << "char in ASCII number : " << i << endl;
    int i2 = 80;
    char ch2 = i2;
    cout << "80 in ASCII result : " << ch2 << endl;

    char ch3 = 80;
    cout << ch3 << endl;
    string str(1, ch3);
    cout << str << endl; 
    cout << "type of str : " << typeid(str).name() << endl;
    
}

void Exercise(){
    
    
    long a = 31536000 % 86400;
    cout << a << endl;

    cout << "Please input the total times in second : " << endl;
    long TotalSec;
    cin >>  TotalSec;
    cout << "Your input is : " << TotalSec << "!" << "\nStart to calculate the time in formal format..." << endl;
    long day, hour, minute, second;
    day = TotalSec / 86400;
    hour = (TotalSec % 86400) / 3600;
    minute = (TotalSec % 86400 % 3600) / 60;
    second = TotalSec % 86400 % 3600 % 60;
    cout << "Time you just input is represent as below : " << endl;
    cout << day << " Days, " << hour << " Hours, " << minute << " Minutes, " << second << " Seconds." << endl;
    
}
