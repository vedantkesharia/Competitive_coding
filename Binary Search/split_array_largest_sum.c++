// same as allocate books and painters partition problem

// Algorithm Explanation:
// Initialize low as the maximum element in the array (minimum possible largest subarray sum) and high as the sum of all elements (maximum possible largest subarray sum).
// Perform binary search between low and high; at each step compute mid, where mid represents the guessed maximum allowed subarray sum.
// Traverse the array greedily and split it into contiguous subarrays such that the sum of elements in each subarray does not exceed mid.
// If the number of subarrays formed is greater than k, it means mid is too small, so increase low; otherwise, mid is a valid answer, update the result and decrease high.
// Repeat until binary search ends and return the minimum value of mid, which is the minimum possible largest subarray sum.



#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <cmath>
#include <numeric>
// #include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countSubarrays(int mid, vector<int>& nums){
        int subArrayCount = 1;
        long long currentCount = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]+currentCount<=mid){
                currentCount = nums[i] + currentCount;
            }
            else{
                subArrayCount++;
                currentCount = nums[i];
            }
        }
        return subArrayCount;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int low = maxi;
        int high = totalSum;
        int ans = high;
        while(low<=high){
            int mid = low + (high - low) / 2;
            int requiredSubarrays = countSubarrays(mid,nums);
            if(requiredSubarrays>k){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};