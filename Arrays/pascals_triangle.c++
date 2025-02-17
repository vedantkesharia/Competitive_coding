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

        vector<int> generateRow(int row) {
            long long ans = 1;
            vector<int> ansrow;
            ansrow.push_back(1);
            for(int col = 1; col<row;col++){
                ans = ans*(row-col)/col;
                ansrow.push_back(ans);
            }
            return ansrow;
        }
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            for(int i = 1; i<=numRows;i++){
                ans.push_back(generateRow(i));
            }
            return ans;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> ans = solution.generate(5);
    for(int i = 0; i<ans.size();i++){
        for(int j = 0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
