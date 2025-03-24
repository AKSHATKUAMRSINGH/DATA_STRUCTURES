#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n <= 1) return n;
    int last = f(n-1);
    int secondLast = f(n-2);
    return last + secondLast;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}