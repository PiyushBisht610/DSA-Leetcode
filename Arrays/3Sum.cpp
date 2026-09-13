/*
Problem: 3Sum
LeetCode: #15

Description:
Given an integer array, find all unique triplets
[a, b, c] such that a + b + c = 0.

Approach:
Sort the array first, then use one fixed element and
two pointers to find the remaining two elements.
Skip duplicate values to ensure that the result contains
only unique triplets.

Time Complexity: O(n^2)
Space Complexity: O(1) extra space
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find3Sum(vector<int> nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
            
        int j = i + 1, k = nums.size() - 1;

        while (j < k){
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0){
                j++;
            }else if (sum > 0){
                k--;
            }else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++, k--;
                
                while (j < k && nums[j] == nums[j-1]) j++;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < 3; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-43};

    find3Sum(nums);
    return 0;
}
