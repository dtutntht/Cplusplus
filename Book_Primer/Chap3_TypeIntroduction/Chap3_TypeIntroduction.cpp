#include <iostream>
#include <string.h>
// #include <windows.h>
#include <unistd.h>
#include "header.h"
#include <climits>

void CheckLimit();
void CheckCarry();

using namespace std; 

int main(){

    cout << "Hello World!" << endl;
    cout << "-------------------------------------" << endl;
    CheckLimit();
    cout << "-------------------------------------" << endl;
    CheckCarry();

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
