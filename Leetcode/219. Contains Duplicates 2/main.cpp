class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // I used a set before, but that was wrong because I was comparing
        // the values, not the indices

        std::unordered_map<int, int> num_map; // Stores the number and its last index

        for (int i = 0; i < nums.size(); i++) {
            if (num_map.find(nums[i]) != num_map.end()) {
                // Check if the absolute difference between indices is <= k
                if (i - num_map[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the last index of the current number
            num_map[nums[i]] = i;
        }

        return false;
    }
};
