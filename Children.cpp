#include "Children.h"
#include <iostream>
#include <cmath>
using namespace std;

//constructor
Children::Children(void)
{
    head= tail=NULL;
    size=0;
}

//destructor, release all children
Children::~Children(void)
{
    while(head)
    {
        Child* next=head->getNext();
        delete head;
        head=next;
    }
}

//responds to the SPAWN command
void Children::spawn(double x, double y)
{
    //out of first quadrant
    if(x<=0 || y<=0)
    {
        cout<<"failure"<<endl;
        return;
    }
    //create a new child
    Child* child=new Child(x, y);
    //as the first child
    if(tail==NULL)
    {
        head=tail=child;
    }
    //append to last location
    else
    {
        tail->setNext(child);
        tail=child;
    }
    size++;
    cout<<"success"<<endl;
}

//TIME command
void Children::time(double t)
{
    //when time >0
    if(t>=0)
    {
        //get first child
        Child* child=head;
        //reset head, tail, and size to make a new list
        head=tail=NULL;
        size=0;
        //deal with each child
        while(child)
        {
            //get next child first from original list
            Child* nextChild=child->getNext();
            //disconnect the relationship
            child->setNext(NULL);
            //calculate new location
            double dx=t*cos(atan2(child->getY(), child->getX()));
            double dy=t*sin(atan2(child->getY(), child->getX()));
            child->setX(child->getX()-dx);
            child->setY(child->getY()-dy);
            //check whether out of first quadrant, remove it if it is
            if(child->getX()<=0 || child->getY()<=0) delete child;
            //current child is valid, keep it in list
            //the first one
            else if(head==NULL)
            {
                head=tail=child;
                size++;
            }
            //append to tail
            else
            {
                tail->setNext(child);
                tail=child;
                size++;
            }
            //deal with next child in original list
            child=nextChild;
        }
    }
    //remove some children too close to wolf
    else
    {
        Child* child=head;
        //reset head, tail, and size to make a new list
        head=tail=NULL;
        size=0;
        //deal with each child
        while(child)
        {
            //get next child first from original list
            Child* nextChild=child->getNext();
            child->setNext(NULL);
            //check whether the distance to origin < 1m
            if(child->distanceToOrigin()<1) delete child;
            //current child is valid, keep it in list
            //the first one
            else if(head==NULL)
            {
                head=tail=child;
                size++;
            }
            //append to tail
            else
            {
                tail->setNext(child);
                tail=child;
                size++;
            }
            //deal with next child in original list
            child=nextChild;
        }
    }
    //output the number of playing children
    num();
}

//output the number of playing children
void Children::num()
{
    cout<<"number of children still playing: "<<size<<endl;
}

//PRT command
void Children::prt(double D)
{
    int n=0;
    Child* child=head;
    while(child)
    {
        //output each child's distance within given range
        if(child->distanceToOrigin()<D)
        {
            cout<<child->getX()<<" "<<child->getY()<<" ";
            n++;
        }
        //deal with next child
        child=child->getNext();
    }
    //no children within the given range
    if(n==0) cout<<"no children within distance";
    cout<<endl;
}

//game over
void Children::over()
{
    if(size>0) cout<<"the players win"<<endl;
    else cout<<"the wolf wins"<<endl;
}