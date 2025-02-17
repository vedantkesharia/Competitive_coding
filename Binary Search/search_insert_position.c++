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
    int searchInsert(vector<int> &nums, int target)
    {
       int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3,4,6,7,8,9};
    int target = 5;
    cout<<solution.searchInsert(nums,target)<<endl;
    return 0;
}