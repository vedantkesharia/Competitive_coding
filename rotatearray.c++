#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

// reverse(nums.begin(), nums.end());
// This line reverses the entire vector nums. It swaps the elements in a way that the first element becomes the last, the second becomes the second-to-last, and so on, effectively reversing the order of elements in the vector.

// reverse(nums.begin(), nums.begin() + k);
// This line reverses the first k elements of the vector nums. It starts at the beginning of the vector (nums.begin()) and goes up to, but not including, the element at position k (nums.begin() + k). This means it reverses the order of the first k elements in the vector.

// reverse(nums.begin() + k, nums.end());
// This line reverses the remaining elements in the vector nums after the first k elements. It starts at the element at position k (nums.begin() + k) and goes up to the end of the vector (nums.end()). This reverses the order of the elements starting from position k until the end of the vector.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;  
        reverse(nums.begin(), nums.end());


        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.rotate(nums, k);

    cout << "Vector after rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



