#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        // vector<int>::iterator iter;
        int max_one = INT_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                max_one = max(max_one, count);
            }
            else
            {
                count = 0;
            }
        }
        if (max_one == INT_MIN)
        {
            return 0;
        }
        else
        {
            return max_one;
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1};
    
    cout << "Binary Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int maxConsecutiveOnes = solution.findMaxConsecutiveOnes(nums);

    cout << "Maximum Consecutive Ones: " << maxConsecutiveOnes << endl;

    return 0;
}