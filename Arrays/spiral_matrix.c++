#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> result;
        int top = 0;
        int right = m-1;
        int bottom = n-1;
        int left = 0;
        while(left<=right && top<=bottom){
            for(int i = left; i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i = right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        return result;
    }
};

int main(){
    Solution solution;

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = solution.spiralOrder(matrix);
    for(int i = 0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
}