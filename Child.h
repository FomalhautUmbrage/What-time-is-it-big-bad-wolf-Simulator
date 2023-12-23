#ifndef CHILD_H
#define CHILD_H

//one child
class Child
{
public:
	Child(double x, double y);
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
	Child* getNext();
	void setNext(Child* next);
    double distanceToOrigin();
private:
    //the location of the child
    double x, y;
    //points to next child
	Child* next;
};

#endif