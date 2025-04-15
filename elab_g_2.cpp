#include<iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    for (int a = 0; a <= n / 1234567; ++a)
        for (int b = 0; b <= (n - 1234567 * a) / 123456; ++b)
            if ((n - 1234567 * a - 123456 * b) % 1234 == 0) return cout << "YES", 0;
    cout<<"NO";
}