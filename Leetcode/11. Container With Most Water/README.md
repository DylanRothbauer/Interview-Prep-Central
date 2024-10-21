# 11. Container With Most Water

**Solved**  
**Difficulty:** Medium  

## Problem Description  
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i-th` line are `(i, 0)` and `(i, height[i])`.  

Find two lines that, together with the x-axis, form a container that holds the **most water**.  

Return the **maximum amount of water** the container can store.  

**Note:** The container **cannot be slanted**.  

---

## Example 1  
**Input:**  
height = [1,8,6,2,5,4,8,3,7]  
  
**Output:**  
49  

**Explanation:**  
- The vertical lines are represented by the array `[1,8,6,2,5,4,8,3,7]`.  
- The max area of water (blue section) the container can contain is `49`.

---

## Example 2  
**Input:**  
height = [1,1]  
  
**Output:**  
1

---

## Constraints  
- `n == height.length`  
- `2 <= n <= 10^5`  
- `0 <= height[i] <= 10^4`  

---

## Hints  
1. **O(n²)** simulation is not efficient.
2. Use **two pointers**: one at the left and one at the right of the array.  
3. Move the pointer that points to the **lower height**.  

---
