#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

//Implementing using 1 queue

//Approach3

//Algo for push 
//Step 1: push element in queue
//Step 2: pop all elements ahead of it and add them behind newly added element

class MyStack {
public:
	queue<int> que;

	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}


	int pop() {
		int x = que.front();
        que.pop();
        return x;
	}


	int top() {
		return que.front();
	}

	bool empty() {
		return que.empty();
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
