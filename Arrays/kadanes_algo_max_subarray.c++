#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    long long maxi = LONG_MIN; 
    long long sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

       
        if (sum < 0) {
            sum = 0;
        }
    }

    // if (maxi < 0) maxi = 0;

    return maxi;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << solution.maxSubArray(nums);
}