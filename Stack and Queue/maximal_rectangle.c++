#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>

using namespace std; 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
          int height = heights[st.top()];
          st.pop();
          int width;
          if (st.empty()){
            width = i;
          }
        else{
            width = i - st.top() - 1;
        }
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        int maxArea = 0;
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                    sum+=1;
                }
                else{
                    sum=0;
                }
                prefixSum[i][j] = sum;
            }
        }
        
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
        }
        return maxArea;
    }
};






