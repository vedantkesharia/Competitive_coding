#include <bits/stdc++.h>
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
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i = s.length()-1; i>=0;i--){
            if(s[i]!=' '){
                count+=1;
            }
            else if (count > 0){
                break;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    string s1 = "Hello World";
    cout << "Length of last word in \"" << s1 << "\": " << solution.lengthOfLastWord(s1) << endl;

    string s2 = "   Hello   ";
    cout << "Length of last word in \"" << s2 << "\": " << solution.lengthOfLastWord(s2) << endl;

    string s3 = "a";
    cout << "Length of last word in \"" << s3 << "\": " << solution.lengthOfLastWord(s3) << endl;

    return 0;
}