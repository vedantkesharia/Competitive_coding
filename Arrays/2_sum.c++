// //better approach (optimal approach if there are negative numbers in the array)
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
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int> mpp;
//         for (int i = 0; i < nums.size(); i++) {
//         int complement = target - nums[i];
//         if (mpp.find(complement) != mpp.end()) {
//             return {mpp[complement], i};
//         }
//         mpp[nums[i]] = i;
//     }
//     return {-1, -1}; 
//     }
// };

// int main(){
//     Solution solution;
//     vector<int> nums = {11, 15, 2, 7};
//     int target = 9;
//     vector<int> result = solution.twoSum(nums, target);
//     cout << result[0] << " " << result[1] << endl;
//     return 0;
// }



//brute force(my logic below, different brute force logic in book)
// #include <iostream>
// #include <vector>
// #include <list>
// #include <map>
// #include <functional>
// #include <algorithm>
// #include <iomanip>
// #include <limits>

// using namespace std;

// pair <int,int> two_sum(vector<int> &nums, int target){
//     for(int i = 0;i<nums.size();i++){
//         int sum = 0;
//         for(int j = i; j<nums.size();j++){
//             sum+=nums[j];
//             if(sum==target){
//                 return {i,j};
//             }
//         }
        
//     }
//     return {-1,-1};
// }

// int main(){
//     vector<int> nums = {11, 15, 2, 7};
//     int target = 9;
//     pair<int, int>result = two_sum(nums, target);
//      cout << result.first << " " << result.second << endl;
//     return 0;
// }