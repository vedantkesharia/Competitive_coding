#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> nge;
        stack<int> st;
        vector<int> ans;
        for(int i=m-1;i>=0;i--){
                    while(!st.empty() && st.top()<nums2[i]){
                            st.pop();
                        }
                        if(st.empty()){
                            nge[nums2[i]] = -1;
                            st.push(nums2[i]);
                        }
                        else{
                        nge[nums2[i]] = st.top();
                        st.push(nums2[i]);
                        }
            }
        for(auto it: nums1){
            ans.push_back(nge[it]);
        }
        return ans;
        
    }
};





