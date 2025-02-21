

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


class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size() - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                {
                    return true;
                }
                if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                    low = low + 1;
                    high = high - 1;
                    continue;
                }
                
                if (nums[low] <= nums[mid])
                {
                    if (target >= nums[low] && target <= nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (target >= nums[mid] && target <= nums[high])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            return false;   
        }
    };


int main() {
    Solution s;
    vector<int> nums = {4,4,5,6,7,0,1,2,2,2};
    cout << s.search(nums, 9) << endl;
    return 0;
}