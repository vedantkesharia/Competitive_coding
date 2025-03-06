#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution
{
public:
    int sumByD(vector<int> &nums, int divisor)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        if(n>threshold) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (sumByD(nums, mid) <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 7;
    cout << solution.smallestDivisor(nums, threshold) << endl;
}