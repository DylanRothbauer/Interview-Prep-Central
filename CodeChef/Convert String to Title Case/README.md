# Convert String to Title Case
Given a string S consisting of only lowercase and uppercase English letters and spaces, your task is to convert it into title case. In title case, the first letter of each word is capitalized while the rest are in lowercase, except for words that are entirely in uppercase (considered as acronyms), which should remain unchanged.  
Note:  
•	Words are defined as contiguous sequences of English letters separated by spaces.  
•	Acronyms are words that are entirely in uppercase and should remain unchanged.  
•	Assume the input does not contain leading, trailing, or multiple spaces between words.  
## Input Format
•	The first line contains a single integer T, the number of test cases.  
•	Each of the next T lines contains a string S.  
## Output Format
For each test case, print a single line containing the string S converted into title case.
## Constraints
•	1≤T≤100  
•	1≤∣S∣≤1000, where ∣S∣ is the length of the string.  
## Sample 1:
### Input
5  
hello world  
this is a CODECHEF problem  
WELCOME to the JUNGLE  
the quick BROWN fOx  
programming in PYTHON  

### Output
Hello World  
This Is A CODECHEF Problem  
WELCOME To The JUNGLE  
The Quick BROWN Fox  
Programming In PYTHON  
## Explanation:
•	In the first test case, each word is capitalized as they are not acronyms.  
•	In the second test case, "CODECHEF" is an acronym and remains in uppercase.  
•	In the third test case, "WELCOME" and "JUNGLE" are considered acronyms.  
•	In the fourth test case, "BROWN" is an acronym, while the rest of the words follow the title case rule.  
•	In the fifth test case, "PYTHON" is an acronym, and the rest of the string is converted to title case.  

