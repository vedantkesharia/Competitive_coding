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

class StockSpanner {
stack<pair<int,int>> st;
int ind = -1;
public:
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind = ind+1;
        int ans = 0;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        
        if(st.empty()){
            ans = ind-(-1);
        }
        else{
            ans = ind-st.top().second;
        }
        
        st.push({price,ind});
        return ans;
    }
};













