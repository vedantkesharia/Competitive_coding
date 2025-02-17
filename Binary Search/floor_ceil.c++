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

int ceil(vector<int> nums, int target)
{
    int low = 0;
    int high = nums.size();
    int ans = nums.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int floor(vector<int> nums, int target)
{
    int ans = -1;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= target)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        return ans;
    }
}

int main()
{
    vector<int> nums = {1, 2, 8, 10, 10, 12, 19};
    int target = 11;
    cout << ceil(nums, target) << endl;
    cout << floor(nums, target) << endl;
    return 0;
}