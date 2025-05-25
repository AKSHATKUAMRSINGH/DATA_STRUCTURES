// C++ program for range minimum
// query using segment tree 
#include <bits/stdc++.h>
using namespace std;

// A utility function to get minimum of two numbers 
int minVal(int x, int y) { 
    return (x < y)? x: y; 
} 

// A utility function to get the 
// middle index from corner indexes. 
int getMid(int s, int e) { 
    return s + (e -s)/2; 
} 

// A recursive function to get the
// minimum value in a given range of array
// st --> Pointer to segment tree 
// index --> Index of current node in the tree
// ss & se --> Starting and ending indexes 
// qs & qe --> Starting and ending indexes of query range
int RMQUtil(vector<int> &st, int ss, int se, int qs, 
                                int qe, int index) { 

    // If segment of this node is a part of given range
    // then return the min of the segment
    if (qs <= ss && qe >= se) 
        return st[index]; 

    // If segment of this node if outside the range
    if (se < qs || ss > qe) 
        return INT_MAX; 

    // If a part of this segment
    // overlaps with the given range 
    int mid = getMid(ss, se); 
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1), 
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2)); 
} 

// Return minimum of elements in range
// from index qs to qe
int RMQ(vector<int> &st, int n, int qs, int qe) { 

    // Check for invalid input
    if (qs < 0 || qe > n-1 || qs > qe) { 
        cout<<"Invalid Input"; 
        return -1; 
    } 
    return RMQUtil(st, 0, n-1, qs, qe, 0); 
} 

// A recursive function that constructs
// Segment Tree for array[ss..se]. 
int constructSTUtil(vector<int> &arr, int ss, int se,
                            vector<int> &st, int si) {

    // If there is one element in array,
    // store it in current node of 
    // segment tree and return 
    if (ss == se) { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 

    // If there are more than one elements, 
    // then recur for left and right subtrees 
    // and store the minimum of two values in this node 
    int mid = getMid(ss, se); 
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1), 
                    constructSTUtil(arr, mid+1, se, st, si*2+2)); 
    return st[si]; 
} 

// Function to construct segment tree 
vector<int> constructST(vector<int> &arr, int n) { 

    //Height of segment tree 
    int x = (int)(ceil(log2(n))); 

    // Maximum size of segment tree 
    int max_size = 2*(int)pow(2, x) - 1; 

    vector<int> st(max_size);

    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, st, 0); 

    // Return the constructed segment tree 
    return st; 
} 

int main() {
 
    vector<int> arr = {1, 3, 2, 7, 9, 11}; 
    int n = arr.size();

    // Build segment tree from given array 
    vector<int> st = constructST(arr, n); 

    // Starting index of query range 
    int qs = 1; 
    
    // Ending index of query range 
    int qe = 5; 

    // Print minimum value in arr[qs..qe] 
    cout<<"Minimum of values in range ["<<qs<<", "<<qe<<"] "<<
    "is = "<<RMQ(st, n, qs, qe)<<endl; 

    return 0; 
}