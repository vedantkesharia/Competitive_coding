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
    int removeElement(vector<int> &nums, int val)
    {
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end())
        {
            if (*iter == val)
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
    vector<int> nums = {3, 2, 2, 3, 4, 5, 2};
    int valToRemove = 2;

    Solution solution; 

    int newSize = solution.removeElement(nums, valToRemove);

    std::cout << "New vector size: " << newSize << std::endl;
    std::cout << "Updated vector: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}