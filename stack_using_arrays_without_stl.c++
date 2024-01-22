#include <iostream>
#include <cstdlib>

class Stack {
public:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    int arr[MAX_SIZE];
    int top; // Index of the top element

    Stack() : top(-1) {}

    void push(int x) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow: Cannot push element, stack is full.\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow: Cannot pop element, stack is empty.\n";
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty.\n";
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack myStack;

    // Pushing elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Displaying the top element
    std::cout << "Top element: " << myStack.peek() << std::endl;

    // Popping elements from the stack
    std::cout << "Popped element: " << myStack.pop() << std::endl;

    // Checking if the stack is empty
    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
