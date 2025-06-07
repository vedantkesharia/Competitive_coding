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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue <pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited (n,vector<int>(m,0));
        
        if(grid[0][0]==1){
            return -1;
        }
        
        if(n==1 && m==1 && grid[0][0]==0){
            return 1;
        }
        
       pair<int, int> traveldirections[] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},{1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        visited[0][0]=1;
        q.push({0,{0,0}});
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int distance = q.front().first;
            q.pop();
            
            
            for(int i=0;i<8;i++){
                int newr = r+traveldirections[i].first;
                int newc = c+traveldirections[i].second;
                
                if(newr<n && newr>=0 && newc<m && newc>=0 && grid[newr][newc]==0 && visited[newr][newc]==0){
                    visited[newr][newc]=1;
                    q.push({distance+1,{newr,newc}});
                    
                }
            }
                    if(r==n-1 && c==m-1){
                        return distance+1;
                    }
        }
        return -1;
    }
};



