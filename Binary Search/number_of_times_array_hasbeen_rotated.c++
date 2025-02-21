#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findPivot(vector<int> &nums){
    int low = 0;
    int high = nums.size() - 1;
    int minimum = INT_MAX;
    int index = -1;  
    while (low <= high) {
        int mid = low + (high - low) / 2;


        if (nums[low] <= nums[high]) {
            if (nums[low] < minimum) {
                return low;
            }
        }

        if (nums[mid] < minimum) {
            minimum = nums[mid];
            index = mid;
        }


        if (nums[mid] >= nums[low]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return index;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Pivot Index: " << findPivot(nums) << endl;
    return 0;
}
