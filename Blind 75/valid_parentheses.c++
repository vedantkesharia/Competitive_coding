#include <stack>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char c = st.top();
                st.pop();
                if((s[i]==')'&& c =='(')||(s[i]==']'&& c =='[')||(s[i]=='}'&& c =='{')){
                    // If there is nothing between the curly braces, it means that there is no action to be taken when the condition is true. It's a way of saying "if this condition is true, do nothing.
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    Solution solution;


    cout << "Test Case 1: " << (solution.isValid("()") ? "Valid" : "Invalid") << endl;
    cout << "Test Case 2: " << (solution.isValid("()[]{}") ? "Valid" : "Invalid") << endl;
    cout << "Test Case 3: " << (solution.isValid("(]") ? "Valid" : "Invalid") << endl;
    cout << "Test Case 4: " << (solution.isValid("([)]") ? "Valid" : "Invalid") << endl;
    cout << "Test Case 5: " << (solution.isValid("{[]}") ? "Valid" : "Invalid") << endl;

    return 0;
}
