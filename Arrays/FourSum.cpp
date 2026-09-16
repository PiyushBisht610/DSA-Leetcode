/*
Problem: 4Sum
LeetCode: #18

Description:
Given an integer array and a target value, find all unique
quadruplets [a, b, c, d] such that:
a + b + c + d = target.

Approach:
Sort the array, fix the first two elements using nested loops,
and use two pointers to find the remaining two elements.
Skip duplicate values at each level to avoid duplicate quadruplets.

Time Complexity: O(n^3)
Space Complexity: O(1) extra space
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fourSum(vector<int> nums, int target){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++){
        if (i > 0 && nums[i - 1] == nums[i])
            continue;

        for (int j = i + 1; j < n;){
            int k = j + 1, l = n - 1;

            while (k < l){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];

                if (sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++, l--;

                    while (k < l && nums[k - 1] == nums[k]){
                        k++;
                    }
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }

            j++;
            while (j < n && nums[j - 1] == nums[j])
                j++;
        }
    }

    for (vector<int> val : ans){
        for (int j = 0; j < val.size(); j++){
            cout << val[j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    fourSum(nums, target);
    return 0;
}
