#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>

using namespace std; 

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxleft = 0;
        int maxright = 0;
        int total = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(maxleft>height[l]){
                    total+=maxleft-height[l];
                }
                else{
                    maxleft = height[l];
                }
                l++;
            }
            else{
                if(maxright>height[r]){
                    total+= maxright-height[r];
                }
                else{
                    maxright = height[r];
                }
                r--;
            }
        }
        return total;
    }
};





