#ifndef POINT_H
#define POINT_H

class point
{
private :
    float x, y;
public:
    point();
    point(float x,float y);//constructeur
    ~point();
    float getx() const; //accesseurs
    float gety() const;
    void setx(float);
    void sety(float);
    point operator=(point);
    void deplace(float,float);
};

#endif

