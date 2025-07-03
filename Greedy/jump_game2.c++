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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, nums[i]+i);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};




