#include <iostream>
#include <string.h>
// #include <windows.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include "Chap4_CompoundType.h"
#include <climits>
void TestCin();
void enumerate();
void pointer_array();
void pointer_char_string();
char * pointer_new_delete();
using namespace std; 

int main(){

    cout << "Hello World!" << endl;
    cout << "--------------------------------------" << endl;
    //TestCin();
    cout << "--------------------------------------" << endl;
    //enumerate();
    cout << "--------------------------------------" << endl;
    pointer_array();
    cout << "--------------------------------------" << endl;
    pointer_char_string();
    cout << "--------------------------------------" << endl;
    char * catcher;
    
    catcher = pointer_new_delete();
    cout << "catcher value is : " << catcher << endl;
    cout << "catcher value is : " << (void *)catcher << endl;
    //delete [] catcher;
    cout << "--------------------------------------" << endl;
    sleep(1000);
}

void TestCin(){
    char keyword[100] = {};
    string keyword2;
    char buffer[512] = {};
    string filename = "log.txt";
    fstream log;
    log.open(filename,std::ios_base::app);    
    cout << "Input the keyword!" << endl;
    cin.getline(keyword,100); // cin.getline is to deal with the basic c++ type like int, char..., string is not.
    cout << "Input the keyword2!" << endl;
    getline(cin,keyword2); // Due to string can be seen as a specific class, so need to use specific getline method containing in string library. 
    cout << "Keyword as below : " << endl;
    cout << "********************" << endl;
    cout << keyword << endl;
    cout << keyword2 << endl;
    cout << "********************" << endl;
    log << "Your input keyword is : " << keyword << endl;
    log << "Your input keyword2 is : " << keyword2 << endl;
    log.close();
    

    // Try multiple way to read data from txt file down below.
    log.open(filename,std::ios_base::in);
    log.read(buffer,sizeof(buffer));
    cout << filename << "'s content is : " << endl;
    cout << buffer << endl; 
    log.close();

    cout << "********************" << endl;
    log.open(filename,std::ios_base::in);
    string tmp;
    while (getline(log,tmp)){
    cout << tmp << endl;
    }
    log.close();
}

void enumerate (){
    // I'm not sure what is enumerate used for......
    enum rainbow {
        red,
        orange,
        yellow,
        green,
        blue,
        indigo,
        purple

    };
    rainbow sky1;
    sky1 = blue;
    cout << sky1 << endl;

    
}

void pointer_array (){
    short array_1[5] = {1,2,3,4,5};
    short * p1 = array_1;
    short * parray_2 = new short [5]{2,4,6,8,10};
    cout << "array_1 #1 = " << *p1 << endl;
    cout << "parray_2 #5 = " << parray_2[4] << endl;
    cout << "parray_2 #5 = " << *(parray_2 + 4) << endl;
    cout << "parray_2 #5 (error) = " << *parray_2 + 4 << "   --> It become to get value of first index and add 4 on this value, which is 2+4" << endl;
    cout << "size of parray_2 = " << sizeof(&parray_2) << endl;
    cout << "size of array_1 = " << sizeof(array_1) << endl;
   
}

void pointer_char_string (){

    const char * dog = "sunny";
    cout << "dog is : " << dog << endl;
    cout << "dog address is : " << &dog << "   --> This represent the address of \"the address of this pointer\", instead of address of string \"sunny\"" << endl;
    cout << "dog is : " << (int *) dog << "   -->casting the pointer to other type like int, to show the address of value." << endl;
   
}

char * pointer_new_delete (){
    char temp[80] = "I can bare almost any how!";
    cout << temp << endl;
    char * pointer_correct  = new char;
    strcpy(pointer_correct, temp);
    char * pointer_fault;
    pointer_fault=temp;
    cout << "Correct pointer value : " << pointer_correct << endl;
    cout << "Correct Pointer address : " << (void *) pointer_correct << endl;
    cout << "Fault Pointer value : " << pointer_fault << endl;
    cout << "Fault Pointer address : " << (void *) pointer_fault << endl;
    cout << "*******************" << endl;
    // You can try to return "pointer_correct" and "pointer_fault" to see the cout result at main function.
    // pointer_correct's address is created by new, so it won't disappear after THIS function finished executed.
    // pointer_fault's address is distributed in function with OOO=XXX, which will disappear after THIS function finished executed.
    // Which cause the fault pointer's value can't be read properly when in main function!!
    // (Due to the fault one isn't created by new, so it can't be DELETED by delete!!)
    // THIS IS HOW C++ CONTROL THE MEMORY, REFER TO CHAP4, PAGE 182-183
    return pointer_fault;
    
}