#include <iostream>
#include <string.h>

using namespace std; 
void point_new();
void pointer_as_argument(int *p);
//int pointer_array_function_wrong (int a[]);
int pointer_array_function_correct (int *a, int size);
void pointer_char(char *a, char *B);

//*******************************************************
int main ()
{
    
    cout << "hello world" << endl;
    
    //point_new();
    /*
    int a=150;
    cout << "main : origin a = " << a << endl;
    pointer_as_argument(&a);
    cout << "main : after a = " << a << endl;
    */
    /*
    //int array[5]={1,2,3,45,900};
    //int size = sizeof(array)/sizeof(array[0]);
    //int total = pointer_array_function_wrong(array);
    //int total = pointer_array_function_correct(array, size); // array can be used for : &array[0]
    //cout << "return of pointer_array_function_wrong = " << total << endl;
    //cout << "return of pointer_array_function_correct = " << total << endl;
    */

    char A_main[20] = "charlie";
    char B_main[20] = "Chris";
    // char *B_main = "Chris";
    // for B_main, it is stored at the conpile time and as "const", so we can't modified the value of it.
    // B_main[0] = "Z"; // this is not allowed.
    pointer_char(A_main, B_main) ;


}

//*******************************************************

void point_new()
{


    cout << "#######################################" << endl;

    int *  p;
    cout << "Address : " << p << endl;
    p = new int;
    *p = 50;

    cout << "Address : " << p << endl;
    cout << "Value : " << *p << endl;
    int * p_backup;
    p_backup = p;
    cout << "p_backup : " << p_backup << endl;
    cout << "#######################################" << endl;

    delete p;
    cout << "Address : " << p << endl;
    cout << "Value : " << *p << endl;

    cout << "#######################################" << endl;

    *p = 5000;
    int p_value = *p;
    int * p_value_p = &p_value;
    cout << "Address : " << p << endl;
    cout << "Value : " << *p << endl;
    cout << "Address of p_value : " << p_value_p << endl;
    cout << "Value : " << *p_value_p << endl;
    cout << "#######################################" << endl;

    //p= new int ;
    //cout << "Address : " << p << endl;

    cout << "#######################################" << endl;
}

//*******************************************************

void pointer_as_argument (int *p)
{
    cout << "pointer_as_argument : origin a = " << *p << endl;
    *p = *p +1;
    cout << "pointer_as_argument : after a = " << *p << endl;

}

//*******************************************************
/*
int pointer_array_function_wrong (int a[])
{
    int i, sum = 0;
    int size = sizeof(a)/sizeof(a[0]);
    // size of a will be only "4", not 4 * 5 = 20, 
    // due to the "pointer_array_function" will only receive the "reference" of the specific array, 
    // which is equal to "int *a", same as the memory address of first element, 
    // it make sense, if array stored 2 billions element, copy whole array into another stack of memory is insane!
    cout << "sizeof a = " << sizeof(a) << endl;
    
    cout << "print a =" << a <<endl;
    for (i=0;i<size;i++)
    {
        cout << i << "th = " << a[i] << endl;
        sum +=a[i]; 
    }
   cout << "sum in function = " << sum << endl;
    return sum;
}
*/
//*******************************************************

int pointer_array_function_correct (int *a, int size)
{
    int i, sum = 0;

    for (i=0;i<size;i++)
    {
        cout << i << "th = " << a[i] << endl;
        sum += a[i];
    }
       cout << "sum in function = " << sum << endl;
    return sum;
}

//*******************************************************

void pointer_char(char *A, char *B)
{

    char D[6] = "timmy";

    cout << sizeof(D) / sizeof(D[0]) << endl;
    cout << strlen(D) << endl;
    cout << D << endl ;
    cout << "***********************" << endl;
    char * d = &D[0];
    cout << d << endl;
    cout << *d << endl;
    cout << d[4] << endl;
    cout << "***********************" << endl;
    cout << A << endl;
    int cnt = 0;
    while(*A != '\0'){

        cout << "count = " << cnt << ", char = " << *A << endl;
        A = A+1;
        cnt = cnt+1;
    }
    cout << "***********************" << endl;
    cout << B << endl;
    cnt = 0;
    while(*B != '\0'){

        cout << "count = " << cnt << ", char = " << *B << endl;
        B = B+1;
        cnt = cnt+1;
    }

}

