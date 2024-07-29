class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        string longestSubStr = strs.at(0);
        int length = longestSubStr.length();

        for (int i = 1; i < strs.size(); i++) {
            while (strs.at(i).substr(0, length) != longestSubStr) {
                if (longestSubStr.size() < 0) {
                    return "";
                }

                longestSubStr.pop_back();
                length--;
            }
        }
        return longestSubStr;

    }
};