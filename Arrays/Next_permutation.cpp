/*
Problem: Next Permutation
LeetCode: #31

Description:
Given an array of integers, rearrange the elements into the
next lexicographically greater permutation.
If no greater permutation exists, rearrange the array into
the lowest possible order.

Approach:
1. Find the first decreasing element from the right.
2. Find the smallest element greater than it from the right.
3. Swap these two elements.
4. Reverse the remaining suffix to get the smallest possible
   permutation after the swap.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void reverse(int arr[], int i, int j){
    while (i < j){
        swap(arr[i], arr[j]);
        i++, j--;
    }
}

void nextPermut(int arr[], int n){
    int piv = -1;
    
    for (int i = n-2; i >= 0; i--){
        if (arr[i] < arr[i+1]){
            piv = i;
            break;
        }
    }

    if (piv == -1){
        reverse(arr, 0, n-1);
        for (int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
        return;
    }

    for (int i = n-1; i >= 0; i--){
        if (arr[piv] < arr[i]){
            swap(arr[piv], arr[i]);
            break;
        }
    }

    reverse(arr, piv+1, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
}

int main(){
    int arr[] = {1,2,3};
    int n = 3;

    nextPermut(arr, n);
    return 0;
}
