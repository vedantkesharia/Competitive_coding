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
#include <set>

using namespace std;

class DisjointSet{
    public:
    vector<int> parent, rank, size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionBysize(int u, int v){
        int uParent = findUParent(u);
        int vParent = findUParent(v);
        if(uParent==vParent){
            return;
        }
        if(size[uParent]<size[vParent]){
            parent[uParent]=vParent;
            size[vParent]+=size[uParent];
        }
        else{
            parent[vParent]=uParent;
            size[uParent]+=size[vParent];
        }
    }
     void unionByrank(int u, int v){
        int uParent = findUParent(u);
        int vParent = findUParent(v);
        if(uParent==vParent){
            return;
        }
        if(rank[uParent]<rank[vParent]){
            parent[uParent]=vParent;
        }
        else if(rank[uParent]>rank[vParent]){
            parent[vParent]=uParent;
        }
        else{
            parent[vParent]=uParent;
            rank[uParent]++;
        }
    }
};


class Solution {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBysize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
      
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUParent(cellNo)]);
        }
        return mx;
    }
};