#include <iostream>
using namespace std;

int main() {
    int num1;
    cout<<"Give the Number: ";
    cin>>num1;
    
    for(int i=num1*10; i>=num1; i=i-num1){
        cout<<" "<<i;
    }

    return 0;
}