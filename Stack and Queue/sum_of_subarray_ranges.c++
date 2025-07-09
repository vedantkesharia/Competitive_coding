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
    vector<int> findNGE(vector<int>& arr){
        int n = arr.size();
        vector<int> nge(n, n);  
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGEE(vector<int>& arr){
        int n = arr.size();
        vector<int> pgee(n, -1);  
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pgee[i] = st.top();
            }
            st.push(i);
        }
        return pgee;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);
        long long total = 0;

        for(int i = 0; i < n; i++){
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            total = (total + arr[i] * left * right);
        }

        return total;
    }
    
public:
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

public:
    vector<int> findPSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> psee(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
            }
            else{
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        long long total = 0;
        long long left = 0;
        long long right = 0;
        
        for(int i=0;i<n;i++){
            left = i - psee[i];
            right = nse[i] - i;
            total = (total+(left*right*1ll*arr[i]));
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        return ans;
    }
};






