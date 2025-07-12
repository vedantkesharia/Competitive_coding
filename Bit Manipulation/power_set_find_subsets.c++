#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), subsets = 1 << n;
        vector<vector<int>> ans(subsets);
        for (int i = 0; i < subsets; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};