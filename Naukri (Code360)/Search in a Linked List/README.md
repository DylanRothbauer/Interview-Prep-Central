# Problem statement
You are given a Singly Linked List of integers with a head pointer. Every node of the Linked List has a value written on it.  

A sample Linked List:  
![Sample 1](https://github.com/DylanRothbauer/Interview-Prep-Central/blob/abc3a58eea97523d02a0198147f1ac43f7cc573e/Naukri%20(Code360)/Search%20in%20a%20Linked%20List/LinkedList_1.png)

Now you have been given an integer value, 'K'. Your task is to check whether a node with a value equal to 'K' exists in the given linked list. Return 1 if node exists else return 0.

## Detailed explanation (Input/output format, Notes, Images)


## Sample Input 1:
3 6 2 7 9 -1  
2
## Sample Output 1:
1

## Explanation for Sample Input 1:
As value 2 exists in the given linked list. So we will return 1 in this case.  
![Sample 2](https://github.com/DylanRothbauer/Interview-Prep-Central/blob/42bb35592c5228aabd949e3cbb0e1539ac988fc8/Naukri%20(Code360)/Search%20in%20a%20Linked%20List/LinkedList_2.png)

## Sample Input 2:
1 2 3 7 -1  
7
## Sample Output 2:
1

## Explanation for Sample Input 2:
As the value 7 exists in the Linked List, our answer is 1.  
![Sample 3](https://github.com/DylanRothbauer/Interview-Prep-Central/blob/abc3a58eea97523d02a0198147f1ac43f7cc573e/Naukri%20(Code360)/Search%20in%20a%20Linked%20List/LinkedList_1.png)

**Expected Time Complexity**:  
Try solving this in O(L).

## Constraints:
1 <= 'L' <= 10^5  
1 <= 'data' <= 10^9 and 'data' != -1  
1 <= 'K' <= 10^9  
Where 'L' represents the total number of nodes in the Linked List, 'data' represents the value at each node, and 'K' is the given integer.  
Time Limit: 1 sec.
