/*
* Recursive Approach with Memoization
    Description:
    This method stores previously computed values to avoid redundant calculations, improving efficiency significantly.

    Time Complexity: O(n)O(n)O(n)

    Space Complexity: O(n)O(n)O(n) (for memoization storage and recursion stack)
*/

class Solution {
public:
    int fib(int n) {
        vector<int> fibMemo(n + 1, -1);
        return fibHelper(n, fibMemo);
    }

private:
    int fibHelper(int n, vector<int>& fibMemo) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (fibMemo[n] != -1) return fibMemo[n];
        fibMemo[n] = fibHelper(n - 1, fibMemo) + fibHelper(n - 2, fibMemo);
        return fibMemo[n];
    }
};