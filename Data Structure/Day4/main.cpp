#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree tr;
    tr.add(20);
    tr.add(50);
    tr.add(30);
    tr.add(25);
    tr.add(70);
    cout<<"the max depth is "<<tr.getMaxDepth();

    return 0;
}
