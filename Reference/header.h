#include <iostream>
using namespace std; 

void change_value1(int & a);
void change_value2(int * & b);
void change_value3(int * c);
int get_value4(const int & d);
int & get_value5(int & e);
int & get_value6(int * & f);

class circle{

public:
    int radius;
    void show_girth(){
        double girth = radius * 2 * 3.1415926;
        cout << "Girth of the circle is : " << girth << endl;
    }
    void show_area(){
        double area = radius * radius * 3.1415926 ;
        cout << "Area of the circle is : " << area << endl;
    }

};

circle & change_radius(circle & c, int r = 0); // initialize integer r as 0
circle *& change_radius2(circle *& c, int r = 0); // initialize integer r as 0

void change_value1(int & a)
{
    
    a+=100;
    
}
void change_value2(int * & b)
{
    
    *b+=1000;
    
}

void change_value3(int * c)
{
    
    *c+=10000;
    
}

int get_value4(const int & d)
{
    
    // d+=100000; //d is declared as constant so it is a read-only value, not modifyable

    return d;

}

int & get_value5(int & e)
{

    return e;

}

int & get_value6(int * & f)
{

    return *f;

}

circle & change_radius(circle & c, int r)
{
    c.radius = r;
    return c;
}

circle *& change_radius2(circle *& c, int r)
{
    c->radius = r;
    return c;
}