/*
* Dynamic Programming with Iterative:

    Approach and Structure
    - Uses a bottom-up approach.
    - Iteratively computes the solution by filling up a DP table (dp), where each entry represents the minimum height needed for the books up to a certain index.
    - The solution is built from smaller subproblems to larger ones, ensuring that all possible configurations are considered in an iterative manner

    Implementation Details
    - DP Table: Uses a single DP table (dp[i]) where dp[i] represents the minimum height required for the first i books.
    - Nested Loops: Iterates through each book and tries placing different books on the same shelf, updating the dp array based on the best possible configuration.
    - Complexity: Time complexity is O(n^2) because each book placement involves a nested loop over previous books.

    Flexibility and Usage
    - Iterative Approach: Can be easier to understand and implement for some problems, especially when the solution naturally fits into an iterative pattern.
    - Space Complexity: Uses additional space proportional to the number of books, but does not involve recursive stack space.

    Summary
    - Builds the solution from base cases up to the final solution.
    - May be more straightforward for problems that involve iterative state transitions.
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] will store the minimum height for first i books
        dp[0] = 0; // No books, no height needed
        // Iterate over each book
        for (int i = 0; i < n; i++) {
            int currentWidth = 0;
            int maxHeight = 0;
            // Try placing books from the current book to the previous books within the shelf width
            for (int j = i; j >= 0; j--) {
                currentWidth += books[j][0]; // Add the width of the current book
                if (currentWidth > shelfWidth) {
                    break; // No space left for the current book on this shelf
                }
                maxHeight = max(maxHeight, books[j][1]); // Update the height of the current shelf
                // Update dp[i + 1] with the minimum height possible
                dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight);
            }
        }
        return dp[n]; // The minimum height required to arrange all books
    }
};