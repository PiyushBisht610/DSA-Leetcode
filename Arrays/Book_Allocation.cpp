/*
Problem: Allocate Books / Book Allocation Problem

Description:
Given an array representing the number of pages in each book
and a number of students, allocate the books among the students
such that:
1. Each student gets at least one book.
2. Each student receives a contiguous set of books.
3. The maximum number of pages assigned to any student is minimized.

Approach:
Binary Search on Answer.
The answer lies between the maximum pages in a single book
and the total number of pages.
For each possible maximum page limit, use a greedy approach
to check whether the books can be allocated to all students.

Time Complexity: O(n log(sum of pages))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages){
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] > maxAllowedPages) return false;
        
        if (pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }else{
            students++;
            pages = arr[i];
        }
    }
    if (students > m) return false;
    else return true;
}

int allocateBooks(vector<int> &arr, int n, int m){
    if (m > n){
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    int st = 0, end = sum, ans = 0;

    while (st <= end){
        int mid = st + (end - st)/2;

        if (isValid(arr, n, m, mid)){
            ans = mid; 
            end = mid - 1; 
        }else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr= {15, 17, 20};
    int n = 3, m = 2; //n-> no of books, m-> no of students

    cout << allocateBooks(arr, n, m);
    return 0;
}
