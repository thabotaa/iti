#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class queue {
private:
    int *items;
    int size;
    int rear, Front;

    int isEmpty() {
        return (rear == -1);
    }

    int isFull() {
        return (rear == size - 1);
    }

public:
    queue(int size) {
        this->size = size;
        items = new int[size];
        rear = -1;
        Front = 0;
    }

    int enqueue(int data) {
        if (isFull()) {
            return 0;
        }
        rear++;
        items[rear] = data;
        return 1;
    }

    int dequeue(int &data) {
        if (isEmpty()) {
            return 0;
        }
        data = items[Front];
        for (int i = 0; i < rear; i++) {
            items[i] = items[i + 1];
        }
        rear--;
        return 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "empty queue\n";
            return;
        }
        for (int i = 0; i <= rear; i++) {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    ~queue() {
        delete[] items;
    }
};

#endif // QUEUE_H
