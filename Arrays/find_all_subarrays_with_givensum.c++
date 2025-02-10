#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> mpp;
            mpp[0] = 1;
            int presum = 0, count = 0;
            for(int i = 0; i<nums.size();i++){
                presum+=nums[i];
                int remove = presum - k;
                count+=mpp[remove];
                mpp[presum]++;
            }
            return count;
        }
    };

int main(){
    Solution solution;

    vector<int> nums = {1,1,1};
    int k = 2;

    cout<<solution.subarraySum(nums,k);
    return 0;
}