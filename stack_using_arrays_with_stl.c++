#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Displaying the top element
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Popping elements from the stack
    myStack.pop();
    std::cout << "Elemeny popped." << std::endl;

    // Checking if the stack is empty
    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

