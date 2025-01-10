
//optimal solution
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1 = 0;
        int XOR2 = 0;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            XOR1 = XOR1 ^ i;
        }
        for (int j = 0; j < n; j++){
            XOR2 = XOR2 ^ nums[j];
        }
        int missingnumber = XOR1 ^ XOR2;
        return missingnumber;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {0,2,3};

    cout << solution.missingNumber(nums);
}

