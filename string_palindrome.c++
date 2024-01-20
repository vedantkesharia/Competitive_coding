#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;


    string s1 = "A man, a plan, a canal, Panama";
    cout << "Is \"" << s1 << "\" a palindrome? " << (solution.isPalindrome(s1) ? "Yes" : "No") << endl;

    string s2 = "race a car";
    cout << "Is \"" << s2 << "\" a palindrome? " << (solution.isPalindrome(s2) ? "Yes" : "No") << endl;

    return 0;
}