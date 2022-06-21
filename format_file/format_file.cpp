#include <iostream>
#include <string.h>
#include <fstream>
#include "windows.h"
#include <cstdio>
#include <typeinfo>
using namespace std; 


int main ()
{


    cout << "hello world" << endl;
    cout << endl;
    ifstream sum_file;
    sum_file.open("WinBatch.log");

    string tmp;
    int line_cnt=0;

    while (getline(sum_file, tmp, '\n'))
    {
        line_cnt++;
    }
    cout << line_cnt << endl;

    sum_file.close();

    sum_file.open("WinBatch.log");
    
    string array[line_cnt];
    int i=0;
    string line; 
    while (getline(sum_file, line))
    {

        array[i]=line;
        i++;
    }
    int j;
    const char * d=";";
    char * word;
 
    int j;
    const char * d=";";
    char * word;

    for (j=2;j<line_cnt;j++)
    {

        char * input = &array[j][0];
        char * word = strtok(input,d);
        while (word != NULL)
        {
            printf("%-10s | ", word);
            word = strtok(NULL,d);
        }
        cout << endl;
    }
    sum_file.close();



    Sleep(10000000);

}

