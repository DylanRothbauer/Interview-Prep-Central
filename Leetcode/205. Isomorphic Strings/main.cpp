class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (int i = 0; i < s.size(); i++) {
            // Check if chars in map
            if (sMap.find(s[i]) == sMap.end()) { // Didn't find it
                sMap[s[i]] = i;
            }

            if (tMap.find(t[i]) == tMap.end()) {
                tMap[t[i]] = i;
            }

            // Check if indices are the same
            if (sMap[s[i]] != tMap[t[i]]) {
                return false;
            }
        }

        return true;
    }
};