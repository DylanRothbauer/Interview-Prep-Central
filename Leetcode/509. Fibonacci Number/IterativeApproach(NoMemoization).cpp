/*
* Iterative Approach (No Memoization)

    Description:
    This method uses a loop to iteratively compute Fibonacci numbers up to n, using only a few variables to store intermediate results.

    Time Complexity: O(n)O(n)O(n)

    Space Complexity: O(1)O(1)O(1) (constant space for variables)
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};