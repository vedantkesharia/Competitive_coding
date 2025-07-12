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
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt=0;
        while(ans>=1){
            if(ans%2==1){
                cnt=cnt+1;
            }
            ans=ans/2;
        }
        return cnt;
    }
};








