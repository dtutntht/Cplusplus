#include <iostream>
#include <string.h>
#include <windows.h>
#include "header.h"

using namespace std; 
void cellphone ();
void cell_pointer ();
struct cellphone{
    string brand;
    string model;
    int generation; 
    int price;
    char rank;
}*samsung_pointer, *nokia_pointer = new struct cellphone;

// Use typeset to give  structure "cellphone2" a alias "samsung" and can directly use it to create variable group.
typedef struct cellphone2{
    string brand;
    string model;
    int generation; 
    int price;
    char rank;
}samsung_struct;



int main ()
{
    /*
    cout << "hello world" << endl;
    cout << endl;
    cout << "Normal struct : " << endl;
    cout << endl;
    cellphone ();
    cout << "-----------------------------------------" << endl;
    cout << "Pointer struct : " << endl;
    cout << endl;
    cell_pointer ();
    cout << "-----------------------------------------" << endl;
    cout << "Typeset for struct : " << endl;
    cout << endl;
    samsung_struct S20; // Try the typeset
    S20.brand = "Samsung";
    cout << S20.brand << endl;
    */
    const circle a{
        .radius=10,
        .height=100
    };

    

    circle cir1;

    distribute_value (cir1,10,50);
    cout << cir1.height << endl;
    cout << cir1.radius << endl;
    cout << &cir1 << endl;;

    cout << "######################" << endl;

    circle cir2;

    copy_circle(cir1,cir2);
    cout << cir2.height << endl;
    cout << cir2.radius << endl;
    cout << &cir2 << endl;;

    cout << "######################" << endl;

    circle * cir3 = new circle;
    copy_circle_pointer(&cir1,cir3);
    cout << cir3->height << endl;
    cout << cir3->radius << endl;
    cout << &cir3 << endl;
    
    cout << "######################" << endl;
    
    circle * cir4 = new circle;
    // "&cir1" is a right value (rvalue), which mean this value is an temporary value and no related address
    // if we can set rvalue as value of argument in function, if we
    circle * cir1_adr = &cir1;
    copy_circle_pointer_ref(cir1_adr,cir4); 
    cout << cir4->height << endl;
    cout << cir4->radius << endl;
    cout << &cir4 << endl;

    cout << "######################" << endl;

    circle * cir5 = new circle;
    // Use the new circle presented as "pointer *cir5" to implement next execution.
    cir5 = copy_circle_pointer_return(&cir1, cir5);
    cout << "area of cir5 : " << cal_area(cir5, cir5->radius) << endl;
    // also can do -->   cout << "area of cir5 : " << cal_area(copy_circle_pointer_return(&cir1, cir5) , copy_circle_pointer_return(&cir1, cir5)->radius) << endl;
    cout << cir5->height << endl;
    cout << cir5->radius << endl;
    cout << &cir5 << endl;

    

    
    
    Sleep(1000000); // sleep for 1000 sec to check the result on external terminal
}

void cellphone ()
{

    struct cellphone iphone;
    iphone.brand = "Apple";
    iphone.model = "iphone12 pro";
    iphone.generation = 12;
    iphone.price = 35000;
    iphone.rank = 'S';
    cout << iphone.model << endl;
    // 2 different way to define the variable.
    struct cellphone sony{
        .brand = "Sony",
        .model = "xperia Z1",
        .generation = 1,
        .price = 20000,
        .rank = 'B'
    };
    cout << sony.model << endl;

}

void cell_pointer ()
{
    // there are 3 ways to create a struct group, as below : 
    struct cellphone * iphone_pointer;
    iphone_pointer = new struct cellphone;
    cout << "Check iphone_pointer address after new the group : " << iphone_pointer << endl;
    iphone_pointer->model = "Iphone6s";
    iphone_pointer->price = 28000;

    cout << "iphone_pointer->model is : " << iphone_pointer->model << endl;
    cout << "iphone_pointer->price is : " << iphone_pointer->price << endl;
    cout << "iphone_pointer->model address is : " << &iphone_pointer->model << endl;
    cout << "iphone_pointer->price address is : " << &iphone_pointer->price << endl;

    cout << "############################" << endl;

    samsung_pointer = new struct cellphone;
    cout << "Check samsung_pointer address after new the group : " << samsung_pointer << endl;
    samsung_pointer->model = "S22 Ultra";
    samsung_pointer->price = 32000;

    cout << "samsung_pointer->model is : " << samsung_pointer->model << endl;
    cout << "samsung_pointer->price is : " << samsung_pointer->price << endl;
    cout << "samsung_pointer->model address is : " << &samsung_pointer->model << endl;
    cout << "samsung_pointer->price address is : " << &samsung_pointer->price << endl;

    cout << "############################" << endl;

    cout << "Check nokia_pointer address after new the group : " << nokia_pointer << endl;
    nokia_pointer->model = "3310" ;
    nokia_pointer->price = 5000;

    cout << "nokia_pointer->model is : " << nokia_pointer->model << endl;
    cout << "nokia_pointer->price is : " << nokia_pointer->price << endl;
    cout << "nokia_pointer->model address is : " << &nokia_pointer->model << endl;
    cout << "nokia_pointer->price address is : " << &nokia_pointer->price << endl;
    

}




