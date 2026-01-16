#include <stack>
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
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto it: mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};


// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int result = 0;

//         for (int bit = 0; bit < 32; bit++) {
//             int count = 0;
//             for (int num : nums) {
//                 if ((num >> bit) & 1) {
//                     count++;
//                 }
//             }
//             if (count % 3 != 0) {
//                 result |= (1 << bit);
//             }
//         }
//         return result;
//     }
// };
