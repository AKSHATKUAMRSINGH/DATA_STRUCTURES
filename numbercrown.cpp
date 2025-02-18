#include <iostream>
using namespace std;

void pattern1(int n) {  
    int space=2*(n-1);      
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        for(int j=1; j<=space;j++){
            cout<<" ";
        }
        for(int j=i; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
        space -=2;
        }
                
    }
int main(){
    int n;
    cout<<"Enter number of rows and columns: ";
    cin>>n;
    pattern1(n);
    return 0;
}