#include <iostream>
using namespace std;

void pattern1(int n) {        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout<<j<<" ";
        }
        cout<<endl;        
    }
}
int main(){
    int n;
    cout<<"Enter number of rows and columns: ";
    cin>>n;
    pattern1(n);
    return 0;
}