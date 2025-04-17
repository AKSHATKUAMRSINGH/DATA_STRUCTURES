#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int j = 1; j <= n; j++) {
        dp[1][j] = 1;
    }
    int i;
    for(i=0;i<n-1;i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == '<') {
                for (int k = j + 1; k <= n; k++) {
                    dp[i + 2][k] = (dp[i + 2][k] + dp[i + 1][j]) % MOD;
                }
            } else if (s[i] == '>') {
                for (int k = 1; k < j; k++) {
                    dp[i + 2][k] = (dp[i + 2][k] + dp[i + 1][j]) % MOD;
                }
            } else { // s[i] == '='
                dp[i + 2][j] = (dp[i + 2][j] + dp[i + 1][j]) % MOD;
            }
        }
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + dp[n][i]) % MOD;
    }

    cout << result << endl;
    return 0;
}