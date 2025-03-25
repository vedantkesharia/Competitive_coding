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
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int countStudents(vector<int> &students, int pages)
    {
        int n = students.size();
        long long pagesStudents = 0;
        int currentstudent = 1;
        for (int i = 0; i < n; i++)
        {
            if (pagesStudents + students[i] <= pages)
            {
                pagesStudents += students[i];
            }
            else
            {
                currentstudent++;
                pagesStudents = students[i];
            }
        }
        return currentstudent;
    }

    // n -> number of books
    // m -> number of students
    int findPages(int n, int m, vector<int> &arr)
    {
        if (n < m)
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid);
            if(students>m){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int n = 5;
    cout << solution.findPages(n, m, arr) << endl;
}