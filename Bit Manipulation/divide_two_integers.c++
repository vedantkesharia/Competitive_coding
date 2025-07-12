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
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        
        int sign = true;
        if(dividend<0 && divisor>=0){
            sign = false;
        }
        
        if(dividend>=0 && divisor<0){
            sign = false;
        }
        
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long ans = 0;
        while(n>=d){
            int cnt = 0;
            while(n>(d<<cnt+1)){
                cnt++;
            }
            ans+=1L<<cnt;
            n -= d << cnt;
        }
        
        if(ans>=pow(2,31) && sign==true){
            return INT_MAX;
        }
        
        if(ans>=pow(2,31) && sign==false) {
            return INT_MIN;
        }
        
        return sign? ans:-ans;
        
    }
};








