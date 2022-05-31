#include<iostream>  
#include<sstream>        //istringstream 必须包含这个头文件
#include<string>  
#include <fstream>
using namespace std;  
int main()  
{  
    std::filebuf.open("./a.txt",ios::in);
    istringstream iss;
    string str="i an a boy";  
    istringstream is(str);  
    string s;  
    while(is>>s)  
    {  
        cout<<s<<endl;  
    }  
      
} 

