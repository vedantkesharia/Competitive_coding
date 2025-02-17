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


int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;
    cout<<lowerbound(nums,target)<<endl;
    cout<<upperbound(nums,target)<<endl;
    return 0;
}