class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> uniqueNums;

        for (int i = 0; i < nums.size(); i++) {
            if (uniqueNums.find(nums[i]) != uniqueNums.end()) { // Found
                return true;
            }

            uniqueNums.insert(nums[i]);
        }
        return false;
    }
};
