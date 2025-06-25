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
    int findWays(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        
        if(nums[0]!=0 && nums[0]<=target){
            dp[0][nums[0]] = 1;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=target;t++){
                int notTaken=dp[ind-1][t];
                int taken = 0;
                if(nums[ind]<=t){
                    taken = dp[ind-1][t-nums[ind]];
                }
                dp[ind][t] = (notTaken+taken);
            }
        }
        return dp[n-1][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        } 
        
        if(totSum-target<0 || (totSum-target)%2!=0){
            return 0;
        }
        
        return findWays(nums,(totSum-target)/2);
    }
};



