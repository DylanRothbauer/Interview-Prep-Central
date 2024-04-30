# Problem statement
You're given an alphabetical string ‘S’.  
Determine whether it is palindrome or not. A palindrome is a string that is equal to itself upon reversing it.

## For example:
‘S’ = racecar  
The reverse of ‘S’ is: racecar  
Since ‘S’ is equal to its reverse. So ‘S’ is a palindrome.  
Hence output will be 1.  
## Detailed explanation (Input/output format, Notes, Images)
### Input format:
The first line of the input contains a single integer 'T' representing the no. of test cases.  
The first line of each test case contains a single alphabetical string, 'S'.
### Output format:
For each test case, print a single integer value 1 if the given string 'S' is palindrome and 0 otherwise.  
Print a separate line for each test case.  
**Note**:  
You are not required to print anything; it has already been taken care of. Just implement the function and return the answer.

## Constraints
1 <= T <= 1000  
1 <= |S| <= 10^5  
S consits of only lowercase english alphabets  
Time limit: 1 sec

## Sample Input 1 :
2  
racecar  
niinja  
## Sample Output 1 :
1  
0

## Explanation For Sample Input 1 :
For First Case - Same as explained in above example.  
For the second case -  
‘S’ = niinja  
Reverse of ‘S’ is: ajniin  
Since ‘S’ is not equal to its reverse. So ‘S’ is not a palindrome.  
Hence output will be 0.  

## Sample Input 2 :
2  
level  
panama  

## Sample Output 2 :
1  
0  
