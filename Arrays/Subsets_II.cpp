/*
Problem: Subsets II
LeetCode: #90

Description:
Given an integer array that may contain duplicate elements,
return all possible subsets without including duplicate subsets.

Approach:
Use Backtracking.
Sort the array first so that duplicate elements are adjacent.
During recursion, skip duplicate elements at the same recursion
level to avoid generating duplicate subsets.

Time Complexity: O(n * 2^n)
Space Complexity: O(n) excluding the output
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void allSubset(vector<int>& nums, vector<vector<int>>& powerSet, vector<int>& ans, int i){
    if (i == nums.size()){
        powerSet.push_back(ans);
        return;
    }
    //include
    ans.push_back(nums[i]);
    allSubset(nums, powerSet, ans, i+1);
    ans.pop_back(); //backtracking

    int idx = i + 1; //skipping duplicates
    while (idx < nums.size() && nums[idx] == nums[idx - 1]){
        idx++;
    } 
    //exclude
    allSubset(nums, powerSet, ans, idx);
}

int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> powerSet;
    vector<int> ans;
    sort(nums.begin(), nums.end());
        
    allSubset(nums, powerSet, ans, 0);
    
    for (vector<int> subset : powerSet){
        cout << '[';
        for (int i = 0; i < subset.size(); i++){
            cout << subset[i] << ',';
        }

        cout << ']' << endl;
    }
}
