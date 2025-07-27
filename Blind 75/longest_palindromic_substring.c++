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
    string longestPalindrome(string str) {
        if (str.length() <= 1)
            return str;

        string LPS = "";

        for (int i = 0; i < str.length(); i++) {
            
            int low = i, high = i;
            while (low >= 0 && high < str.length() && str[low] == str[high]) {
                if (high - low + 1 > LPS.length()) {
                    LPS = str.substr(low, high - low + 1);
                }
                low--;
                high++;
            }

            
            low = i;
            high = i + 1;
            while (low >= 0 && high < str.length() && str[low] == str[high]) {
                if (high - low + 1 > LPS.length()) {
                    LPS = str.substr(low, high - low + 1);
                }
                low--;
                high++;
            }
        }

        return LPS;
    }
};
