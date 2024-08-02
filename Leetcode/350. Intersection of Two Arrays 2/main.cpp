class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            for (int k = 0; k < nums2.size(); k++) {
                if (nums1[i] == nums2[k]) {
                    result.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + k);
                    break;
                }
            }
        }
        return result;
    }
};