/*
Step 1: Build the frequency map from magazine.
Step 2: For each letter in ransomNote, decrease the corresponding frequency from the map.
Step 3: If any letter in ransomNote has a frequency greater than what's available in magazine, return false.
Step 4: If all letters are found with sufficient frequency, return true.

Time Complexity
Time: O(m + n), where m is the length of magazine and n is the length of ransomNote.
Space: O(1), since the map size is limited to the number of possible letters (at most 26 for lowercase English letters).
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map; // key and freqency
        // std::unordered_map<char,int>::iterator itr;

        for (int i = 0; i < magazine.size(); i++) { // Populating map
            map[magazine[i]]++; // Increase frequency
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (map[ransomNote[i]] > 0) {
                map[ransomNote[i]]--; // decriment frequency
            }
            else {
                return false;
            }
        }

        return true;
    }
};