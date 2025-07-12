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
    double myPow(double x, int n) {
        double ans=1;
        long long m = abs((long long)n);
        while(m>0){
            if(m%2==1){
                ans=ans*x;
                m--;
            }
            else{
                m=m/2;
                x=x*x;
            }
           
        }
         if(n<0){
                ans=1.0/ans;
            }
        
        return ans;
    }
};






