#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "point.h"
#include "forme.h"

class rectangle : public forme
{
    protected:
    point p1,p2;
    int length;
    int width;
    int m_couleur;
    public:
    rectangle(int x1 = 0,int x2 = 0,int y1 = 0,int y2 = 0);
    rectangle(int, int, int, int, int);
    rectangle(point, point);
    rectangle(point, point, int);
    rectangle(point);
    ~rectangle();
    void deplace_rect(int,int);
    void affiche();
    point getP1();
    point getP2();
    void setP1(point);
    void setP2(point);
    int getLength();
    void setColor(int);
    bool dans_rect(int, int);
    bool dans_rect(point);
};

#endif // RECT_H_INCLUDED
