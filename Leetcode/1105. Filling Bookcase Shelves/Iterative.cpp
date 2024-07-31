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