// Problem: Container with most Water
// LeetCode: #11
// Approach: Two pointer approach
// Time Complexity: O(n)
// Space Complexity: O(1) extra space

#include <iostream>
using namespace std;

int main(){
    int A[] = {1,8,6,2,5,4,8,3,7}; //Array of heights 
    int n = 9;
    
    int lt = 0, rt = n-1;
    int maxWtr = 0;
    while (lt < rt){
        int w = rt-lt;
        int h = min(A[lt], A[rt]);
        int area = h*w;
        maxWtr = max(maxWtr, area);
        if (A[lt] < A[rt]){
            lt++;
        }else if(A[lt] >= A[rt]){
            rt--;
        }
    }
  
    cout << maxWtr;
    return 0;
}
