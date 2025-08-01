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
    int maxNonAdjSum(vector<int>& nums) {
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
public:
    int rob(vector<int>&nums){
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1(n);
        vector<int> temp2(n);
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
           
        }
        maxi = max(maxNonAdjSum(temp1),maxNonAdjSum(temp2));
       return maxi;
        
    }
};
