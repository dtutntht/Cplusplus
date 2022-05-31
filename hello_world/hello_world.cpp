#include <iostream>
#include <windows.h>

using namespace std; 

int whileloop(int index);
void forloop(int index);
void arrayinarray();
void pointer();
void coffee_shop();

//*******************************************************
int main ()
{
    
    cout << "hello world" << endl;
    //whileloop(5);
    //forloop(5);
    //arrayinarray();
    //pointer();
    coffee_shop();
}

//*******************************************************

int whileloop (int limit)
{
    int index = 1;
    cout << "input limit!" << endl;
    cin >> limit ;
    while (index < limit)
    {   
        cout << index << endl;
        Sleep(1000);
        index++;
    }
return 0;

}

//*******************************************************

void forloop(int limit)
{
    int index;
    cout << "input limit!" << endl;
    cin >> limit ;
    for (index=1;index<=limit;index++)
    {
        cout << index << endl;
        Sleep(1000);
        index++;
    }
}

//*******************************************************

void arrayinarray()

{

int array_2[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
    int a=sizeof(array_2[0]) / sizeof(array_2[0][0]);
    cout << "a=" << a << endl;
    int index1;
    int index2;
    int array_cnt_1=sizeof(array_2) / sizeof(array_2[0]);
    //cout << "array layer 1 count = " << array_cnt_1 << endl;
    //cout << array_cnt_1 << endl;
    //cout << array_2[0][1] << endl;
    for (index1=0;index1<array_cnt_1;index1++)

    {
        int array_cnt_2=sizeof(array_2[index1]) / sizeof(array_2[index1][0]);
        //cout << "array layer 2 count = " << array_cnt_2 << endl;
        for (index2=0;index2<array_cnt_2;index2++)
        {
            cout << array_2[index1][index2] << "|";
        };
        cout << endl;
    }
    
    Sleep(5000);

}

//*******************************************************

void pointer()
{
    double abc=56123;
    double *abc_p = &abc;
    cout << "abc = " << &abc << endl;
    cout << "abc_p = " << abc_p << endl;
    cout << "*abc_p = " << *abc_p;
}

//*******************************************************

class coffee
{
    // Timmy comment : "private" means only codes that also belongs to the same class can access the code put in private zone.
    private:
        // Variable "store" can only be used by the code in class "coffoe", in this case, I write the "store_select" function
        // to control the value of "store".
        string store;
    public:
        string name;
        string region;
        string roast;

        char rank; 
        int price;

        // This is the constructor which can define the object form, thus can set the object more convenience
        coffee(string in_name, string in_region, string in_roast, int in_price)
        {
            name=in_name;
            region=in_region;
            roast=in_roast;
            price=in_price;
            
            cout << "Coffee's name = " << name << endl;
            cout << "Coffee's region = " << region << endl;
            cout << "Coffee's roast = " << roast << endl;
            cout << "Coffee's price = " << price << endl;
        }

        // Timmy comment : It is the function included in coffee Class, which need to be called as " 'objectname'.price_sorting()" 
        void price_sorting()
        {
            if (price >= 400)
            {
                cout << name << "'s price >= 400" << endl;
                rank='S';
                
            }
        }

        // This is a setter in order to limit the setting value of "store" variable as , for example, in Hsinchu, Taipei and Taichung.
        string store_select(string in_store)
        {
            string store_pool[3]={"Hsinchu", "Taipei", "Taichung"};
            int i;
            int array_cnt=sizeof(store_pool)/sizeof(store_pool[0]);
            
            for (i=0 ; i<array_cnt ; i++)
            {
                // This function(string.compare) is to compare the string.
                // Why I can use in_store.compare is because "in_store" is declare as string when defining it. 
                if ( in_store.compare(store_pool[i]) == 0 ) {
                    store=in_store;
                    cout << "Input Store : " << store << endl;
                    break;
                } else {
                    cout  << i << " : Input Store invalid!" << endl;
                    store="invalid";
                }
            } 
            // This returned value can be used by like cout, to print out the value stored into "store"variable.
            return store;
        }


};

void coffee_shop ()
{

//Object setting section
coffee Coffee_1 ("yirgacheffe","Ethiopia, Africa", "Light roast", 400);
Coffee_1.price_sorting();
Coffee_1.store_select("Hsinchu");



// Output section
cout << "###################" << endl;  
cout << Coffee_1.name << " is from " << Coffee_1.region << ", it's " << Coffee_1.roast << ", and the price is : " << Coffee_1.price << endl;
if (Coffee_1.rank == 'S')
{
    cout << "It is a premium coffee! Rank :" << Coffee_1.rank << endl;
}
cout << "###################" << endl;

cout << Coffee_1.store_select("Miaoli") << endl;

}

//********************************************************

