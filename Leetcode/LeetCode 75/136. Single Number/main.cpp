class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Not constant space - not using bitwise XOR operator
        set<int> mySet;
        set<int>::iterator it;

        for (int i = 0; i < nums.size(); i++) {
            it = mySet.find(nums[i]);
            if (it != mySet.end()) { // found value
                mySet.erase(it);
            }
            else { // Otherwise, add to set
                mySet.insert(nums[i]);
            }
        }
        it = mySet.begin();
        return *it;
    }
};