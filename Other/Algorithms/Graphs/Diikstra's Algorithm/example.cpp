#include <iostream>     // For input/output (cout, cin)
#include <vector>       // For using dynamic arrays (vector)
#include <queue>        // For priority queue (min-heap)
#include <limits>       // For setting max integer values (numeric_limits)

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();

    /*
	* dist[i] stores the shortest distance from the source node to node i
	* Initially, all distances are set to infinity (numeric_limits<int>::max())
	* dist[source] = 0 because the distance from the source to itself is 0
    */
    vector<int> dist(n, numeric_limits<int>::max()); // Stores shortest distances from source

    /*
	* This is a min-heap (smallest value at the top) that stores pairs of {distance, node}
    * Used to always expand the closest unvisited node first
    * 
	* 1. priority_queue<pair<int, int>>: Stores pairs of integers (pair<int, int>). This is our main container, and we want it to store pairs of {distance, node}
	* 2. vector<pair<int, int>>: Uses a vector as the underlying container (vector<pair<int, int>>), that will store those pairs.
	* 3. greater<pair<int, int>>: The comparator that makes the priority queue behave like a min-heap (smallest value comes first)
    */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap {distance, node}

    // Start from the source node
    dist[source] = 0;
	pq.push({ 0, source }); // Push the source node with distance 0

	// Process the PriorityQueue until it is empty
    /*
	* Pick the node with the smallest distance (top of the priority queue)
	* Remove it from the priority queue and relax all its neighbors
    */
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // If the distance is already outdated, skip processing
		// Sometimes, a nodes might have already been processed with a shorter distance. In this case, we can skip it.
        if (current_dist > dist[current_node]) continue;

		// Explore neighbors (Relaxation - update shortest distances)
        /*
		* Loop through all neighbors of the current node
		* neighbor.first is the weight of the edge
		* neighbor.second is the next node
        */
        for (auto& neighbor : graph[current_node]) {
            int weight = neighbor.first;
            int next_node = neighbor.second;

            // Relaxation step: update distance if a shorter path is found
		    // If we found a shorter path to next_node, update dist[next_node] and push it to the priority queue
            if (dist[current_node] + weight < dist[next_node]) {
                dist[next_node] = dist[current_node] + weight;
                pq.push({ dist[next_node], next_node });
            }
        }
    }

    // Output shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << " -> " << (dist[i] == numeric_limits<int>::max() ? -1 : dist[i]) << endl;
    }
}

// Driver Code
int main() {
    int n = 5; // Number of nodes
    /*
    * graph[i] stores a list of neighbors for node i
	* Each neighbor is represented by a pair {weight, node}
    */
    vector<vector<pair<int, int>>> graph(n);

    // Adding weighted edges (undirected graph example)
	graph[0].push_back({ 10, 1 }); // Edge from node 0 to node 1 with weight 10
    graph[0].push_back({ 5, 3 });
    graph[1].push_back({ 10, 0 });
    graph[1].push_back({ 2, 2 });
    graph[2].push_back({ 2, 1 });
    graph[2].push_back({ 3, 3 });
    graph[2].push_back({ 9, 4 });
    graph[3].push_back({ 5, 0 });
    graph[3].push_back({ 3, 2 });
    graph[3].push_back({ 2, 4 });
    graph[4].push_back({ 9, 2 });
    graph[4].push_back({ 2, 3 });

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
