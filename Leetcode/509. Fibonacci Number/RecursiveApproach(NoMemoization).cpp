/*
* Recursive Approach (No Memoization)

    Description:
    This method uses a straightforward recursive formula but does not store intermediate results. 
    It recomputes values multiple times, leading to exponential time complexity.

    Time Complexity: O(2n)O(2^n)O(2n)

    Space Complexity: O(n)O(n)O(n) (due to recursion stack)
*/
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};