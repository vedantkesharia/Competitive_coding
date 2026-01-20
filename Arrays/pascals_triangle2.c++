#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> ansrow;
            ansrow.push_back(1);
            for(int col = 1; col<=rowIndex;col++){
                ans = ans*(rowIndex-col+1)/col;
                ansrow.push_back(ans);
            }
        return ansrow;
    }
};