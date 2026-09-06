// Problem: Maximum Subarray
// LeetCode: #53
// Approach: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <climits>
using namespace std;

int MaxSubarraySum(int nums[], int n){
    int currSum = 0, maxSum = INT_MIN;
    
    for (int i = 0; i < n; i++){
        currSum += nums[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main(){
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n=9;
    
    cout << "Max SubArray Sum: " << MaxSubarraySum(nums, n);
    return 0;
}
