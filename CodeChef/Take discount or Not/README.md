# Take discount or Not
There are 𝑁 items in a shop. You know that the price of the 𝑖-th item is 𝐴𝑖. Chef wants to buy all the 𝑁 items.  
There is also a discount coupon that costs 𝑋 rupees and reduces the cost of every item by 𝑌 rupees. If the price of an item was initially ≤𝑌, it becomes free, i.e, costs 00.  
Determine whether Chef should buy the discount coupon or not. Chef will buy the discount coupon if and only if the total price he pays after buying the discount coupon is strictly less than the price he pays without buying the discount coupon.  

**Input Format**  
•	The first line of input will contain a single integer 𝑇, denoting the number of test cases. The description of the test cases follows.  
•	Each test case consists of two lines of input.  
- The first line of the test case contains three space-separated integers — 𝑁, 𝑋, and 𝑌.
- The second line contains 𝑁 space-separated integers — 𝐴1,𝐴2,…,𝐴𝑁.  

**Output Format**  
•	For each test case, output COUPON if Chef should buy the discount coupon, and NO COUPON otherwise.  
Each letter of the output may be printed in either lowercase or uppercase. For example, the strings coupon, CouPoN, and COUPON will all be treated as equivalent.
## Constraints
•	1≤𝑇≤1000  
•	1≤𝑁≤100  
•	1≤𝑋,𝑌≤10^5  
•	1≤𝐴𝑖≤10^5  
## Sample 1:
### Input
5  
4 30 10  
15 8 22 6  
4 40 10  
15 8 22 6  
4 34 10  
15 8 22 6  
2 10 100  
60 80  
3 30 5  
50 60 50  
### Output
COUPON  
NO COUPON  
NO COUPON  
COUPON  
NO COUPON
## Explanation:
**Test case 1**: The original cost of the items is 15+8+22+6=51. Buying the coupon costs 30, and after buying it the cost of buying all the items is 5+0+12+0=175+0+12+0=17. The total cost of buying everything with the coupon is 30+17=47, which is strictly less than 51. So, Chef will buy the coupon.  

**Test case 2**: The original cost of the items is 15+8+22+6=51. Buying the coupon costs 40, and after buying it the cost of buying all the items is 5+0+12+0=17. The total cost of buying everything with the coupon is 40+17=57, which is more than 51. So, Chef will not buy the coupon.  

**Test case 3**: The original cost of the items is 51. Buying the coupon costs 34, and the cost of buying all the items after using it is 17, making the total cost 34+17=51. Since this is not strictly less than the original cost, Chef won't buy the coupon.  

**Test case 4**: The original cost of the items is 140, the coupon costs 10, and the cost of buying everything after using the coupon is 0. Since 10+0<140, Chef will buy the coupon.

