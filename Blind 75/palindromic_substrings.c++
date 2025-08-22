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
    int countSubstrings(string s) {
        int n = s.length();
        int count=0;
        for(int center=0;center<2*n-1;center++){
            int left = center/2;
            int right = left + center%2;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                count++;
                right++;
            }
        }
        return count;
    }
};