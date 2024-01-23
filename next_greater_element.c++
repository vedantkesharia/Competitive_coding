//IMPORTANT



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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // Initializing a vector 'ans' of size n with all elements set to -1
        
        int n = nums2.size();
        vector<int> ans(n, -1);

        // Initializing a stack to store indices of elements in nums2
        stack<int> st;

        // Finding the next greater element of each element in nums2
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop elements from the stack while the current element is greater than the top of the stack
            while (!st.empty() && nums2[st.top()] < nums2[i])
                st.pop();

            // If the stack is not empty, update ans[i] with the top element of the stack
            if (st.size() > 0)
                ans[i] = nums2[st.top()];

            // Push the current index onto the stack
            st.push(i);
        }

        // Storing each next greater element into the map
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums2.size(); i++)
            mpp[nums2[i]] = ans[i];

        // Creating the final result vector 'final' for nums1
        vector<int> final(nums1.size(), -1);

        // Updating final[i] with the next greater element if it exists
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mpp.find(nums1[i]) != mpp.end())
            {
                final[i] = mpp[nums1[i]];
            }
        }

        // Returning the final result
        return final;
    }
};

int
main()
{
    Solution solution;

    // Example input
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Calling the nextGreaterElement function
    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    // Displaying the result
    cout << "Result: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
