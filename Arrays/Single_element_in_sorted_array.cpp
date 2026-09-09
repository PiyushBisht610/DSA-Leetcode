/*
Problem: Single Element in a Sorted Array
LeetCode: #540

Description:
Given a sorted array where every element appears exactly twice
except for one element, find the element that appears only once.

Approach:
Binary Search using index parity.
Before the single element, pairs start at even indices.
After the single element, this pattern is shifted.
Use this property to eliminate half of the search space.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int search(int arr[], int n){
    int st = 0, end = n-1;

    while (st <= end){
        int mid = st + (end - st)/2;

        if (mid == 0 && arr[0] != arr[1]) return arr[0];
        if (mid == n-1 && arr[n-2] != arr[n-1]) return arr[n-1];

        if (arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]){
            return mid;
        }

        if (mid % 2 == 0){
            if (arr[mid-1] == arr[mid]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if (arr[mid-1] == arr[mid]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    int arr[] = {1,1,2,3,3,4,4,8,8};
    int n = 9;

    int idx = search(arr, n);
    cout << "Single element found at index: " << idx;
    return 0;
}
