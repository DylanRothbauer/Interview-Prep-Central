# 🍉 Problem 4A - Watermelon

## 📂 Problem Details

| **Problem ID** | **Name**      | **Topics**           | **Difficulty** | **Participants Solved** |
|----------------|---------------|----------------------|----------------|--------------------------|
| 4A             | Watermelon    | brute force, math    | 800            | 547,886                  |


## 📄 Problem Description

Pete and Billy want to divide a watermelon they bought into two parts such that:  
1. Each part weighs an **even number of kilos**.
2. Each part has a **positive weight**.

Help Pete and Billy determine if such a division is possible.

### Input
A single integer `w` (1 ≤ w ≤ 100), the weight of the watermelon.

### Output
Print `YES` if the watermelon can be divided as desired, or `NO` otherwise.

---

## 🔑 Examples

| **Input** | **Output** | **Explanation**                                                   |
|-----------|------------|-------------------------------------------------------------------|
| 8         | YES        | Watermelon can be divided into parts of 2 and 6 or 4 and 4 kilos.|
| 3         | NO         | Watermelon cannot be divided into two even, positive weights.    |

---

## 🧠 Key Insights

- The watermelon must weigh at least `4` kilos to allow a division into two **positive even parts**.
- The weight `w` must be **even** for the division to be possible.

---

## 🏆 Solution

### Approach:
1. Check if `w` is even and greater than `2`.  
   - **Even check** ensures both parts are even.
   - **Greater than 2 check** ensures positive weights for both parts.
2. Return `YES` if both conditions are met, otherwise return `NO`.

### Complexity:
- **Time Complexity:** O(1), as the solution involves a constant number of checks.
- **Space Complexity:** O(1), as no extra space is used.

---

## 📜 Implementation

### Python Code:
```python
w = int(input())
if w > 2 and w % 2 == 0:
    print("YES")
else:
    print("NO")

