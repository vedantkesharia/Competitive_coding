#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

class Solution {
public:
vector <int> leaders(vector <int> &arr){
    int n = arr.size();
    int maximum = INT_MIN;
    vector <int> result;
    for(int i =n-1; i>=0;i--){
        if(arr[i]>maximum){
            result.push_back(arr[i]);
        }
        maximum = max(maximum,arr[i]);
    }
    return result;
}
};

int main(){
    Solution solution;

    vector<int> arr = {10,22,12,3,0,6};

    vector <int> leaders = solution.leaders(arr);

    for(int leader : leaders){
        cout<<leader<<" ";
    }
    return 0;
}