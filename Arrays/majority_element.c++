//Optimal (Moore's Voting Algorithm) - O(n) or O(2n)(if we need ti check whether majority element exists) time complexity and O(1) space complexity
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
    int majorityElement(vector<int>& nums) {
        int element;
        int count = 0;
        for(int i = 0; i<nums.size();i++){
            if(count==0){
                count=1;
                element = nums[i];
            }
            else if(element==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }

        int count1 = 0;
        for(int i = 0;i<nums.size();i++){
            if(element==nums[i]){
                count1++;
            }
        }

        if(count1>(nums.size()/2)){
            return element;
        }
        return -1;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};

    cout<<solution.majorityElement(nums);
}
