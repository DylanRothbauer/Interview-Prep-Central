class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create unordered sets to store unique elements from nums1 and nums2
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // Initialize vectors to store results
        vector<int> uniqueToNums1;
        vector<int> uniqueToNums2;
        vector<vector<int>> answer;

        // Find elements in set1 that are not in set2
        for (const int& num : set1) {
            if (set2.find(num) == set2.end()) {
                uniqueToNums1.push_back(num);
            }
        }

        // Find elements in set2 that are not in set1
        for (const int& num : set2) {
            if (set1.find(num) == set1.end()) {
                uniqueToNums2.push_back(num);
            }
        }

        // Return the result as a vector of vectors
        answer.push_back(uniqueToNums1);
        answer.push_back(uniqueToNums2);
        return answer;
    }
};