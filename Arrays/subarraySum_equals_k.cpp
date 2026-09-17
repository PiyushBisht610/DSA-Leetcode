/*
Problem: Subarray Sum Equals K
LeetCode: #560

Description:
Given an integer array and an integer k, find the total
number of continuous subarrays whose sum equals k.

Approach:
Use Prefix Sum with a Hash Map.
For the current prefix sum, if (currentSum - k) has already
appeared, then a subarray with sum k exists between those
prefix sums.
Store the frequency of each prefix sum to count all valid
subarrays.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];

    for (int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    unordered_map<int, int> m; // (Sum, freq)
    int ans = 0;

    for (int i = 0; i < n; i++){
        if (prefixSum[i] == k) ans++;
            
        int val = prefixSum[i] - k;
        if (m.find(val) != m.end()) ans += m[val];
        if (m.find(prefixSum[i]) == m.end()) m[prefixSum[i]] = 0;
        m[prefixSum[i]]++;
    }

    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    int target = 3;

    cout << subarraySum(nums, target);
    return 0;
}
