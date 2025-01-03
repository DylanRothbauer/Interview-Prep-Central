# 🛠️ Contains Duplicate

### Status: **Solved** ✅

---

## 📝 Problem Description

**Given**: An integer array `nums`.  
**Task**: Return `true` if any value appears more than once in the array; otherwise, return `false`.  

---

### 🔍 Examples

#### Example 1  
**Input**: `nums = [1, 2, 3, 3]`  
**Output**: `true`

#### Example 2  
**Input**: `nums = [1, 2, 3, 4]`  
**Output**: `false`

---

### 📊 Recommended Complexity

- **Time Complexity**: `O(n)`  
- **Space Complexity**: `O(n)`  
  *(where `n` is the size of the input array)*

---

### 💡 Hints

1. **Brute Force**: A simple solution is to compare each element with every other element in the array. However, this results in an `O(n^2)` solution, which is inefficient for larger arrays.  
2. **Optimal Approach**: Avoid comparing every element. Is there a data structure that can help you track elements you've already seen?  
3. **Hashing**: Use a hash set to store elements as you traverse the array. Check if an element already exists in the set, which allows for duplicate detection in constant time.

---

### 🚀 Approach

To achieve the desired `O(n)` time and space complexity:
- Traverse the array once, storing each element in a hash set.
- At each step, check if the current element already exists in the hash set:
  - **Yes**: A duplicate is found; return `true`.
  - **No**: Add the element to the hash set and continue.

---

## 📹 Video Explanation

For a step-by-step walkthrough of this problem, check out the explanation by **Navi** on YouTube:  
[Contains Duplicate | NeetCode](https://www.youtube.com/watch?v=3OamzN90kPg)

---
