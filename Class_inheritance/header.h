class circle{
public:

    int radius;
    int height;
    int * height_p = new int;   // Remember, ALWAYS to new a pointer when declaring it instead of assigning a pointer for random existed value.
    double girth;
    double area;
    double volume;
    
    void SetValue(int R, int H){
        radius=R;
        height=H;
        
    }
    double GetVolume(){

        volume=radius * radius * 3.14159 * height;
        return volume;
        
    }

};
