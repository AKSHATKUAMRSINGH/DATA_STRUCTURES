#include <iostream>
using namespace std;

int main(){
    int summ;
    int n;
    int dup;
    cin>>n;
    dup=n;
    int rev_num=0;
    while(n>0){
        int ld=n%10;
        summ=summ+(ld*ld*ld);
        n=n/10;
    }
    cout<<summ;
    if(summ==dup){
        cout<<" is a armstrong number";
    }
    else{
        cout<<" is not a armstrong number";
    }
}