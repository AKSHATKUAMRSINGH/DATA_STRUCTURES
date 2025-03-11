#include <iostream>
using namespace std;

void name(int i, int n) { // Define data types for parameters
    if (i > n) return;
    cout << "Akshat" << endl;
    name(i + 1, n);
}

int main() {
    int n;
    cin >> n;
    name(1, n); // Start recursion with i = 1
    return 0;
}
 