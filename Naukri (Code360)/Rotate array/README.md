# Problem statement
Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.  

## Example:
'arr '= [1,2,3,4,5]  
'k' = 1  rotated array = [2,3,4,5,1]  
'k' = 2  rotated array = [3,4,5,1,2]  
'k' = 3  rotated array = [4,5,1,2,3] and so on.

## Detailed explanation ( Input/output format, Notes, Images )
### Input format:
The first line contains an integer 'n' representing the size of the array.  
The second line contains 'n' space-separated integgers representing the elements of the array.  
The last line contains an integer 'k' representing the number of times the array has to be rotated in the left direction.

### Output format:
The output contains 'n' space-separated integers representing the Rotated array elements.  
**Note**:  
You don't need to print anything. Just implement the given function.

## Sample Input 1:
8  
7 5 2 11 2 43 1 1  
2
## Sample Output 1:
2 11 2 43 1 1 7 5  

**Explanation of Sample Input 1**:  
Rotate 1 steps to the left: 5 2 11 2 43 1 1 7  
Rotate 2 steps to the left: 2 11 2 43 1 1 7 5  

## Sample Input 2:
4  
5 6 7 8  
3  
## Sample Output 2:
8 5 6 7  

**Explanation of Sample Input 2**:  
Rotate 1 steps to the left: 6 7 8 5  
Rotate 2 steps to the left: 7 8 5 6  
Rotate 2 steps to the left: 8 5 6 7  

**Expected Time Complexity**:  
O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.

## Constraints:
1 <= 'n' <= 10^3  
1 <= 'arr'[i] <= 10^9  
1 <= 'k' < 'n'

## Hints:
1. For an index ‘i’, find where it lands after k swaps.  
2. When performing rotation once observe how the positions of all elements change.
