// At every step:
// Binary search chooses a column (mid column)
// Scan that column to find its maximum element (linear search)
// Compare that element with left & right neighbors
// Move to another column (left or right)

// [[10,20,15],[21,30,14],[7,16,32]]
// mid = low+high/2 = 1 (so column with index 1 -> ie 20,30,16)
// now in this column linear search to find max element -> 30 at row 1
// now compare 30 with its left & right neighbors (21 & 14)
// since 30 > 21 & 30 > 14 -> we have found a peak
// if left neighbor was greater -> move to left half
// if right neighbor was greater -> move to right half


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
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int maxRow = 0;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int left = (mid-1>=0)?mat[maxRow][mid-1]:-1;
            int right = (mid+1<n)?mat[maxRow][mid+1]:-1;

            if(mat[maxRow][mid]>left && mat[maxRow][mid]>right){
                return {maxRow, mid};
            }
            else if(left>mat[maxRow][mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return {-1,-1};
        
    }
};