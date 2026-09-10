/*
Problem: Sort Colors
LeetCode: #75

Description:
Given an array containing only 0s, 1s, and 2s, sort the array
in-place so that elements of the same color are adjacent.

Approach:
Use the Dutch National Flag algorithm with three pointers:
low, mid, and high.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <stack>
using namespace std;

void sortColours(int arr[], int n){
    int low = 0, mid = 0, high = n-1;

    while (mid <= high){
        if (arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++, mid++;
        }else if (arr[mid] == 1){
            mid++;
        }else if (arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
}

int main(){
    int arr[] = {2,0,2,1,1,0,0};
    int n = 7;

    sortColours(arr, n);
    return 0;
}
