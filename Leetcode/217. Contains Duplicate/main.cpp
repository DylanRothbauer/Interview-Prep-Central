class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> set;
        std::set<int>::iterator itr;

        for (int i = 0; i < nums.size(); i++) {
            itr = set.find(nums[i]);
            if (itr == set.end()) { // It did not find it
                set.insert(nums[i]);
            }
            else {
                return true;
            }
        }
        return false;
    }
};