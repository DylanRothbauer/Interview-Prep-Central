#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visited: " << node << endl;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n);

    // Example graph (0-based indexing)
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3, 4 };
    adj[2] = { 0, 4 };
    adj[3] = { 1 };
    adj[4] = { 1, 2 };

    BFS(adj, 0); // Start BFS from node 0
    return 0;
}
