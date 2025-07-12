#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR1 = 0;
        for(int i = 0; i<n; i++){
            XOR1 = XOR1 ^ nums[i];
        }
        return XOR1;
    }
};