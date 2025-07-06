#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>


using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<int,int> mpp;
        for(int i=0;i<256;i++){
            mpp[i] = -1;
        }
        int left = 0;
        int right = 0;
        int maxlen = 0;
        while(right<n){
            if(mpp[s[right]]!=-1){
                if(mpp[s[right]]>=left){
                    left = mpp[s[right]]+1;
                }
            }
            int len = right-left+1;
            maxlen = max(len,maxlen);
            mpp[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};



