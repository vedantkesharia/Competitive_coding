#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <cmath>

using namespace std;
class Solution
{
public:
    int findmax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long totalHours(int mid, vector<int> &piles)
    {
        long long totalhours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            totalhours += (piles[i] + mid - 1) / mid;  
        }
        return totalhours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = findmax(piles);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long totalhours = totalHours(mid, piles);

            if (totalhours <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    Solution solution;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<solution.minEatingSpeed(piles,h)<<endl;
}