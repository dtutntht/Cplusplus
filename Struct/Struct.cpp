#include <iostream>
#include <string.h>
#include <windows.h>

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
