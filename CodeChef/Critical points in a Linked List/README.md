# Critical Points in a Linked List

Given the head of a linked list, find the number of critical points. (The starting and ending nodes are not considered critical points).

**Local minima or maxima are called critical points.**

- A node is called a **local minima** if both the next and previous elements are greater than the current element.
- A node is called a **local maxima** if both the next and previous elements are smaller than the current element.

## Constraints
- 1 ≤ Number of elements in the linked list (N) ≤ 10<sup>5</sup>
- 1 ≤ Node.data ≤ 10<sup>9</sup>

## Sample 1:
### Input:
8  
1 2 3 3 3 5 1 3

#### Output:
2

### Explanation:
1 is a minima and 5 is a maxima hence there are 2 critical points

## Sample 2:
### Input:
7  
1 2 3 2 1 3 2

#### Output:
3

### Explanation:
3rd node, 5th node and 6th node are the critical nodes, hence the answer is 3
