# 🌟 Insertion in a Min-Heap

A **min-heap** is a binary tree data structure that maintains the **heap property**: the value of any node is less than or equal to the values of its children.

### 📝 Key Concepts:
- **Heap Property:** In a min-heap, each parent node is smaller than its children.
- **Complete Binary Tree:** The tree is completely filled at all levels except possibly the lowest, which is filled from left to right.
- **Array Representation:** Min-heaps are typically implemented using arrays:
  - Left child of a node at index `i` is at `2i + 1`
  - Right child of a node at index `i` is at `2i + 2`
  - Parent of a node at index `i` is at `(i - 1) / 2`

### 🔄 Insertion Process:
1. **Add the element** at the end of the array (as the last leaf in the binary tree).
2. **Heapify Up:** Compare the new element with its parent and swap them if necessary to restore the heap property.

### 🧩 Pseudocode:
```plaintext
Class MinHeap:
    Public:
        heap: List of integers

        // Helper function to maintain the heap property by moving the element up
        Function heapifyUp(index):
            While index > 0:
                parentIndex = (index - 1) / 2
                If heap[index] < heap[parentIndex]:
                    Swap heap[index] with heap[parentIndex]
                    index = parentIndex
                Else:
                    Break

        // Function to insert a new element into the heap
        Function insert(value):
            Append value to heap
            Call heapifyUp(heap.size() - 1)

```

### 📊 Task:
You are given an integer N (the number of elements) and N integers. Your task is to insert these integers into a min-heap and print the array after each insertion.

### Example:
**Input:**  
5  
5  
4  
3  
2  
1  

**Output:**
5  
4 5  
3 5 4  
2 3 4 5  
1 2 4 5 3  

### 📌 Explanation:
Step 1: Insert 5 → [5]  
Step 2: Insert 4 → [4, 5] (swap 4 and 5)  
Step 3: Insert 3 → [3, 5, 4] (swap 3 with 4)  
Step 4: Insert 2 → [2, 3, 4, 5] (swap 2 up the heap)  
Step 5: Insert 1 → [1, 2, 4, 5, 3] (swap 1 up the heap)  

**Note:** Explaination provided by CodeChef
