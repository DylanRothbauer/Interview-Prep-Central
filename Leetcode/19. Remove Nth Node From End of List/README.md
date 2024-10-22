# 19. Remove Nth Node From End of List  
**Solved**  
**Medium**  

---

### Problem  
Given the head of a linked list, remove the nth node from the end of the list and return its head.  

---

### Example 1:
![linkedlist](https://github.com/user-attachments/assets/7d0afeaa-7886-4b15-9205-39a4fbb5f3b0)

Input: head = [1,2,3,4,5], n = 2  
Output: [1,2,3,5]

### Example 2:
Input: head = [1], n = 1  
Output: []

### Example 3:
Input: head = [1,2], n = 1  
Output: [1]

---

### Constraints:
- The number of nodes in the list is `sz`.  
- `1 <= sz <= 30`  
- `0 <= Node.val <= 100`  
- `1 <= n <= sz`  

---

### Follow Up:
Could you do this in one pass?  

---

### Hints:
1. Maintain two pointers and update one with a delay of `n` steps.

---
