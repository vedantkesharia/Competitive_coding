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

using namespace std;

class Solution {
    public:

        int ispossible(vector<int>& arr, int day, int m,int k){
            int n = arr.size();
            int count = 0;
            int noofbouquets = 0;
            for(int i = 0;i<n;i++){
                if(arr[i]<=day){
                    count++;
                }
                else{
                    noofbouquets += count/k;
                    count = 0;
                }
            }
            noofbouquets += count/k;
            return noofbouquets>=m;
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            long long val = m*1ll *k*1ll;
            int n = bloomDay.size();
            if(val>n){
                return -1;
            }
            int low = INT_MAX;
            int high = INT_MIN;
            for(int i = 0;i<n;i++){
                low = min(low,bloomDay[i]);
                high = max(high,bloomDay[i]);
            }
            while(low<=high){
                int mid = low + (high-low)/2;
                if(ispossible(bloomDay,mid,m,k)){
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
    vector<int> bloomDay = {7,7,7,7,13,11,12,7};
    int m = 3;
    int k = 2;
    cout<<solution.minDays(bloomDay,m,k)<<endl;
    return 0;
}