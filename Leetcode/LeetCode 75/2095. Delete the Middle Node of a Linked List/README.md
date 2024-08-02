# 2095. Delete the Middle Node of a Linked List

**Solved** | Medium

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size `n` is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For `n = 1, 2, 3, 4, and 5`, the middle nodes are `0, 1, 1, 2, and 2`, respectively.

### Example 1:
![ll1](https://github.com/user-attachments/assets/0b17a02f-f032-4357-9188-b3070f29b8b0)

**Input:** 
`head = [1,3,4,7,1,2,6]`

**Output:** 
`[1,3,4,1,2,6]`

**Explanation:**  
The above figure represents the given linked list. The indices of the nodes are written below.  
Since `n = 7`, node `3` with value `7` is the middle node, which is marked in red.  
We return the new list after removing this node. 

### Example 2:
![ll2](https://github.com/user-attachments/assets/73743f7b-8f75-457d-98b7-71531fabfaa9)

**Input:** 
`head = [1,2,3,4]`

**Output:** 
`[1,2,4]`

**Explanation:**  
The above figure represents the given linked list.  
For `n = 4`, node `2` with value `3` is the middle node, which is marked in red.

### Example 3:
![ll3](https://github.com/user-attachments/assets/2b553562-c096-44ee-b035-d2324c487438)

**Input:** 
`head = [2,1]`

**Output:** 
`[2]`

**Explanation:**  
The above figure represents the given linked list.  
For `n = 2`, node `1` with value `1` is the middle node, which is marked in red.  
Node `0` with value `2` is the only node remaining after removing node `1`.

### Constraints:

- The number of nodes in the list is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`

### Hint 1

If a point with a speed `s` moves `n` units in a given time, a point with speed `2 * s` will move `2 * n` units at the same time. Can you use this to find the middle node of a linked list?

### Hint 2

If you are given the middle node, the node before it, and the node after it, how can you modify the linked list?
