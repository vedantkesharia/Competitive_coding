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
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        
        if(s.length()!=t.length()){
            return false;
        }
        
        for(auto it: s){
           mpp[it] = mpp[it]+1;
        }
        
        for(auto it:t){
            if(mpp.find(it)==mpp.end() || mpp[it]==0){
                return false;
            }
            else{
                mpp[it]--;
            }
        }
        return true;
    }
};









