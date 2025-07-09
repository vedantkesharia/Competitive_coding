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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int total = 0;
        int mod = (int)(1e9+7);
        int left = 0;
        int right = 0;
        
        for(int i=0;i<n;i++){
            left = i - psee[i];
            right = nse[i] - i;
            total = (total+(left*right*1ll*arr[i])%mod)%mod;
        }
        return total;
    }
};






