#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        string input = to_string(x);
        int k = input.length();

        for (int i = 0; i < k; i++) {
            if (input.at(i) == input.at(k - 1)) {
                k--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};