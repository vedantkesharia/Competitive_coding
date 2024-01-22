#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

// Approach 1
//  class MyQueue {
//  public:

//     stack<int> s1;
//     stack<int> s2;

//     MyQueue() {

//     }

//     void push(int x) {
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int pop() {
//         int current = s1.top();
//         s1.pop();
//         return current;
//     }

//     int peek() {
//         return s1.top();
//     }

//     bool empty() {
//         return s1.empty();
//     }
// };

// Optimized way -> Amortized O(1)
class MyQueue
{
public:
    stack<int> s_input;
    stack<int> s_output;

    MyQueue()
    {
    }

    void push(int x)
    {
        s_input.push(x);
    }

    int pop()
    {
        if (!s_output.empty())
        {
            int result = s_output.top();
            s_output.pop();
            return result;
        }
        else
        {
            while (!s_input.empty())
            {
                s_output.push(s_input.top());
                s_input.pop();
            }
            int result = s_output.top();
            s_output.pop();
            return result;
        }
    }

    int peek()
    {
        if (!s_output.empty())
        {
            return s_output.top();
        }
        else
        {
            while (!s_input.empty())
            {
                s_output.push(s_input.top());
                s_input.pop();
            }
            return s_output.top();
        }
    }

    bool empty()
    {
        if (s_output.empty())
        {
            while (!s_input.empty())
            {
                s_output.push(s_input.top());
                s_input.pop();
            }
        }
        return s_output.empty();
    }
};

int main()
{
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    cout << "Front element: " << myQueue.peek() << endl;

    cout << "Dequeue: " << myQueue.pop() << endl;
    cout << "Dequeue: " << myQueue.pop() << endl;

    cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    myQueue.push(4);
    myQueue.push(5);

    cout << "Front element: " << myQueue.peek() << endl;

    return 0;
}
