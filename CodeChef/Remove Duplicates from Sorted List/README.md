# Remove Duplicates from Sorted List

You are given the head of a non-empty sorted linked list where the value of the i-th node will be `Ai`. 

Your task is to delete all duplicates such that each element appears only once and return the linked list sorted.

## Input:
- The first line will contain `T`, the number of test cases. 
- For each test case, the first line contains one integer `N` — the length of the linked list. 
- The second line contains `N` space-separated integers `A1, A2, ..., AN` — the values of the linked list nodes starting from the head.

### Note:

- For Java language, you need to:  
  Complete the function in the submit solution tab:  
  Node removeDuplicates(Node head){...}
 
 
- For C++ language, you need to:  
  Complete the function in the submit solution tab:  
  Node* removeDuplicates(Node* head){...}

 
- For Python language, you need to:  
  Complete the function in the submit solution tab:  
  def Node removeDuplicates(self, head):

## Output:
The function you complete should return the required answer.

# Constraints
1 ≤ T ≤ 10  
1 ≤ N, A<sub>i</sub> ≤ 10<sup>5</sup>


## Sample 1:

### Input:
3  
5  
1 1 6 8 8  
5  
1 2 3 4 5  
4  
5 5 5 5

### Output:
1 6 8   
1 2 3 4 5   
5

### Explanation:
- **Test case 1:** We will remove the duplicate entries `1` and `8`. The sorted linked list will be `1 → 6 → 8`.
- **Test case 2:** There are no duplicate entries. The sorted linked list remains `1 → 2 → 3 → 4 → 5`.
- **Test case 3:** We will remove the duplicate entries of `5`. The sorted linked list will be `5`.
