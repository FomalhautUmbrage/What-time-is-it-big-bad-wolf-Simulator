#ifndef CHILDREN_H
#define CHILDREN_H
#include "Child.h"

//all children in the list, it's actual a linked list
class Children
{
public:
	Children(void);
	~Children(void);
    void spawn(double x, double y);
    void time(double t);
    void num();
    void prt(double D);
    void over();
private:
    //points to the first child
	Child* head;
    //points to the last child
    Child* tail;
    //the number of children in list
    int size;
};

#endif
