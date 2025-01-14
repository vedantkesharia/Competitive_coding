//better
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
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector <int> rows(n,0);
        vector <int> cols(m,0);

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(rows[i]==1 || cols[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


int main(){
    Solution solution;
    vector<vector<int>> matrix = {{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,0}};
    solution.setZeroes(matrix);
    for(int i = 0; i<matrix.size();i++){
        for(int j = 0; j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}