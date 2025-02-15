#include <iostream>
using namespace std;

int main() {
    int num1;
    cout<<"Give the Number: ";
    cin>>num1;
    
    int i=num1*10;
    while (i>=1){
        cout<<" "<<i;
        i=i-num1;
    }

    return 0;
}