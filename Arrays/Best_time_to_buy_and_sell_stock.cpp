// Problem: Best time to buy and sell stock
// LeetCode: #121
// Approach: Treat each day as a selling day and track the minimum buying price seen so far
// Time Complexity: O(n)
// Space Complexity: O(1)


#include <iostream>
using namespace std;

int buy_sell_stock(int arr[], int n){
    int maxprofit = 0, bestbuy = arr[0];

    for (int i = 1; i < n; i++){
        if (arr[i] - bestbuy > maxprofit){
            maxprofit = max(maxprofit, arr[i] - bestbuy);
        }
        bestbuy = min(arr[i], bestbuy);
    }

    return maxprofit;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = 6;

    cout << "Max profit: " << buy_sell_stock(arr, n);
    return 0;
}
