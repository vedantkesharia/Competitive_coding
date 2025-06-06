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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> graphrev(v);            
        vector<int> indegree(v, 0);                

        
        for (int i = 0; i < v; i++) {
            for (auto it : graph[i]) {
                graphrev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);                          
            }
        }

        vector<int> safenodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safenodes.push_back(node);              
            for (auto it : graphrev[node]) {  
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};
