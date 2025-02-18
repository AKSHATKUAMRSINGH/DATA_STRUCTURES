#include <iostream>
using namespace std;

void pattern1(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
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