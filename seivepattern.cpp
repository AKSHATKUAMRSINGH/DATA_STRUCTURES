#include <bits/stdc++.h>
using namespace std;

void pattern19(int N)
{
      int iniS = 0;
      for(int i=0;i< N;i++){

          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }

          for(int j=0;j<iniS;j++){
              cout<<" ";
          }

          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }

          iniS+=2;

          cout<<endl;
      }

      iniS = 2*N -2;
      for(int i=1;i<=N;i++){

          for(int j=1;j<=i;j++){
              cout<<"*";
          }

          for(int j=0;j<iniS;j++){
              cout<<" ";
          }

          for(int j=1;j<=i;j++){
              cout<<"*";
          }

          iniS-=2;

          cout<<endl;
      }
      
}

int main()
{   
    // Here, we have taken the value of N as 5.
    // We can also take input from the user.
    int N = 5;
    
    pattern19(N);

    return 0;
}
