#include <bits/stdc++.h> 
using namespace std; 
 
int minHeadings(string s1, string s2) { 
    int m = s2.size(), j = 0, count = 0; 
     
    while (j < m) {  // (1) while loop 
        int prev_j = j; 
        for (char c : s1) {  // (2) for loop 
            j += (j < m && c == s2[j]);  // (3) condition merged 
        } 
        if (prev_j == j) return -1;  // (4) if condition 
        ++count; 
    } 
     
    return count; 
} 
 
int main() { 
    string s1, s2; 
    cin>>s1>>s2; 
    cout << minHeadings(s1, s2) << endl; 
    return 0; 
} 
 
