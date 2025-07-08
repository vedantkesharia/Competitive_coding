#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>


using namespace std; 

class Solution {
public:
    int subarraysWithlesserEqualKDistinct(vector<int>&nums, int k){
        int l=0;
        int r=0;
        int n = nums.size();
        int cnt=0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = subarraysWithlesserEqualKDistinct(nums,k)-subarraysWithlesserEqualKDistinct(nums,k-1);
        return ans;
    }
};