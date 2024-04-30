# Problem statement
Given 3 Strings, check whether the 3rd string contains all the characters of string 1 and 2 in any order. If all the characters are present, print "YES" otherwise print "NO".  
There should not be any extra character and any missing character.  
The string s contains uppercase Latin letters only.

## Detailed explanation (Input/output format, Notes, Images)
### Input format:
Line 1: First String  
Line 2: Second String  
Line 3: Third String
### Output format:
YES or NO

## Constraints :
1 <= n (Length of 1st & 2nd Strings) <= 100

## Sample Input 1 :
SANTACLAUS  
DEDMOROZ  
SANTAMOROZDEDCLAUS
## Sample Output 1 :
YES  

## Sample Input 2 :
PAPAINOEL  
JOULUPUKKI  
JOULNAPAOILELUPUKKI

## Sample Output 2 :
NO
## Sample Input 3 :
BABBONATALE  
FATHERCHRISTMAS  
BABCHRISTMASBONATALLEFATHER  
## Sample Output 3 :
NO

## Sample Output Explanation :
Output 1 : the letters written in the last line can be used to write the names and there won't be any extra letters left.  
Output 2 : Letter "P" is missing and there's an extra letter "L"  
Output 3 : There's an extra letter "L"  
