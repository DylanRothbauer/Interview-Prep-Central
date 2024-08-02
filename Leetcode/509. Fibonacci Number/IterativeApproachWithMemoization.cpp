/*
* Iterative Approach with Memoization
    Description:
    Although not a common use case for memoization in iterative solutions (as it's usually more relevant in recursive solutions), 
    this approach involves maintaining a list to store Fibonacci numbers up to n.

    Time Complexity: O(n)O(n)O(n)

    Space Complexity: O(n)O(n)O(n) (for memoization storage)
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> fibMemo(n + 1);
        fibMemo[0] = 0;
        fibMemo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fibMemo[i] = fibMemo[i - 1] + fibMemo[i - 2];
        }
        return fibMemo[n];
    }
};