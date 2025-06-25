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
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n,vector<int>(amount+1,0));
       for(int t=0;t<=amount;t++){
           if(t%coins[0]==0){
               dp[0][t]=t/coins[0];
           }
           else{
               dp[0][t]=1e9;
           }
       }
       
       for(int ind=1;ind<n;ind++){
           for(int target=0;target<=amount;target++){
               int notTake = dp[ind-1][target];
               
               int take = 1e9;
               if(coins[ind]<=target){
                   take=1+dp[ind][target-coins[ind]];
               }
               dp[ind][target] = min(take,notTake);
           }
       }
       int ans = dp[n-1][amount];
       if(ans==1e9) return -1;
       return ans;
    }
};



