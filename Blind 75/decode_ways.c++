
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
    int numDecodings(string s) {
         int n = s.size();
        if (n == 0) return 0;

        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; i++) {
            int oneDigit = s[i - 1] - '0';
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if (oneDigit >= 1)
                dp[i] += dp[i - 1];

            if (twoDigits >= 10 && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};