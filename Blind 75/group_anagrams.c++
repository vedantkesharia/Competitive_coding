#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

           
            string key;
            for (int freq : count) {
                key += to_string(freq) + '#'; 
            }

            mpp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : mpp) {
            result.push_back(pair.second);
        }

        return result;
    }
};










