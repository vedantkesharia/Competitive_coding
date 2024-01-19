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
    bool containsDuplicate(vector<int> &nums)
    {
        vector<int>::iterator iter = nums.begin();
        sort(nums.begin(),nums.end());
        while (iter != nums.end()){
            if(iter != nums.begin() && *iter==*(iter-1) ){
                return true;
            }
            else{
               ++iter;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 1, 2, 3, 4, 5};

    cout << "Contains Duplicate in nums1: " << boolalpha << solution.containsDuplicate(nums1) << endl;
    cout << "Contains Duplicate in nums2: " << boolalpha << solution.containsDuplicate(nums2) << endl;

    return 0;
}