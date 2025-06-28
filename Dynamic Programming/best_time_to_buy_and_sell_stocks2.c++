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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        dp[n][0]=0; 
        dp[n][1]=0;
        
        int profit = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    profit = max(dp[ind+1][0], -prices[ind]+dp[ind+1][1]);
                }
                
                if(buy==1){
                    profit = max(dp[ind+1][1], prices[ind]+dp[ind+1][0]);
                }
                dp[ind][buy] = profit; 
            }
            
        }
        return dp[0][0];
    }
};



