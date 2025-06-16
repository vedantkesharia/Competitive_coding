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
    void findSubsets(int ind, vector<vector<int>>&ans, vector<int> &ds, vector<int>&nums){
        ans.push_back(ds);
        for(int i = ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            findSubsets(i+1,ans,ds,nums);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,ans,ds,nums);
        return ans;
    }
};