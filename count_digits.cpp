#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int count_digits(int n){
        int count = 0;
        while(n!=0){
            n = n/10;
            count++;
        }
        return count;
    }
};