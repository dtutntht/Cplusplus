class rectangle{
    int length;
    int width;
    
    public:
    void set_length (int length);
    
    int get_length ();

    void set_width (int width);
    
    int get_width ();

    rectangle(int length = 0, int width = 0){
        
        set_length(length);
        set_width(width);
    }
};

void rectangle :: set_length(int length){

    if (length <= 100 && length >= 0){
        this->length = length;
    } else {
        this->length = 0;
    }
    
}

int rectangle :: get_length(){
    
    return this->length;
    
}

void rectangle :: set_width(int width){

    if (width <= 100 && width >= 0) {
        this->width = width;
    } else {
        this->width = 0;
    }

}

int rectangle :: get_width(){

    return this->width;
    
}

//--------------------------------------------------------------------------------

class circle{
    int radius;
    int area;
    
    public:
    void set_radius (int radius);
    
    int get_radius ();

    void set_area (int area);
    
    int get_area ();

    circle(int radius = 0, int area = 0){
        this->radius = 0;
        this->area = 0;
        set_radius(radius);
        set_area(area);
    }
};


void circle :: set_radius(int radius){

    if (radius <= 100 && radius >= 0){
        this->radius = radius;
    }
    
}

int circle :: get_radius(){
    
    return this->radius;
    
}

void circle :: set_area(int area){

    if (area <= 100 && area >= 0) {
        this->area = area;
    }

}

int circle :: get_area(){

    return this->area;
    
}
