#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

int removeDuplicates(vector<int> &arr, int n){
    int i =0;
    for(int j=1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return arr[i];
    // return i+1; // if you want number of sorted elements in the array
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = nums.size();
    cout << "Original vector: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int newSize = removeDuplicates(nums,n);

    cout << "Vector after removing duplicates: ";
    for (int i = 0; i < newSize; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}


// class Solution
// {
// public:
//     int removeDuplicates(vector<int> &nums)
//     {
//         vector<int>::iterator iter = nums.begin();
//         while (iter != nums.end())
//         {
//             if (iter != nums.begin() && *iter == *(iter - 1))
//             {
//                 iter = nums.erase(iter);
//             }
//             else
//             {
//                 ++iter;
//             }
//         }
//         return nums.size();
//     }
// };

// int main()
// {
//     Solution solution;

//     vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

//     cout << "Original vector: ";
//     for (int num : nums)
//     {
//         cout << num << " ";
//     }
//     cout << endl;

//     int newSize = solution.removeDuplicates(nums);

//     cout << "Vector after removing duplicates: ";
//     for (int i = 0; i < newSize; ++i)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }