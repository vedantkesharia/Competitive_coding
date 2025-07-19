#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int n : nums) {
            if (numSet.find(n) != numSet.end()) {
                return true;
            }
            numSet.insert(n);
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