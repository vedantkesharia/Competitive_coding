#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mpp.find(complement) != mpp.end()) {
            return {mpp[complement], i};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1}; 
    }
};
