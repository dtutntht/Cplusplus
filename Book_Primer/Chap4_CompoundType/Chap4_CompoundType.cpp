#include <iostream>
#include <string.h>
// #include <windows.h>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include "Chap4_CompoundType.h"
#include <climits>
void TestCin();
using namespace std; 

int main(){

    cout << "Hello World!" << endl;
    cout << "--------------------------------------" << endl;
    TestCin();
    cout << "--------------------------------------" << endl;
    sleep(1000);
}

void TestCin(){
    char keyword[100] = {};
    char buffer[512] = {};
    string filename = "log.txt";
    fstream log;
    log.open(filename,std::ios_base::app);    
    cout << "Input the keywords!" << endl;
    cin >> keyword;
    cout << "Keyword as below : " << endl;
    cout << "********************" << endl;
    cout << keyword << endl;
    cout << "********************" << endl;
    log << "Your input keyword is : " << keyword << endl;
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
