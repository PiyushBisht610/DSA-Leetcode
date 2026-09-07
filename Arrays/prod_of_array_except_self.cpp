// Problem: Product of array except self
// LeetCode: #238
// Approach: Use prefix and suffix products to calculate the product of all elements 
// except the current element
// Time Complexity: O(n)
// Space Complexity: O(1) extra space

#include <iostream>
#include <vector>
using namespace std;

void prod_of_array(vector<int> V){
    int n = V.size();
    for (int i = 0; i < n; i++){ 
        cout<< V[i] << " ";  //original vector
    }

    vector<int> ans(4,1);

    //prefix
    for (int i = 1; i < n; i++){
        ans[i] = ans[i-1] * V[i-1]; 
    }

    //suffix
    int suffix = 1;
    for (int i = n-2; i >= 0; i--){
        suffix *= V[i+1];
        ans[i] = ans[i] * suffix;
    }

    cout<< endl;
    for (int val: ans){
        cout<< val << " ";  //answer vector
    }
}

int main(){
    vector <int> V= {1,2,3,4};
    
    prod_of_array(V);
    return 0;
}
