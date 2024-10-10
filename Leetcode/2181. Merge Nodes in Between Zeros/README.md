# 2181. Merge Nodes in Between Zeros

**Solved**  
**Difficulty**: Medium  
**Topics**: Linked List, Simulation

---

### Problem

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have `Node.val == 0`.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

---

### Example 1:
![linkedlist_1](https://github.com/user-attachments/assets/50fb180f-8388-486e-b33b-5b50ab9c4e84)

**Input**:  
`head = [0,3,1,0,4,5,2,0]`

**Output**:  
`[4,11]`

**Explanation**:  
The modified list contains:
- The sum of the nodes marked in green: `3 + 1 = 4`.
- The sum of the nodes marked in red: `4 + 5 + 2 = 11`.

---

### Example 2:
![linkedlist_2](https://github.com/user-attachments/assets/b75c9519-4e5d-4983-9e22-b0c10fd8cca1)

**Input**:  
`head = [0,1,0,3,0,2,2,0]`

**Output**:  
`[1,3,4]`

**Explanation**:  
The modified list contains:
- The sum of the nodes marked in green: `1 = 1`.
- The sum of the nodes marked in red: `3 = 3`.
- The sum of the nodes marked in yellow: `2 + 2 = 4`.

---

### Constraints:

- The number of nodes in the list is in the range `[3, 2 * 10^5]`.
- `0 <= Node.val <= 1000`.
- There are no two consecutive nodes with `Node.val == 0`.
- The beginning and end of the linked list have `Node.val == 0`.

---

### Hints:

1. How can you use two pointers to modify the original list into the new list?
2. Have a pointer traverse the entire linked list, while another pointer looks at a node that is currently being modified.
3. Keep summing the values of the nodes between the traversal pointer and the modifying pointer until the former comes across a `0`. In that case, the modifying pointer is incremented to modify the next node.
4. Do not forget to have the next pointer of the final node of the modified list point to `null`.

---

**Acceptance Rate**: 89.8%  
**Companies**: Various

