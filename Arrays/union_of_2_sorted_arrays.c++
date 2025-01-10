#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> union_of_2_sorted_arrays(vector<int> vec1, vector<int> vec2)
{
    int n = vec1.size();
    int m = vec2.size();
    vector<int> unionArray;
    int i=0, j=0;
    while (i < n && j < m)
    {
        if (vec1[i] <= vec2[j])
        {
            if (unionArray.size() == 0 || unionArray.back() != vec1[i])
            {
                unionArray.push_back(vec1[i]);
            }
            i++;
        }
        else
        {
            if (unionArray.size() == 0 || unionArray.back() != vec2[j])
            {
                unionArray.push_back(vec2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (unionArray.size() == 0 || unionArray.back() != vec1[i])
        {
            unionArray.push_back(vec1[i]);
        }
        i++;

    }
        while (j < m)
        {
            if (unionArray.size() == 0 || unionArray.back() != vec2[j])
            {
                unionArray.push_back(vec2[j]);
            }
            j++;
        }
    return unionArray;
}


int main(){

vector<int> vec1 = {1,1,2,3,4,5};
vector<int> vec2 = {2,3,4,4,5,6};

vector<int> unionArray = union_of_2_sorted_arrays(vec1, vec2);

for (int i = 0; i < unionArray.size(); i++){
    cout<<unionArray[i]<<" ";
}

}