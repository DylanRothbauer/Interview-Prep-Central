# Problem statement
You are given two strings 'STR1' and 'STR2'. You need to tell whether the strings are meta strings or not.  
Meta strings are strings that can be made equal by swapping exactly one pair of distinct characters in one of the strings.  

**Note**:  
Equal strings are not considered as meta strings.

## Detailed explanation (Input/output format, Notes, Images)
### Input format:
The first line of input contains an integer 'T' denoting the number of test cases or queries to be run.  
The first line of each test case or query contains the first string "STR1".  
The second line of the test case or query contains the second string "STR2".
### Output format:
For each test case, print a single line containing "YES" if the strings are meta strings otherwise, "NO".  
The output of each test case will be printed in a separate line.  
**Note**:  
You do not need to print anything; it has already been taken care of. Just implement the given function.

## Constraints:
1 <= T <= 10  
2 <= length of STR1<= 10 ^ 5  
2 <= length of STR2 <= 10 ^ 5

## Sample Input 1:
2  
Coding  
Codnig  
Ninjas  
Niaxns  
## Sample Output 1:
YES  
NO  
## Explanation for Input 1:
For test case 1: By swapping ‘i’ and ‘n’ in the second string, it becomes equal to the first string.  
For test case 2: There is no way we can make both the strings equals by swapping one pair of characters.

## Sample Input 2:
3  
Hello  
Hello  
Play  
Playes  
Seek  
Seke  
## Sample Output 2:
NO  
NO  
YES
