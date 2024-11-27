#include <iostream>

using namespace std;
#include "LINKED LIST.h"



int main()
{
    LinkedList mylist;


    mylist.push(2);
    mylist.push(3);
    mylist.push(4);
    mylist.display();
    int data=0;
    mylist.pop(data)?cout<<" out "<<data<<endl:cout<<"it's empty\n ";
    mylist.display_new();
    mylist.peek(data)?cout<<" peak "<<data<<endl:cout<<"it's empty\n ";






    return 0;
}

