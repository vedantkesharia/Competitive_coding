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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));


        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                unsigned long long notTake = dp[ind - 1][t];
                unsigned long long take = 0;
                if (coins[ind] <= t) {
                    take = dp[ind][t - coins[ind]];
                }
                dp[ind][t] = take + notTake;
            }
        }

        return static_cast<int>(dp[n - 1][amount]);
    }
};
