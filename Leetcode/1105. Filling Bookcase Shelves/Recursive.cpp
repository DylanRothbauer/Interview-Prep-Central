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