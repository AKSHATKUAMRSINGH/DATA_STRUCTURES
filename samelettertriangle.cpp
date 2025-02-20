#include <iostream>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch='A'+i;
        for (int j=0; j<= i; j++)
        {
            cout << ch << " ";
            
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter number of rows and columns: ";
    cin >> n;
    pattern1(n);
    return 0;
}