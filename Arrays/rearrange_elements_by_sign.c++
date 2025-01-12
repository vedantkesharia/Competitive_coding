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
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0;
        int negIndex = 1;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
            else{
                ans[negIndex]=nums[i];
                negIndex+=2;
            }
        }
            return ans;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {1, 2, -3, -4, -1, 4};

    vector<int> result = solution.rearrangeArray(nums);

    for(int num : result){
        cout<<num<<" ";
    }

}