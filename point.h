#ifndef POINT_H
#define POINT_H

class point
{
private :
    int x, y;
public:
    point(int x = 0,int y = 0);//constructeur
    ~point();
    int getx() const; //accesseurs
    int gety() const;
    void setx(int,int); // CHANGEMENT DE X PRENANT EN COMPTE LE DEPLACEMENT A VENIR
    void setx(int);
    void sety(int);
    void deplace(int,int);
};

#endif
