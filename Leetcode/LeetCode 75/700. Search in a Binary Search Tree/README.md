## 700. Search in a Binary Search Tree
**Solved** | Easy

You are given the root of a binary search tree (BST) and an integer `val`.

Find the node in the BST whose value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

### Example 1:
![example1](https://github.com/user-attachments/assets/3ef14bc0-bee1-4cd6-9ae4-6b7608ac5917)


**Input:** `root = [4,2,7,1,3], val = 2`  
**Output:** `[2,1,3]`

### Example 2:
![example2](https://github.com/user-attachments/assets/f1866cb5-63d2-4882-82ba-05a62ff8c9fb)


**Input:** `root = [4,2,7,1,3], val = 5`  
**Output:** `[]`

### Constraints:
- The number of nodes in the tree is in the range `[1, 5000]`.
- `1 <= Node.val <= 10^7`
- `root` is a binary search tree.
- `1 <= val <= 10^7`
