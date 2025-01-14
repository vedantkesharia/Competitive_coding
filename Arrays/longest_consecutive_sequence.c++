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
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int longest = 1;
        unordered_set<int> st;

        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1)==st.end()){
            int count = 1;
            int x = it;
            
            while(st.find(x+1)!=st.end()){
                x++;
                count++;
            }
            longest = max(longest,count);
            }

        }
        return longest;

    }
};

int main(){
    Solution solution;

    vector<int> nums = {100,4,200,1,3,2};

    cout<<solution.longestConsecutive(nums);
    return 0;
}