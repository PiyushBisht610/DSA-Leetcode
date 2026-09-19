/*
Problem: Permutations
LeetCode: #46

Description:
Given an array of distinct integers, return all possible
permutations of the elements.

Approach:
Use Backtracking with swapping.
For each position, try placing every remaining element
at that position, recursively generate permutations for
the remaining positions, and then swap back to restore
the original array.

Time Complexity: O(n * n!)
Space Complexity: O(n) excluding the output
*/

#include <iostream>
#include <vector>
using namespace std;

void findPermut(vector<int>& nums, int idx, vector<vector<int>>& allPermut){
    if (idx == nums.size()){
        allPermut.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++){
        swap(nums[idx], nums[i]);
        findPermut(nums, idx+1, allPermut);
        swap(nums[i], nums[idx]);
    }
}
    
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> allPermut;
    findPermut(nums, 0, allPermut);
    
    for (vector<int> V : allPermut){
        cout << '[';
        for (int i = 0; i < V.size(); i++){
            cout << V[i] << ' ';
        }
        cout << ']' << endl;
    }

    return 0;
}
