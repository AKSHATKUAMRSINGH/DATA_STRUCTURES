#include <bits/stdc++.h>
using namespace std;

int smallestSumSubarr(vector<int> arr)
{
    int n = arr.size();
    int min_sum = INT_MAX; 
    int temp = 0;
    for( int i=0; i<n; i++)
    {
        temp =0; 
        for( int j=i; j<n; j++)
        {
            temp+= arr[j];
            min_sum = min(min_sum, temp);
        }
    }
    return min_sum; 
}


int main()
{
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
    cout <<smallestSumSubarr(arr);
    return 0;
}