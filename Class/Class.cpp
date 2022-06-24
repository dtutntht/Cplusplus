#include <iostream>
#include <string.h>
#include <windows.h>
#include "header.h"

using namespace std; 
void Circle();
void StructCircle();
void PointerCircle();
void CirclePassByVariable();
void CirclePassByPointer();
void ReferenceCircle();


int main ()
{

    cout << "hello world" << endl;
    Circle();
    cout << "-------------------------------------------" << endl;
    cout << "StructCircle : " << endl;
    StructCircle();
    cout << "-------------------------------------------" << endl;
    cout << "PointerCircle : " << endl;
    PointerCircle();
    cout << "-------------------------------------------" << endl;
    cout << "CirclePassByVariable : " << endl;
    CirclePassByVariable();
    cout << "-------------------------------------------" << endl;
    cout << "CirclePassByPointer : " << endl;
    CirclePassByPointer();
    cout << "-------------------------------------------" << endl;
    cout << "ReferenceCircle : " << endl;
    ReferenceCircle();


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


void CirclePassByVariable(){

    class circle * TremendousCircle = new circle;
    TremendousCircle->radius = 10000;
    class circle CopiedCircleVariable;
    CopiedCircleVariable.CopyRadiusByVariable_1(*TremendousCircle);

    cout << "Copy by Variable 1 : " << CopiedCircleVariable.radius << endl;
    TremendousCircle->radius = 1000000;
    CopiedCircleVariable = TremendousCircle->CopyRadiusByVariable_2(CopiedCircleVariable);
    cout << "Copy by Variable 2 : " << CopiedCircleVariable.radius << endl; ; 
    

}

void CirclePassByPointer(){

    class circle * TinyCircle = new circle;
    TinyCircle->radius = 2;
    class circle * CopiedCirclePointer = new circle;
    CopiedCirclePointer = TinyCircle->CopyRadiusByPointer_1(CopiedCirclePointer);
    
    cout << "Copy by Pointer 1 : " << CopiedCirclePointer->radius << endl;
    cout << "Copy by Pointer 1 Address : " << &CopiedCirclePointer->radius << endl;
    cout << "Tiny's Address : " << &TinyCircle->radius << endl;
    TinyCircle->radius = 1;
    // CopiedCirclePointer = TinyCircle->CopyRadiusByPointer_2();
    
    cout << "Copy by Pointer 2 : " << TinyCircle->CopyRadiusByPointer_2()->radius << endl;
    cout << "Copy by Pointer 2 Address : " << TinyCircle->CopyRadiusByPointer_2()->radius << endl;
    cout << "Tiny's Address : " << &TinyCircle->radius << endl;

}

void ReferenceCircle(){
    
    class circle PrettyCircle;
    PrettyCircle.radius=87;
    class circle CopiedCircleReference;
    PrettyCircle.CopyRadiusReference_1(CopiedCircleReference);
    cout << "Copy by Reference 1 : " << CopiedCircleReference.radius << endl;
    cout << "Copy by Reference 1 Address : " << &CopiedCircleReference.radius << endl;
    class circle CopiedCircleReference2;
    class circle CopiedCircleReference3;

    PrettyCircle.CopyRadiusReference_1(CopiedCircleReference2).CopyRadiusReference_1(CopiedCircleReference3);
    cout << "Copy by Reference object2 : " << CopiedCircleReference2.radius << endl;
    cout << "Copy by Reference object2 Address : " << &CopiedCircleReference2.radius << endl;
    cout << "Copy by Reference object3 : " << CopiedCircleReference3.radius << endl;
    cout << "Copy by Reference object3 Address : " << &CopiedCircleReference3.radius << endl;
    
    class circle CopiedCircleReference4;
    PrettyCircle.CopyRadiusReference_2(CopiedCircleReference4)->height = 78;
    cout << "Copy by Reference object4 Height : " << CopiedCircleReference4.height << endl;


}

void ReferencePointerCircle(){
    circle * OriginCircle = new circle;
    
    circle OriginCircle2;
    circle *& MagicCircle = OriginCircle;
    // circle *& MagicCircle = &OriginCircle2;    <--- This is not allow!
    // By C++ Rule, & Reference don't accept rvalue(const value), 
    // and the value "&OriginCircle2" is a "const value" which represent mem address of OriginCircle2 object.
    // (I consider it's because there is no mem address of const value existed, and reference is an mem address of some variable in actual.)
    


    
}