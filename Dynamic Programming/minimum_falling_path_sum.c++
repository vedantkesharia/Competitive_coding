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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int straight = matrix[i][j]+dp[i-1][j];
                int leftdiagonal = matrix[i][j];
                if(j-1>=0){
                    leftdiagonal += dp[i-1][j-1];
                }
                else{
                    leftdiagonal += 1e9;
                }
                int rightdiagonal = matrix[i][j];
                if(j+1<n){
                    rightdiagonal += dp[i-1][j+1];
                }
                else{
                    rightdiagonal += 1e9;
                }
                dp[i][j] = min(straight,min(leftdiagonal,rightdiagonal));
            }
        }
        
                int mini = 1e9;
                for(int j=0;j<n;j++){
                    mini = min(mini,dp[n-1][j]);
                }
                return mini;
    }
};