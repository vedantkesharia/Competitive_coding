#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
	    int mini = prices[0];
	
	for(int i=1;i<prices.size();i++){
        int curProfit = prices[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,prices[i]);
        }
	return maxProfit;
    }
};