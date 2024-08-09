class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int k = i + 1; k < nums.size(); k++) {
                if (nums[k] != 0 && nums[i] == 0) {
                    swap(nums[i], nums[k]);
                    break;
                }
            }
        }
    }
};