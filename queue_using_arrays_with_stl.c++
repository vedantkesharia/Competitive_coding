#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Enqueueing elements into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Displaying the front element
    std::cout << "Front element: " << myQueue.front() << std::endl;

    // Dequeueing elements from the queue
    myQueue.pop();
    std::cout << "Dequeued element." << std::endl;

    // Checking if the queue is empty
    std::cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
