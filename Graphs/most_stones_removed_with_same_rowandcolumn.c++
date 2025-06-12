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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it:stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int noderow = it[0];
            int nodecol = maxRow+it[1]+1;
            ds.unionBysize(noderow,nodecol);
            stoneNodes[noderow]=1;
            stoneNodes[nodecol]=1;
        }
        
        int countcomponents = 0;
        for(auto it:stoneNodes){
         if(ds.findUParent(it.first)==it.first){
             countcomponents++;
         }   
        }
        int n = stones.size();
        int ans = n-countcomponents;
        return ans;
    }
};