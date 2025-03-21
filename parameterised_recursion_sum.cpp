#include <iostream>
using namespace std;

void num(int i, int sum) { // Define data types for parameters
    if (i < 1) {
        cout << sum<<endl;
        return;
    }
    num(i - 1, sum+i);
}

int main() {
    int n;
    cin >> n;
    num(n, 0); // Start recursion with i = 1
    return 0;
}