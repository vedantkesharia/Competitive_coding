#include <bits/stdc++.h>
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
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto num : nums){
            if(i == 0 || i == 1 || nums[i-2]!=num ){
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {1, 1, 1, 2, 2, 3, 3};
    cout<<"Original vector: ";
    for(int num : nums){
        cout<<num<<" ";
    }
    // solution.removeDuplicates(nums);
    int newSize = solution.removeDuplicates(nums);
    nums.resize(newSize);

    cout<<"New vector: ";
        for(int num : nums){
        cout<<num<<" ";
    }
}