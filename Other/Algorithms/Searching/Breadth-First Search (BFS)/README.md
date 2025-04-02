# Breadth-First Search (BFS)

## Overview
**Breadth-First Search (BFS)** is an algorithm used to traverse or search through a graph or tree data structure. It explores all the nodes at the present depth level before moving on to the nodes at the next depth level. BFS is widely used in various applications such as finding the shortest path in an unweighted graph, solving puzzles, and network broadcasting.

## How BFS Works

BFS starts at a given node (usually called the **source** or **root**) and explores all of its neighbors first. After visiting the neighbors, it proceeds to visit their neighbors, and so on, level by level. This continues until all nodes are visited or the target node is found.

### BFS Algorithm (Step-by-Step)
1. **Start with the source node**: Begin at the starting node and mark it as visited.
2. **Queue the source node**: Put the starting node into a queue (FIFO).
3. **Visit nodes**: While the queue is not empty:
   - Dequeue the front node from the queue.
   - Visit the node and process it.
   - Enqueue all unvisited neighbors of the current node and mark them as visited.
4. **Repeat** until all nodes are visited or the target node is found.

## Time Complexity

The **Time Complexity** of Breadth-First Search (BFS) is **O(V + E)**, where:
- **V** is the number of vertices (nodes) in the graph.
- **E** is the number of edges in the graph.

### Breakdown:
- **O(V)**: Each node is visited exactly once.
- **O(E)**: Each edge is processed exactly once. In an undirected graph, an edge is considered twice (once from each vertex), but it's still processed in linear time relative to the number of edges.

BFS explores nodes level by level and processes each edge once, making it efficient for many graph-related problems, such as finding the shortest path in an unweighted graph.

### Example:
If you have a graph with:
- **1000 nodes (V = 1000)** and
- **5000 edges (E = 5000)**,

the time complexity would be **O(1000 + 5000) = O(6000)**, meaning the running time of BFS grows linearly with both the number of nodes and edges in the graph.

### Space Complexity
The **Space Complexity** of BFS is **O(V)**, where:
- **V** is the number of vertices, as the algorithm requires space to store:
  - The **visited set** to track which nodes have been processed.
  - The **queue** to store nodes that need to be processed.

In the worst case, the queue may store all nodes, leading to a space complexity of **O(V)**.
