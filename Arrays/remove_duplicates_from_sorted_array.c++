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
    int removeDuplicates(vector<int> &nums)
    {
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end())
        {
            if (iter != nums.begin() && *iter == *(iter - 1))
            {
                iter = nums.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    cout << "Original vector: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int newSize = solution.removeDuplicates(nums);

    cout << "Vector after removing duplicates: ";
    for (int i = 0; i < newSize; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}