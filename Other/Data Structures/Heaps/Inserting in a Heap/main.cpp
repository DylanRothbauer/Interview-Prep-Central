#include <bits/stdc++.h>

using namespace std;
class MinHeap {
public: std::vector < int > heap;

      // Helper function to maintain the heap property by moving the element up
      void heapifyUp(int index) {
          while (index > 0) {
              int parentIndex = (index - 1) / 2;
              if (heap[index] < heap[parentIndex]) {
                  std::swap(heap[index], heap[parentIndex]);
                  index = parentIndex;
              }
              else {
                  break;
              }
          }
      }

public:
    // Function to insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
};
int main() {
    int n;
    cin >> n;
    MinHeap h1;
    for (int i = 0; i < n; i++) {
        int n1;
        cin >> n1;
        h1.insert(n1);

        for (int i = 0; i < h1.heap.size(); i++) {
            cout << h1.heap[i] << " ";
        }
        cout << "\n";
    }
}