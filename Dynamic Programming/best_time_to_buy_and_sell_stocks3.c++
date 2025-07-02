#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std; 

int maxProfit(vector<int>& prices) {
   int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { 
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                           -prices[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                           prices[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

   
    return dp[0][0][2];
}
