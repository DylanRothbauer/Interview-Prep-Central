# 1574. Shortest Subarray to be Removed to Make Array Sorted
**Difficulty:** Medium  
**Topics:** Arrays, Two Pointers

---

## Problem Statement

Given an integer array `arr`, remove a subarray (which can be empty) such that the remaining elements in `arr` are in non-decreasing order. Return the length of the shortest subarray to remove.

---

## Examples

### Example 1:
**Input:**  
`arr = [1,2,3,10,4,2,3,5]`  
**Output:**  
`3`

**Explanation:** The shortest subarray we can remove is `[10,4,2]` of length 3. The remaining elements after that will be `[1,2,3,3,5]` which are sorted. Another correct solution is to remove the subarray `[3,10,4]`.

### Example 2:
**Input:**  
`arr = [5,4,3,2,1]`  
**Output:**  
`4`

**Explanation:** Since the array is strictly decreasing, we can only keep a single element. Therefore, we need to remove a subarray of length 4, either `[5,4,3,2]` or `[4,3,2,1]`.

### Example 3:
**Input:**  
`arr = [1,2,3]`  
**Output:**  
`0`

**Explanation:** The array is already non-decreasing. We do not need to remove any elements.

---

## Constraints

- `1 <= arr.length <= 10^5`
- `0 <= arr[i] <= 10^9`

---
