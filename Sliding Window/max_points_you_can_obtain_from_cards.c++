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
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;
        for(int i=0;i<k;i++){
            leftSum = leftSum+cardPoints[i];
            maxSum = max(leftSum,maxSum);
        }
        
        int rightindex = n-1;
        for(int i=k-1;i>=0;i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightindex];
            rightindex--;
            maxSum = max(maxSum,leftSum+rightSum);
        }
        return maxSum;
    }
};



