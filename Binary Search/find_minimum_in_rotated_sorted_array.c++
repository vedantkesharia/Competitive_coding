#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int minimum = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid])
            {
                minimum = min(minimum, nums[low]);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                minimum = min(minimum, nums[mid]);
            }
        }
        return minimum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.findMin(nums) << endl;
    return 0;
}