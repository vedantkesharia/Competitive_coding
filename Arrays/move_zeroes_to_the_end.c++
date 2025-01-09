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
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        if (j == -1) return;

        for(int i = j+1; i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

int main(){
    Solution solution;

    vector<int> nums = {0, 1, 0, 3, 12};
    // vector<int> nums = {1,2,3};

    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.moveZeroes(nums);

    cout << "Vector after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}