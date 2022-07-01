class shape{
    protected:
    int area, girth;
    public:
    int get_girth(){
        return girth;
    }
    int get_area();
};

int shape :: get_area(){
    return area;
}


