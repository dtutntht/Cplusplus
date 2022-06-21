#include <iostream>
#include <string.h>
#include <windows.h>
#include "header.h"

using namespace std; 
void Circle();
void StructCircle();
void PointerCircle();

int main ()
{

    cout << "hello world" << endl;
    Circle();
    cout << "-------------------------------------------" << endl;
    StructCircle();
    cout << "-------------------------------------------" << endl;
    PointerCircle();


Sleep(110000000);

};


void Circle(){
    
    class circle BigCircle;
    BigCircle.SetValue(5,10);
    BigCircle.GetVolume();
    cout << BigCircle.volume << endl;
    cout << BigCircle.height << endl;
    cout << BigCircle.radius << endl;

}

void StructCircle(){
    
    struct circle2 MediumCircle;
    circle2 & RefMC=MediumCircle;
    MediumCircle.SetValue(MediumCircle,5,10);
    MediumCircle.GetVolume();
    cout << MediumCircle.volume << endl;
    cout << MediumCircle.height << endl;
    cout << MediumCircle.radius << endl;
    
}

void PointerCircle(){
    class circle * SmallCircle = new circle;
    SmallCircle->SetValue(3,5);
    cout << "Value of height : " << SmallCircle->height << endl;
    cout << "Address of height : " << &SmallCircle->height << endl;
    *SmallCircle->height_p = 20 ;
    cout << "Value of height_p : " << *SmallCircle->height_p << endl;
    cout << "Address of height_p : " << SmallCircle->height_p << endl;
    
}