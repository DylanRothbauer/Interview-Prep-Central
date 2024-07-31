/*
* Recursive with memorization:

    Approach and Structure
    - Uses a top-down approach.
    - Recursively solves the problem by breaking it down into smaller subproblems and storing the results to avoid redundant calculations.
    - Starts with the initial problem and recursively solves smaller subproblems, using memorization to cache and reuse previously computed results.

    Implementation Details
    - Memoization Table: Uses a memoization table (dp[i]) to store results of subproblems where dp[i] represents the minimum height needed starting from index i.
    - Recursive Calls: The function helper is called recursively to compute the minimum height for remaining books, and memoization is used to cache results of previously solved subproblems.
    - Complexity: Time complexity can be similar to the iterative approach, but it depends on the number of unique subproblems that need to be solved. Memoization helps in reducing redundant calculations
    
    Flexibility and Usage
    - Recursive Approach: Can be more intuitive for problems that naturally fit a recursive decomposition.
    - Space Complexity: Includes both the space for the DP table and the recursive call stack, which could be significant for deep recursion.
    
    Summary
    - Solves the problem using recursion and caches intermediate results.
    - Can be more intuitive for problems that decompose naturally into recursive subproblems.
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1); // Initialize dp vector with -1 to indicate uncomputed states

        return helper(0, books, shelfWidth, dp);
    }

private:
    int helper(int i, const vector<vector<int>>& books, int shelfWidth, vector<int>& dp) {
        if (i >= books.size()) { // If we've placed all books
            return 0;
        }

        if (dp[i] != -1) { // If result is already computed
            return dp[i];
        }

        int currentWidth = 0;
        int maxHeight = 0;
        int result = INT_MAX;

        // Try placing books from index `i` onward on the current shelf
        for (int j = i; j < books.size(); ++j) {
            int bookWidth = books[j][0];
            int bookHeight = books[j][1];

            if (currentWidth + bookWidth > shelfWidth) {
                break;  // No more space for the current book on this shelf
            }

            currentWidth += bookWidth;  // Update the width of the current shelf
            maxHeight = max(maxHeight, bookHeight);  // Update the height of the current shelf

            // Recursively calculate the minimum height if placing books from `j + 1`
            result = min(result, helper(j + 1, books, shelfWidth, dp) + maxHeight);
        }

        dp[i] = result;  // Store the result in the memoization table
        return result;
    }
};