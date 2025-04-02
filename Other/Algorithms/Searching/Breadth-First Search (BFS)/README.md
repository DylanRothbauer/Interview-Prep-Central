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
