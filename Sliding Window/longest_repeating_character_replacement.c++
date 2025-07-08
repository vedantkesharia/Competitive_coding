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
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxf = 0;
        int n = s.size();
        vector<int> hashvector(26,0);
        while(r<n){
            hashvector[s[r]-'A']++;
            maxf = max(maxf,hashvector[s[r]-'A']);
            if(r-l+1-maxf>k){
                hashvector[s[l]-'A']--;
                maxf = 0;
                l++;
            }
            
            if(r-l+1-maxf<=k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};






