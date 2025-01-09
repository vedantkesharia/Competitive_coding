#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <limits.h>
using namespace std;

int second_largest_element(int arr[], int n){
    int largest = arr[0];
    int second_largest = INT_MIN;
    for(int i = 0; i<n;i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>second_largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main() {
    int arr[] = {1,2,4,7,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Second largest element in the array: " << second_largest_element(arr,n) << endl;

    return 0;
}