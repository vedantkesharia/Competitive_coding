#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution
{
public:
    //  bool canJump(vector<int>& nums) {
    //     int i = 0;
    //     while (i < nums.size()) {
    //         if (i >= nums.size() - 1 || i + nums[i] >= nums.size() - 1) {
    //             return true;
    //         } else if (nums[i] == 0) {
    //             return false;
    //         } else {
    //             i = i + nums[i];
    //         }
    //     }
    //     return false;
    // }
     bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReachable) {
                return false; 
            }
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable >= nums.size() - 1) {
                return true; 
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test Case 1: " << (solution.canJump(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test Case 2: " << (solution.canJump(nums2) ? "true" : "false") << endl;

    vector<int> nums3 = {2, 0};
    cout << "Test Case 3: " << (solution.canJump(nums3) ? "true" : "false") << endl;

    vector<int> nums = {2, 5, 0, 0};
    cout << "Test Case 4: " << (solution.canJump(nums) ? "true" : "false") << endl;

    return 0;
}
