//optimal approach(Dutch National Flag Algorithm)
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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }

        }
    }
};


int main(){
    Solution solution;

    vector<int> nums = {2,0,2,1,1,0};

    solution.sortColors(nums);

    for(int num : nums){
        cout<<num<<" ";
    }
}

//better approach
// #include <iostream>
// #include <vector>
// #include <list>
// #include <map>
// #include <functional>
// #include <algorithm>
// #include <iomanip>
// #include <limits>

// using namespace std;

// class Solution {
// public :
//     void sortColors(vector<int>& nums) {
//         int cnt0 = 0, cnt1 = 0, cnt2 = 0;
//         for(int i = 0;i<nums.size();i++){
//             if(nums[i]==0){
//                 cnt0++;
//             }
//             else if (nums[i]==1){
//                 cnt1++;
//             }
//             else{
//                 cnt2++;
//             }
//         }

//         for(int i = 0;i<cnt0;i++){
//             nums[i] = 0;
//         }
//         for(int i = cnt0;i<cnt0+cnt1;i++){
//             nums[i] = 1;
//         }
//         for(int i = cnt0+cnt1;i<nums.size();i++){
//             nums[i] = 2;
//         }
//     }
// };

// int main(){
//     Solution solution;

//     vector<int> nums = {2,0,2,1,1,0};

//     solution.sortColors(nums);

//     for(int num : nums){
//         cout<<num<<" ";
//     }
// }