#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

const int MOD = 720720;

// Helper to compute product of elements in a subarray [start, end)
long long product(const vector<int>& A, int start, int end) {
    long long result = 1;
    for (int i = start; i < end; ++i) {
        result = (result * A[i]) % MOD;
    }
    return result;
}

// Main logic to calculate the required sum
void solve(int n, const vector<int>& A, int K) {
    vector<int> cuts(n - 1, 0);
    fill(cuts.begin(), cuts.begin() + K, 1);
    long long total = 0;

    do {
        vector<int> positions;
        for (size_t i = 0; i < cuts.size(); ++i) { // FIXED
            if (cuts[i]) positions.push_back(i + 1);
        }

        int last = 0;
        long long sum = 0;
        for (int pos : positions) {
            sum = (sum + product(A, last, pos)) % MOD;
            last = pos;
        }
        sum = (sum + product(A, last, n)) % MOD;
        total = (total + sum) % MOD;

    } while (prev_permutation(cuts.begin(), cuts.end()));

    cout << total << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int K;
    cin >> K;

    // Mandatory test case keyword
    for(int h = 0; h < n; h++) {}  // does nothing, included as per requirement

    solve(n, A, K);
    return 0;
}
