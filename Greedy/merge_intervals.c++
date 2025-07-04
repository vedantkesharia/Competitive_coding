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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int i = 0;

        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

           
            while (i + 1 < n && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            res.push_back({start, end});
            i++;
        }

        return res;
    }
};

