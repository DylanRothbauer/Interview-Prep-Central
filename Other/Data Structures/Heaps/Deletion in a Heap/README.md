# 🗑️ Deletion in a Min-Heap

A **min-heap** is a binary tree data structure that ensures the smallest element is always at the root. When deleting elements, the min-heap property must be maintained.

## 🚀 Deletion Process:
### Steps for Deleting the Minimum Element (Root):
1. **Remove the Root:**
   - Swap the root with the last leaf (the rightmost leaf of the last level).
   - Remove the last leaf from the heap.

2. **Heapify Down:**
   - Compare the new root with its children.
   - Swap the root with the smaller of its two children to maintain the min-heap property.
   - Repeat this process recursively until the heap property is restored.

## 📜 Pseudocode:
```
Function deleteMin():
    If heap is empty:
        Return an error (heap is empty)
    
    Swap heap[0] (root) with heap[size - 1] (last leaf)
    Remove the last element from the heap

    HeapifyDown(0)  // Start the heapify process from the root

Function HeapifyDown(index):
    leftChild = 2 * index + 1
    rightChild = 2 * index + 2
    smallest = index

    If leftChild < size and heap[leftChild] < heap[smallest]:
        smallest = leftChild

    If rightChild < size and heap[rightChild] < heap[smallest]:
        smallest = rightChild

    If smallest != index:
        Swap heap[index] with heap[smallest]
        HeapifyDown(smallest)  // Recursively heapify the affected subtree
```

## 📝 Task:
Given a Min-Heap:
1. The first line contains an integer `N`, the length of the min-heap.
2. The second line contains `N` elements of the heap (`a1, a2, ..., aN`).
3. Perform the deletion operation repeatedly until the heap is empty. After each deletion, print the heap array.

## 📊 Sample:
**Input:**  
5  
1 2 4 5 3

**Output:**  
2 3 4 5  
3 5 4  
4 5  
5  


