#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>

using namespace std;


class Solution {
    public:
    
    int lowerbound(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
            ans = mid;
            high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    int upperbound(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
            ans = mid;
            high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int> &nums, int target){
        int lb = lowerbound(nums,target);
        if(lb == nums.size()||nums[lb]!=target){
            return {-1,-1};
        }
        int ub = upperbound(nums,target)-1;
        return {lb,ub};
    }
        
    };

int main(){
    Solution solution;
    vector<int> nums = {5,7,7,8,8,8,10};
    int target = 8;
    vector<int> p = solution.searchRange(nums,target);
    cout<<p[0]<<" "<<p[1]<<endl;
}