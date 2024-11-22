# 📚 Heap Sort Algorithm

Heap sort is a comparison-based sorting algorithm that builds a heap from the input array and then sorts the elements. It works by repeatedly extracting the maximum (or minimum) element from the heap and rearranging the remaining elements to maintain the heap property.

## 💡 Problem Description:
Write a program to input an array and sort it in ascending order using the heap sort algorithm.

## 📝 Input Format:
1. The first line of input will contain a single integer `n`, denoting the length of the array.
2. The second line of input will contain `n` space-separated elements `a1, a2, a3, ..., an`.

## 📤 Output Format:
- Print the sorted array in ascending order on a single line.

## 🚀 Example:
**Input:**  
7  
23 9 17 5 31 12 8  

**Output:**  
5 8 9 12 17 23 31


## 🛠️ Steps Involved in Heap Sort:
1. **Build a Max-Heap**: Rearrange the array to satisfy the heap property.
2. **Heapify**: Extract elements one by one, reducing the heap size and maintaining the heap structure.
3. **Sorting**: Swap the root of the heap with the last element and heapify the reduced heap.

## 🔗 Notes:
- Heap sort has a time complexity of O(n log n) and is not a stable sort.
- This implementation uses the max-heap property for sorting in ascending order.

---

