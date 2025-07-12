#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0 ) return false;
        return ( (n & (n-1)) == 0 );
    }
};