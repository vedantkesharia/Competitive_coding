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
    int numSubarraysWithSumlessorequal(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        int n = nums.size();
        while(r<n){
            sum = sum+(nums[r]%2);
            while(sum>goal){
                sum = sum-(nums[l]%2);
                l++;
            }
            cnt = cnt+(r-l+1);
            r++;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int ans = numSubarraysWithSumlessorequal(nums, k) - numSubarraysWithSumlessorequal(nums,k-1);
        return ans;
    }
};
