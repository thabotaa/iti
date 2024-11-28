#include <iostream>

using namespace std;


class parent
{
public:
    int x;
    parent()
    {
      x=0;
    }
    parent(int n)
    {
      x=n;
    }


    void method()
    {
    cout<<"\ni'm parent method";
    }
};

class child :public parent
{
public:
    int y;
    child()
    {
     x=y=0;
    }
     child(int n1,int n2)
     {
         x=n1;
         y=n2;
     }


  virtual  void method()
   {
    cout<<"\ni'm child method";
    }
};
class grandchild :public child
{
public:
    int z;

    grandchild()
    {
     x=y=z=0;
    }
     grandchild(int n1,int n2,int n3)
     {
         x=n1;
         y=n2;
         z=n3;
     }


    void method()
   {
    cout<<"\ni'm grandchild method";
    }
};

int main()
{
    parent p1(3);
    parent *pptr;
    pptr=&p1;
    cout<<"\np1.x ="<<p1.x;
    cout<<"\npptr->x ="<<pptr->x;
/// cout<<"p1.y ="<<p1.y;            error can't read y
    p1.method();

    child ch(5,6);
    child *chptr;
    chptr=&ch;
    cout<<"\nch.x ="<<ch.x;
    cout<<"\nch.y ="<<ch.y;           ///  can read y
    cout<<"\nchptr->x ="<<chptr->x;
    ch.method();


    grandchild gch(7,8,9);
    grandchild *gchptr;
    gchptr=&gch;
    cout<<"\ngch.x ="<<gch.x;
    cout<<"\ngch.y ="<<gch.y;
    cout<<"\ngch.z ="<<gch.z;
    cout<<"\ngchptr->x ="<<gchptr->x;
    gch.method();

    cout<<"\n *******************";
    pptr=&ch;
    cout<<"\npptr->method =";
    pptr->method();


    cout<<"\n #############";
    chptr=&gch;
    cout<<"\nchptr->method =";
    chptr->method();





}
