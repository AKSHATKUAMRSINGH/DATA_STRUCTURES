#include <bits/stdc++.h>
using namespace std;

int main(){
    //taking input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //precompute
    int hash[15] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    //Fetches value
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        
        cout<<hash[x]<<endl;
    }
    return 0;
}