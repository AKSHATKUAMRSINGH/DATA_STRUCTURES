#include <iostream>
using namespace std;

int main(){
    int n;
    int dup;
    cin>>n;
    dup=n;
    int rev_num=0;
    while(n>0){
        int ld=n%10;
        rev_num=(rev_num*10)+ld;
        n=n/10;
    }
    cout<<rev_num;
    if(rev_num==dup){
        cout<<" is a palindrome";
    }
    else{
        cout<<" is not a palindrome";
    }
}