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
    vector<vector<string>> result;

    
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }


    void backtrack(string &s, int start, vector<string> &current) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current);
                current.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(s, 0, current);
        return result;
    }
};
