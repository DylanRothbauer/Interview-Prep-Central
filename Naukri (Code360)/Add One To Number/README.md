# Problem statement
Given a non-negative number represented as an array of digits, you have to add 1 to the number, i.e, increment the given number by one.  
The digits are stored such that the most significant digit is at the starting of the array and the least significant digit is at the end of the array.  

**For Example**  
If the given array is {1,5,2}, the returned array should be {1,5,3}.  

## Note 
Input array can contain leading zeros, but the output array should not contain any leading zeros (even if the input array contains leading zeroes).  
**For Example**:  
If the given array is {0,2}, the returned array should be {3}.

## Detailed explanation (Input/output format, Notes, Images)
### Input format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run.  
The first line of each test case contains a positive integer N, which represents the number of digits in the given number/array.  
The next line contains 'N' single space-separeed positive integers representing the elements of the array.
### Output format:
For each test case, print the final number.  
Print the output of each test case in a separate line.  
**Note**  
You do not need to print anything, it has already been taken care of. Just implement the given function.

## Constraints
1 <= T <= 10  
1 <= N <= 5 * 10^4  
0 <= Arr[i] <= 9  

Where Arr[i] is the i-th digit in the number.

## Sample Input 1
3  
3  
1 2 3  
2  
9 9  
1  
4
## Sample Output 1
1 2 4  
1 0 0  
5  
## Explanation For Sample Input 1
In the 1st test case, the number is 123 after adding 1 number becomes 124, hence the output will be {1,2,4}.  
In the 2nd test case, the number is 99 after adding 1 number becomes 100, hence the output will be {1,0,0}.  
In the 3rd test case, the number is 4 after adding 1 number becomes 5, hence the output will be {5}.  

## Sample Input 2
3  
4  
2 4 6 8   
1  
0  
2  
0 2  
## Sample Output 2
2 4 6 9  
1  
3  
