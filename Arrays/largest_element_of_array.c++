#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <limits.h>
using namespace std;
int largest_element_of_array(std::vector<int> vec) {
    int largest = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > largest) {
            largest = vec[i];
        }
    }
    return largest;

}


int main(){
    vector<int> nums = {4,5,1,3,2};
    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Largest element in the array: " << largest_element_of_array(nums) << endl;

    return 0;
}