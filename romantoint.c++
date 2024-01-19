#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i < s.length() - 1 && romanValues[s[i]] < romanValues[s[i + 1]])
            {
                result -= romanValues[s[i]];
            }
            else
            {
                result += romanValues[s[i]];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    cout << solution.romanToInt("III") << endl;
    cout << solution.romanToInt("LVIII") << endl;
    cout << solution.romanToInt("MCMXCIV") << endl;

    return 0;
}
