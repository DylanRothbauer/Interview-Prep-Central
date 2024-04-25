# Add One
You are given a large number N. You need to print the number N+1.  
Note: The number is very large and it will not fit in standard integer data type. You have to take the input as String and then manipulate the digits to convert it to N+1.
## Input Format
•	The first line of the input contains a single integer T - the number of test cases. The description of T test cases follows.
•	The first line of each test case contains a single integer N.
## Output Format
•	For each test case, print a single line containing one integer - the number N+1.
## Constraints
•	1≤T≤100  
•	1≤N≤10^(200000)−1  
•	the sum of the number of digits of all N in a single test file does not exceed 4⋅10^5
## Subtasks
### Subtask #1 (30 points): each digit of the number N is at most 8
### Subtask #2 (70 points): original constraints
## Sample 1:
### Input
6  
99  
17  
1  
599  
10000000000000000000  
549843954323494990404  

### Output
100  
18  
2  
600  
10000000000000000001  
549843954323494990405  
## Explanation:
**Example case 1**: N=99 so N+1=100.  
**Example case 2**: N=17 so N+1=18.  
**Example case 3**: N=1 so N+1=2.  
**Example case 4**: N=599 so N+1=600.  
**Example case 5**: N=10000000000000000000 so N+1=10000000000000000001.  
**Example case 6**: N=549843954323494990404 so N+1=549843954323494990405.  

