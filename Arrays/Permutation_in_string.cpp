/*
Problem: Permutation in String
LeetCode: #567

Description:
Given two strings s1 and s2, determine whether s2 contains
a permutation of s1 as one of its substrings.

Approach:
Use a fixed-size sliding window along with frequency counts.
Maintain the character frequencies of s1 and compare them with
the frequencies of each window of the same length in s2.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

bool sameFreq(int arr1[], int arr2[]){
    for (int i = 0; i < 26; i++){
        if (arr1[i] != arr2[i]){
            return false;
        }
    }

    return true;
}

bool checkInclusion(string s1, string s2){
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++){
        freq[s1[i] - 'a']++; 
    }

    int windsize = s1.length();

    for (int i = 0; i < s2.length(); i++){
        int windidx = 0, idx = i;
        int windfreq[26] = {0};

        while (windidx < windsize && idx < s2.length()){
            windfreq[s2[idx] - 'a']++;
            windidx++, idx++;
        }

        if (sameFreq(freq, windfreq)){
            return true;
        }
    }

    return false;
}

int main(){
    string s1 = "ab", s2 = "eidbaooo";

    cout << checkInclusion(s1, s2);
    return 0;
}
