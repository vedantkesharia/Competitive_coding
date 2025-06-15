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
    void printSubsets(int ind, vector<int>&ds, vector<int> &nums, int n,vector<vector<int>> &ans){
        if(ind==n){
           ans.push_back(ds);
           return;
        }
        ds.push_back(nums[ind]);
        printSubsets(ind+1,ds,nums,n,ans);
        ds.pop_back();
        printSubsets(ind+1,ds,nums,n,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        printSubsets(0,ds,nums,n,ans);
        return ans;
    }
};