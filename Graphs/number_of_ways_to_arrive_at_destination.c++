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
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        vector<long long> dist(n, 1e18);  
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        int mod = 1e9 + 7;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long edgW = it.second;

                if (dis + edgW < dist[adjNode]) {
                    dist[adjNode] = dis + edgW;
                    pq.emplace(dist[adjNode], adjNode);
                    ways[adjNode] = ways[node];
                } else if (dis + edgW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1]%mod;
    }
};
