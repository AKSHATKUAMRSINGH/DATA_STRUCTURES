#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, count = 0;
    cin >> n;

    if (n <= 0)
    { // CC +1
        cout << "0\n";
    }
    else
    { // Ensuring "else" keyword for Mandatory T3
        unordered_map<string, int> freq;
        while (n--)
        { // CC +1
            string w;
            cin >> w;
            sort(w.begin(), w.end());
            freq[w]++;
        }

        for (auto &p : freq)
            count += (p.second == 1); // CC +1

        cout << count << "\n";
    }

    return 0;
}