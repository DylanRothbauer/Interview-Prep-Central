# I also wanted to include a python example so I could reference if need be (code provided by CodeChef)
class MinHeap:
    def __init__(self):
        self.heap = []

    # Helper function to maintain the heap property by moving the element up
    def heapify_up(self, index):
        while index > 0:
            parent_index = (index - 1) // 2
            if self.heap[index] < self.heap[parent_index]:
                self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
                index = parent_index
            else:
                break

    # Function to insert a new element into the heap
    def insert(self, value):
        self.heap.append(value)
        self.heapify_up(len(self.heap) - 1)

if __name__ == "__main__":
    n = int(input())
    h1 = MinHeap()
    for _ in range(n):
        n1 = int(input())
        h1.insert(n1)

        print(" ".join(map(str, h1.heap)))
