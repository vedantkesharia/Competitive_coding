#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for(auto it : s){
            if(isalnum(it)){
                filtered+=tolower(it);
            }
        }
        
        int n = filtered.length();
        int i=0;
        int j=n-1;
        while(i<j){
            if(filtered[i]!=filtered[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};





