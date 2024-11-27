#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue q(5);  // Specify the size of the queue
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
    int data = 0;
    q.dequeue(data) ? cout << "Out = " << data << endl : cout << "Can't Dequeue\n";
    q.display();

    return 0;
}
