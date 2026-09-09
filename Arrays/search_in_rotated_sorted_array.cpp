/*
Problem: Search in Rotated Sorted Array
LeetCode: #33

Description:
Given a sorted array that has been rotated at an unknown
pivot, search for a target value and return its index.
Return -1 if the target is not present.

Approach:
Modified Binary Search.
At each step, one half of the array is guaranteed to be sorted.
Determine which half is sorted, check whether the target lies
within that range, and eliminate the other half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int search(int arr[], int target, int n){
    int st = 0, end = n-1;

    while (st <= end){
        int mid = st + (end - st)/2;

        if (arr[mid] == target){
            return mid;
        }

        if (arr[st] <= arr[mid]){ //left sorted
            if (arr[st] <= target && target <= arr[mid]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{ // right sorted
            if (arr[mid] <= target && target <= arr[end]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7;
    int target = 1;

    int idx = search(arr, target, n);
    cout << "target found at index: " << idx;
    return 0;
}
