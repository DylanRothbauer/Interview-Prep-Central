#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> heap;

    // Constructor to initialize the heap with given elements
    MinHeap(const vector<int>& elements) {
        heap = elements;
        buildHeap();
    }

    // Function to heapify downwards from a given index
    void heapifyDown(int index) {
        int size = heap.size();
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);  // Recursively heapify the affected subtree
        }
    }

    // Function to build the min-heap by heapifying all non-leaf nodes
    void buildHeap() {
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Function to delete the minimum element (root) from the heap
    void deleteMin() {
        if (heap.empty()) return;

        // Swap root with the last element and remove the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Heapify down from the root to restore min-heap property
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    // Function to print the current state of the heap
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    MinHeap minHeap(elements);

    // Perform deletion until the heap is empty
    while (!minHeap.heap.empty()) {
        minHeap.deleteMin();  // Delete the root (minimum element)
        minHeap.printHeap();  // Print heap state after deletion
    }

    return 0;
}
