#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int findDays(vector<int>& weights, int capacity) {
            int days = 1;
            int load = 0;
            int n = weights.size();
            for(int i = 0;i<n;i++){
                if(load + weights[i]>capacity){
                    days++;
                    load = weights[i];
                }
                else{
                    load+=weights[i];
                }
            }
            return days;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int low = *max_element(weights.begin(),weights.end());
            int high = accumulate(weights.begin(),weights.end(),0);
            while(low<=high){
                int mid = low + (high-low)/2;
                if(findDays(weights,mid)<=days){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            return low;
        }
    };


    int main(){
        Solution solution;
        vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
        int days = 5;
        cout<<solution.shipWithinDays(weights,days);
    }