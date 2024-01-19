#include <bits/stdc++.h>
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
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i< prices.size();i++){
            if(prices[i-1]<prices[i]){
                profit+=prices[i]-prices[i-1];
            }

        }
        return profit;
    }
};

int main(){
    Solution solution;

    vector<int> prices = {7,1,5,3,6,4};
    cout<<"Stock Prices: ";
    for(int num : prices){
        cout<<num<<" ";
    }
    int profit = solution.maxProfit(prices);

    cout<<"Profit: "<<profit<<endl;
 
}