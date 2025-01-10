#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR1 = 0;
        for(int i = 0; i<n; i++){
            XOR1 = XOR1 ^ nums[i];
        }
        return XOR1;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {1,1,3,3,4,5,5};

    cout << solution.singleNumber(nums);
}