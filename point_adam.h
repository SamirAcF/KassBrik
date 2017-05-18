#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

using namespace std;

class point
{
private:
	float x,y;
	float rho,theta; // rho = sqrt(x²+y²) ;
	//tan(theta) = y/x --> theta = arctan(y/x)
	void majpol();
	void majcart();
public:
	//surdéfinition du constructeur : c'est le nombre et le type qui permettent de définir une surdéfinition.
	point();
	point(float);
	point(float,float);
	~point();
	void affiche();
	void init(float, float);
	void deplace(float,float);
	void homothetie(float);
	void rotation(float);
	float getx();
	float gety();

};

point::point()
{
	x=0;
	y=0;
	majpol();
	cout << "constructeur 1" << endl;
}

point::point(float p)
{
	x = p;
	y = p;
	majpol();
	//OU init(p,p)
	//cout << "constructeur 2" << endl;
}
point::point(float px, float py)
{
	x = px;
	y = py;
	majpol();
	// OU  init(px,py)
	//cout << "constructeur 3" << endl;
}
point::~point()
{
    //cout << "destructeur" << endl;
}

void point::affiche()
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "rho="<< rho << endl;
	cout << "theta="<< theta * 180 / M_PI << endl;
}
void point::init(float px,float py)
{
    x = px;
    y = py;
    majpol();
}
void f()
{
    cout << "Je suis dans f" << endl;
    point tmp(999);
    tmp.affiche();
    cout << "Je sors de la fonction" << endl;
}
void point::deplace(float dx, float dy)
{
    x=x+dx;
    y=y+dy;
    majpol();
}

void point::homothetie(float cf)
{
    x= x*cf;
    y= y*cf;
    majpol();
}

void point::majpol()
{
	rho = sqrt(x*x+y*y);
	theta = atan2(x,y);
}
void point::majcart()
{
	x = rho * cos(theta);
	y = rho * sin(theta);
}
void point::rotation(float ang)
{
	//Ang est en degré
	ang = ang * M_PI/ 180;
	theta = theta + ang;
	majcart();
}
float point::getx ()
{
    return x;
}
float point::gety ()
{
    return y;
}
#endif // POINT_H
