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
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i>1){
                take+=prev2;
            }
            int notTake = prev;
            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

