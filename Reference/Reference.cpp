#include <iostream>
#include <string.h>
#include <windows.h>
#include "header.h"

using namespace std; 

// void reference_variable();
// void reference_parameter();
void reference_returned();

int main ()
{
    
    cout << "hello world" << endl;

    // reference_variable();
    //reference_parameter();
    reference_returned();

    Sleep(1000000); // sleep for 1000 sec to check the result on external terminal
}



void reference_variable()
{
    cout << "Normal variable : " << endl;
    cout << "\n";

    string a = "Faker is good at Zoe.";
    string & b = a;

    cout << "Before MSI : " << b << endl;
    b = "Faker's Zoe sucks as funk :)";
    cout << "####### MSI #######" << endl;
    cout << "After MSI : " << a << endl;

    cout << "-------------------------------" << endl;

    cout << "Pointer variable : " << endl;
    cout << "\n";
    
    string * c = new string;
    *c = "Craps sucks!";
    string * & d = c;
    
    cout << "Before MSI : " << *d << endl;
    *d = "Caps is god!";
    cout << "####### MSI #######" << endl;
    cout << "After MSI : " << *c << endl;

}

//*************************************

void reference_parameter()
{

    int A = 10;
    change_value1(A);
    cout << A << endl;

    int * B = new int;
    *B = 10;
    change_value2(B);
    cout << *B << endl;
    
    int C = 10;
    change_value3(&C);
    cout << C << endl;
    
    int D = 10;
    cout << "before modified D = " << D << endl;
    // DD is the integer value returned by get_value4(D), and this function is an integer
    // so when I modified D, DD will still the same because it is another value which been stored in another memory address.
    int DD = get_value4(D);
    D = 999;
    cout << "after modified D = " << D << endl;
    cout << "get_value4 returned original D = " << DD << endl;
    

}



void reference_returned()
{

    int E = 100;
    cout << "before modified E = " << E << endl;
        // EE is the reference of the "get_value6()" function, and this function is the reference of E
    // So when I modified E value, print FF will get same value as E due to they are eventually the same value "E" at same memory address
    int & EE = get_value5(E);
    E = 99;
    cout << "after modified E = " << E << endl;
    cout << "int & EE = get_value5(E) = " << EE << endl << endl;

    int * F = new int;
    *F = 1000;
    cout << "before modified *F = " << *F << endl;
    // FF is the reference of the "get_value6()" function, and this function is the reference of *F
    // So when I modified *F value, print FF will get same value as *F due to they are eventually the same value "*F" at same memory address
    int & FF = get_value6(F); 
    *F = 999;
    cout << "after modified F = " << *F << endl;
    cout << "int & FF = get_value6(F) = " << FF << endl << endl;


    // here is Normal variable part...
    class circle ball1;
    ball1.radius = 10;
    ball1.show_girth();
    ball1.show_area();
    cout << "---------- \"executing change_radius\" funciton ----------" << endl;
    change_radius(ball1, 200).show_area();   

    cout << endl << "#########################################################"  << endl << endl;;
    // here is pointer part...
    circle * ball2 = new circle;
    ball2->radius = 70;
    ball2->show_girth();
    ball2->show_area();
    cout << "---------- \"executing change_radius2\" funciton ----------" << endl;
    change_radius2(ball2, 90)->show_area();
}

