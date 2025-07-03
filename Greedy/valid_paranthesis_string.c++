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
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini = mini+1;
                maxi = maxi+1;
            }
            else if(s[i]==')'){
                mini = mini-1;
                maxi = maxi-1;
            }
            else{
                mini = mini - 1;
                maxi = maxi + 1;
            }
            if(mini<0) mini = 0;
            if(maxi<0) return false;
        }
        
        return (mini==0);
    }
};




