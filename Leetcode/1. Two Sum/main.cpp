class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int k = 1; k < nums.size(); k++) {
                if (i == k) {
                    continue;
                }
                if (nums.at(i) + nums.at(k) == target) {
                    result.push_back(i);
                    result.push_back(k);
                    return result;

                }
            }
        }
        return result;
    }
};