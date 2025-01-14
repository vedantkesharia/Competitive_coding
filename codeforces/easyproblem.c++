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

int main(){
    int t;
    
    cin>>t;
    vector<int> arr(t);
    for(int i = 0; i<t;i++){
        cin>>arr[i];
    }

    for(int i = 0;i<arr.size();i++){
        arr[i]=arr[i]-1;
    }

    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }



    
    return 0;
}