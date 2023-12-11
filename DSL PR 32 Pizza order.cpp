#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, capacity;
    int* queue;

public:
    CircularQueue(int size) {
        capacity = size;
        front = rear = -1;
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int orderNumber) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more orders." << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
            queue[rear] = orderNumber;
        } else {
            rear = (rear + 1) % capacity;
            queue[rear] = orderNumber;
        }

        cout << "Order " << orderNumber << " placed successfully." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve." << endl;
            return -1;
        }

        int orderServed = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        cout << "Order " << orderServed << " served." << endl;
        return orderServed;
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxSize;

    CircularQueue orders(maxSize);
    int choice, orderNum;

    do {
        cout << "\n1. Place an order\n2. Serve an order\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!orders.isFull()) {
                    cout << "Enter order number to place: ";
                    cin >> orderNum;
                    orders.enqueue(orderNum);
                }
                break;

            case 2:
                orders.dequeue();
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
