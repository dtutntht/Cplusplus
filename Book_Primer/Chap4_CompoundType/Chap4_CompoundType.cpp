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
using namespace std; 

int main(){

    cout << "Hello World!" << endl;
    cout << "--------------------------------------" << endl;
    //TestCin();
    cout << "--------------------------------------" << endl;
    enumerate();
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