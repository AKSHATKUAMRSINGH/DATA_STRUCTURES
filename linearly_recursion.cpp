#include <iostream>
using namespace std;

void num(int i, int n) { // Define data types for parameters
    if (i > n) return;
    cout << i;
    num(i + 1, n);
}

int main() {
    int n;
    cin >> n;
    num(1, n); // Start recursion with i = 1
    return 0;
}
 