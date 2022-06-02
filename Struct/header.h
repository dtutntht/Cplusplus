#include <iostream>

using namespace std;

struct circle{
    int radius = 0;
    int height = 0; 
    int area = 0; 

};

circle distribute_value(circle & c, int r, int h)
{
    cout << "replace " << c.height << " by " << h << endl;
    cout << "replace " << c.radius << " by " << r << endl;
    c.height = h;
    c.radius = r;
    cout << "new height : " << c.height << endl;
    cout << "new radius : " << c.radius << endl;

    return c;

}

void copy_circle(circle &c1,  circle &c2)
{

    c2.height = c1.height;
    c2.radius = c1.radius; 
    
    cout << "c2 height : " << c2.height << endl;
    cout << "c2 radius : " << c2.radius << endl;
}

void copy_circle_pointer(circle *c1, circle *c2)
{

    c2->height = c1->height;
    c2->radius = c1->radius; 
    
    cout << "c2 height : " << c2->height << endl;
    cout << "c2 radius : " << c2->radius << endl;

}

void copy_circle_pointer_ref(circle *& c1, circle *& c2)
{

    c2->height = c1->height;
    c2->radius = c1->radius; 
    
    cout << "c2 height : " << c2->height << endl;
    cout << "c2 radius : " << c2->radius << endl;


}

circle * copy_circle_pointer_return(circle *c1, circle *c2)
{
    
    c2->height = c1->height;
    c2->radius = c1->radius; 
    
    //cout << "c2 height : " << c2->height << endl;
    //cout << "c2 radius : " << c2->radius << endl;
    return c2;

}

int cal_area(circle * c, int r)
{
    c->area = r * r * 3.14159;
    cout << "area = " << c->area << endl;
    return c->area;
}