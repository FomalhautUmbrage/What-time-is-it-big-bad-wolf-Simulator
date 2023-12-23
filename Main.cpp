#include "Children.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Children children;
    string command;
    while(cin>>command)
    {
        //show menu
        // cout<<"Input command SPAWN x y, TIME t, NUM, PRT, or OVER please: ";
        //deal with each command
        if(command=="SPAWN")
        {
            double x, y;
            cin>>x>>y;
            children.spawn(x, y);
        }
        else if(command=="TIME")
        {
            double t;
            cin>>t;
            children.time(t);
        }
        else if(command=="NUM")
        {
            children.num();
        }
        else if(command=="PRT")
        {
            double D;
            cin>>D;
            children.prt(D);
        }
        else if(command=="OVER")
        {
            children.over();
            break;
        }
        //invalid input
        else cout<<"Not supported command"<<endl;
    }

    return 0;
}