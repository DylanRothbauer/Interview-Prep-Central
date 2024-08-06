class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        bool hasMore;

        for (int i = 0; i < candies.size(); i++) {
            for (int k = 0; k < candies.size(); k++) {
                if (candies[i] + extraCandies >= candies[k]) {
                    hasMore = true;
                }
                else {
                    hasMore = false;
                    break;
                }
            }
            result.push_back(hasMore);
        }
        return result;
    }
};