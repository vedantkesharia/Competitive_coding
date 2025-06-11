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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtraEdges = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                cntExtraEdges++;
            }
            else{
                ds.unionBysize(u,v);
            }
        }
        
        int countcomponents=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                countcomponents++;
            }
        }
        
        int ans = countcomponents-1;
        if(cntExtraEdges>=ans){
            return ans;
        }
        return -1;
        
    }
};