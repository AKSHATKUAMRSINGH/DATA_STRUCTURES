#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<unordered_map<char, int>> row_freq(n), col_freq(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
            row_freq[i][a[i][j]]++;
            col_freq[j][a[i][j]]++;
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (row_freq[i][a[i][j]] == 1 && col_freq[j][a[i][j]] == 1)
                cout<<a[i][j];
}