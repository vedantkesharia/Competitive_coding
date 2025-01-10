    // optimal
     #include <iostream>
     #include <vector>
     #include <list>
     #include <map>
     #include <functional>
     #include <algorithm>
     #include <iomanip>
     #include <limits>

    using namespace std;

    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int n = nums.size();
            int XOR1 = 0;
            for(int i = 0; i<n; i++){
                XOR1 = XOR1 ^ nums[i];
            }
            return XOR1;
        }
    };

    int main()
    {
        Solution solution;

        vector<int> nums = {1, 1, 3, 3, 4, 5, 5};

        cout << solution.singleNumber(nums);
    }


    //better using map
// #include <iostream>
// #include <vector>
// #include <list>
// #include <map>
// #include <functional>
// #include <algorithm>
// #include <iomanip>
// #include <limits>

// using namespace std;

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         map<int, int> mpp;

//         for (int num : nums)
//         {
//             mpp[num]++;
//         }
//         for (auto it : mpp)
//         {
//             if (it.second == 1)
//             {
//                 return it.first;
//             }
//         }
//     }
//     };

    // better using hash
    // #include <iostream>
    // #include <vector>
    // #include <list>
    // #include <map>
    // #include <functional>
    // #include <algorithm>
    // #include <iomanip>
    // #include <limits>

    // using namespace std;

    // class Solution {
    // public:
    //     int singleNumber(vector<int>& nums) {
    //         // Find the maximum value in nums
    //         int maxnumber = *max_element(nums.begin(), nums.end());

    //         // Create and initialize the hash vector
    //         vector<int> hash(maxnumber + 1, 0);

    //         // Count occurrences of each number
    //         for (int num : nums) {
    //             hash[num]++;
    //         }

    //         // Find and return the number that occurs exactly once
    //         for (int num : nums) {
    //             if (hash[num] == 1) {
    //                 return num;
    //             }
    //         }

    //         return -1; // Return -1 if no single number is found (optional)
    //     }
    // };
