# Dijkstra’s Algorithm

Dijkstra’s Algorithm is a graph search algorithm used to find the **shortest path** from a single source node to all other nodes in a **weighted graph**.  
It is widely used in **network routing, GPS navigation, and various optimization problems**.

---

## How It Works

Dijkstra’s Algorithm follows a **greedy approach** and works as follows:

### **1️⃣ Initialize:**
- Set the **distance** to the **source node** as `0` and all other nodes as **infinity** (`∞`).
- Mark **all nodes as unvisited**.
- Create a **priority queue (min-heap)** to store nodes based on their **tentative distance**.

### **2️⃣ Processing Nodes:**
- Pick the node with the **smallest tentative distance**.
- Update the **distances** to its **neighboring nodes** if a **shorter path** is found.
- Mark the **current node as visited** (so it won’t be processed again).

### **3️⃣ Repeat Until Done:**
- Continue picking the **nearest unvisited node** and **updating distances**.
- Stop when **all nodes** have been visited **or** the **shortest path** to the desired node is found.
- **Reconstruct the shortest path** if needed by **backtracking** from the target node.

---

## Time Complexity

| Implementation Method | Time Complexity |
|----------------------|----------------|
| **Using a simple array** | `O(V²)` (where `V` is the number of vertices) |
| **Using a priority queue (Min-Heap)** | `O((V + E) log V)` (better for large graphs) |

---

🔹 **Best for:** Weighted graphs with **non-negative** edge weights.  
🔹 **Not suitable for:** Graphs with **negative weights** (use Bellman-Ford instead).  
🔹 **Common Applications:** GPS Navigation, Internet Routing, Game AI Pathfinding.

---

🚀 **Want to see an example implementation?** Check out the [C++ Code](#).  
