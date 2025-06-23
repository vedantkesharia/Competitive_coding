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
    bool subsetSumToK(int n, int k ,vector<int>& nums){
        vector<int> prev(k+1,0), cur(k+1,0);
        prev[0] = cur[0] = true;
        if(nums[0]<=k) {
            prev[nums[0]] = true;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind]<=target){
                  take = prev[target-nums[ind]];
                }
                cur[target] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        if(totalSum%2!=0) return false;
        int sum = totalSum/2;
        return subsetSumToK(n,sum,nums);
    }
};