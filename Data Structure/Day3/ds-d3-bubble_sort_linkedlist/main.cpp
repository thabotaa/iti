#include <iostream>
#include "Linked.h"

using namespace std;

int main() {
    LinkedList mylist;
    mylist.add(3);
    mylist.add(2);
    mylist.add(5);
    mylist.add(1);

    cout << "Before sorting: ";
    mylist.display();

    mylist.bubbleSort();

    cout << "After sorting: ";
    mylist.display();

    return 0;
}
