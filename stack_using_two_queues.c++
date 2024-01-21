#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

//Implementing using 2 queues

//Approach2

//Algo for push 
//Step 1: push element in q2
//Step 2: shift all elements of q1 to q2
//Step 3: swap q1 and q2

class MyStack {
public:

    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        //swapping
        queue<int>q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() {
        if(q1.empty()){
            return 0;
        }
        else{
            int x = q1.front();
            q1.pop();
            return x;
        }
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;

 
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);


    cout << "Top element: " << myStack.top() << endl;


    cout << "Popped element: " << myStack.pop() << endl;


    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    return 0;
}
