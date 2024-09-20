# Cycle Detection in a Linked List

## Problem Statement

You are given a linked list `A` of size `N`.

Return the node where the cycle begins in the linked list. If there is no cycle, return `NULL`.

### Input:

- The first line contains an integer `T`, the number of test cases.
- Each test case contains three lines of input:
  1. The first line contains an integer `N`, the length of the linked list `A`.
  2. The second line contains `A1, A2, ..., AN`, the values of the linked list nodes starting from the head.
  3. The third line contains an integer denoting the index of the node where the cycle starts.

### Output:

- The function you complete should return the value of the node where the cycle begins or `NULL` if there is no cycle.

### Function Signatures:

For different programming languages, the function signature is as follows:

- **Java:**
  ```java
  Node detectCycle(Node head);

- **C++**
  ```C++
  Node* detectCycle(Node* head);

- **Python**
  ```Python
  def detectCycle(head):

### Constraints:
1 ≤ T ≤ 10  
1 ≤ N ≤ 10^5  
1 ≤ Ai ≤ 10^9

### Sample Input:
3  
2  
8 5  
1  
2  
5 9  
1  
3  
5 6 8  
2

### Sample Output:
8  
5  
6

### Explanation:
**Test Case 1:** The list is of the form 8 ⇌ 5, where 8 is the head. Thus, the cycle starts from 8.  
**Test Case 2:** The list is of the form 5 ⇌ 9, where 5 is the head. Thus, the cycle starts from 5.  
**Test Case 3:** The list is of the form 5 → 6 ⇌ 8, where 5 is the head. Thus, the cycle starts from 6.

