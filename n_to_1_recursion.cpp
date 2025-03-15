#include <iostream>
using namespace std;

void num(int i, int n) { // Define data types for parameters
    if (i < 1) return;
    cout << i;
    num(i - 1, n);
}

int main() {
    int n;
    cin >> n;
    num(n, n); // Start recursion with i = 1
    return 0;
}
 