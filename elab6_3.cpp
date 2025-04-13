#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

// Function to read an integer from standard input
int rdint() {
    int x;
    cin >> x;
    return x;
}

void cf() {
    int n = rdint(); // Number of points
    int m = rdint(); // Number of tunnels
    int p = rdint(); // Modulo value

    vector<int> o(n);
    for (int i = 0; i < n; i++) {
        o[i] = rdint(); // Read danger times for each point
    }

    // Create an adjacency list for the graph
    vector<vector<pair<int, long long>>> graph(n);
    for (int i = 0; i < m; i++) {
        int a = rdint();
        int b = rdint();
        long long c = rdint();
        graph[a].emplace_back(b, c); // directed edge
    }

    // Priority queue for Dijkstra's: (currentTime, currentNode)
    priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;
    vector<vector<long long>> minTime(n, vector<long long>(p, INF));

    // Start from node 0 at time 0
    pq.emplace(0, 0);
    minTime[0][0] = 0;

    while (!pq.empty()) {
        long long currentTime;
        int currentPoint;
        tie(currentTime, currentPoint) = pq.top();
        pq.pop();

        if (currentPoint == n - 1) {
            cout << currentTime << endl;
            return;
        }

        for (size_t i = 0; i < graph[currentPoint].size(); ++i) {
            int neighbor = graph[currentPoint][i].first;
            long long travelTime = graph[currentPoint][i].second;
            long long arrivalTime = currentTime + travelTime;
            int arrivalMod = arrivalTime % p;

            if (arrivalMod != o[neighbor]) {
                if (arrivalTime < minTime[neighbor][arrivalMod]) {
                    minTime[neighbor][arrivalMod] = arrivalTime;
                    pq.emplace(arrivalTime, neighbor);
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cf();
    return 0;
}