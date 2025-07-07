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
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3,-1);
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt = cnt + (1 + min(min(lastseen[0], lastseen[1]), lastseen[2]));
            }
        }
        return cnt;
    }
};










