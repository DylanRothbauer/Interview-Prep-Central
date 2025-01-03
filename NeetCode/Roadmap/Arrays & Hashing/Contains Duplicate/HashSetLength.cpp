/*
* Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};