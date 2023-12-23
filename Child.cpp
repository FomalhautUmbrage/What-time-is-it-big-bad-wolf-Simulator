#include "Child.h"
#include <iostream>
#include <cmath>
using namespace std;

//constructor
Child::Child(double x, double y)
{
	this->x=x;
    this->y=y;
    next=NULL;
}

//get location x
double Child::getX()
{
    return x;
}

//get location y
double Child::getY()
{
    return y;
}

//set location x
void Child::setX(double x)
{
    this->x=x;
}

//set location y
void Child::setY(double y)
{
    this->y=y;
}

//get next child
Child* Child::getNext()
{
    return next;
}

//set next child
void Child::setNext(Child* next)
{
    this->next=next;
}

//calculate the distance to wolf's location (0, 0)
double Child::distanceToOrigin()
{
    return sqrt(x*x+y*y);
}