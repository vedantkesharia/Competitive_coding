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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(), accounts.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBysize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};