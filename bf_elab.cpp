#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    
    // Initially distance from source to all 
    // other vertices is not known(Infinite).
	vector<int> dist(V, 1e8);
	dist[src] = 0;
  
	// Relaxation of all the edges V times, not (V - 1) as we
    // need one additional relaxation to detect negative cycle
	for (int i = 0; i < V; i++) {
	    
		for (vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			    
                // If this is the Vth relaxation, then there is
                // a negative cycle
                if(i == V - 1)
                    return {-1};
               
                // Update shortest distance to node v
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist;
}

int main() {
    
    // Number of vertices in the graph
    int V = 5;

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    // Define the source vertex
    int src = 0;

    // Run Bellman-Ford algorithm to get shortest paths from src
    vector<int> ans = bellmanFord(V, edges, src);

    // Output the shortest distances from src to all vertices
    for (int dist : ans) 
        cout << dist << " ";

    return 0; 
}