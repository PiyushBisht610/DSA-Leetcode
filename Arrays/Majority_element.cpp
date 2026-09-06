// Problem: Majority element
// LeetCode: #169
// Approach: Moore's voting algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int majority_element(int arr[], int n){
    int freq = 1, num = arr[0];

    for (int i = 1; i < n; i++){
        if (freq == 0){
            num = arr[i];
        }
        
        if (arr[i] == num){
            freq++;
        }else{
            freq--;
        }
    }

    return num;
}

int main(){
    int arr[] = {2,2,1,1,1,2,2};
    int n = 7;

    cout << "Majority element: " << majority_element(arr, n);
    return 0;
}
