#include <iostream>
#include <cstdlib>

class Queue {
public:
    static const int MAX_SIZE = 100; // Maximum size of the queue
    int arr[MAX_SIZE];
    int front, rear;

    Queue() : front(-1), rear(-1) {}

    void enqueue(int x) {
        if (rear == MAX_SIZE - 1) {
            std::cout << "Queue Overflow: Cannot enqueue element, queue is full.\n";
            return;
        }

        if (front == -1) {
            front = 0; // If the queue was empty, set front to 0
        }

        arr[++rear] = x;
    }

    int dequeue() {
        if (front == -1) {
            std::cout << "Queue Underflow: Cannot dequeue element, queue is empty.\n";
        
        }

        int dequeuedElement = arr[front];

        if (front == rear) {
            front = rear = -1; // If there was only one element, reset front and rear
        } else {
            front++;
        }

        return dequeuedElement;
    }

    int peek() {
        if (front == -1) {
            std::cout << "Queue is empty.\n";
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    Queue myQueue;


    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);


    std::cout << "Front element: " << myQueue.peek() << std::endl;


    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;


    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
