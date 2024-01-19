#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

// 219 Contains duplicate 2

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); ++i)
        {
           
            if (seen.find(nums[i]) != seen.end())
            {
                return true;
            }

            
            seen.insert(nums[i]);

           
            if (seen.size() > k)
            {
                seen.erase(nums[i - k]);
            }
        }

        return false;
    }

};

int main()
{
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;

    Solution solution;
    cout << boolalpha << solution.containsNearbyDuplicate(nums1, k1) << endl; 
    cout << boolalpha << solution.containsNearbyDuplicate(nums2, k2) << endl;
    cout << boolalpha << solution.containsNearbyDuplicate(nums3, k3) << endl; 

    return 0;
}