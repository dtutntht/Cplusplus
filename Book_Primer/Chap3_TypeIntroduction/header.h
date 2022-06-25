#include <iostream>

using namespace std;

class circle{
public:

    int radius;
    int height;
    int * height_p = new int;   // Remember, ALWAYS to new a pointer when declaring it instead of assigning a pointer for random existed value.
    double girth;
    double area;
    double volume;
    
    void SetValue(int R, int H){
        radius=R;
        height=H;
        
    }
    double GetVolume(){

        volume=radius * radius * 3.14159 * height;
        return volume;
    }
    void CopyRadiusByVariable_1(circle C){
        radius = C.radius;
        // I can do so because the radius on left is the value of the object which call this function.
        // and this value sourced from same memory address as the object which was declared on main function(or what ever function in main .cpp program.)
        // On the other hand, this means that the memory address of "radius" in this function is same as the OOOO's radius variable in main .cpp program.
        // That's why I can modify radius here by another input object and affect the origin one.
        // ************* It is the property of Class! *************
    }
    circle CopyRadiusByVariable_2(circle C){
       C.radius = radius;
       return C;

    }

    circle * CopyRadiusByPointer_1(circle * C){
        C->radius = radius;
        return C;
    }
    circle * CopyRadiusByPointer_2(){
        
        circle * C = new circle;
        C->radius = radius;
        cout << "Tmp's Address : " << &C->radius << endl;
        return C;

        // In this way, will create a tmp object, give it a radius value by the calling object's radius value
        // we will create a memory block and we can't delete in this function due to we need to return it,
        // it will cause that the temp memory might not be delete, 
        // and it will occupy the RAM and we can't locate it after using this function(Unless user assign it to another pointer and he remember to delete...)
        // ************* WE CAN"T DO THAT! *************
    }

    circle  CopyRadiusReference_1(circle & C){
        C.radius = radius;
        return C;
    
    }
    circle * CopyRadiusReference_2(circle & C){
        C.radius = radius;
        return &C;
    
    }

};

struct circle2{
public:

    int radius;
    int height;
    double girth;
    double area;
    double volume;
    
    void SetValue(circle2 & S, int R, int H){
        S.radius=R;
        S.height=H;
        
    }
    double GetVolume(){

        volume=radius * radius * 3.14159 * height;
        return volume;
        
    }

};