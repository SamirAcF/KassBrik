#ifndef POINT_C
#define POINT_C

point::point() : x(0), y(0){}

point::point(int a): x(a), y(a){}

point::point(int x, int y): x(x), y(y){}

~point(){}

int point::getx(){
    return(x);
}

int point::gety(){
    return(y);
}


#endif
