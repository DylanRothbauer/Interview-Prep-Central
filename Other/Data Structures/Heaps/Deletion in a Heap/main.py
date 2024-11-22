class MinHeap:
    def __init__(self, elements):
        self.heap = elements
        self.build_heap()

    def heapify_down(self, index):
        size = len(self.heap)
        smallest = index
        left_child = 2 * index + 1
        right_child = 2 * index + 2

        if left_child < size and self.heap[left_child] < self.heap[smallest]:
            smallest = left_child
        if right_child < size and self.heap[right_child] < self.heap[smallest]:
            smallest = right_child
        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self.heapify_down(smallest)  # Recursively heapify the affected subtree

    def build_heap(self):
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self.heapify_down(i)

    def delete_min(self):
        if not self.heap:
            return

        # Swap root with the last element and remove the last element
        self.heap[0] = self.heap[-1]
        self.heap.pop()

        # Heapify down from the root to restore min-heap property
        if self.heap:
            self.heapify_down(0)

    def print_heap(self):
        print(" ".join(map(str, self.heap)))


if __name__ == "__main__":
    n = int(input())
    elements = list(map(int, input().split()))

    min_heap = MinHeap(elements)

    # Perform deletion until the heap is empty
    while min_heap.heap:
        min_heap.delete_min()  # Delete the root (minimum element)
        min_heap.print_heap()  # Print heap state after deletion
