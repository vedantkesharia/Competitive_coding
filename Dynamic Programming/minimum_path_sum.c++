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
    int minPathSum(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[0][0]=grid[i][j];
                }
                else{
                    int up = grid[i][j];
                    if(i>0){
                        up += dp[i-1][j];
                    }
                    else{
                        up = 1e9;
                    }
                    int left = grid[i][j];
                    if(j>0){
                         left += dp[i][j-1];
                    }
                    else{
                        left = 1e9;
                    }
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};