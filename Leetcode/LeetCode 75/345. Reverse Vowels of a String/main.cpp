class Solution {
public:
    string reverseVowels(string s) {
        // two pointers to swap vowels in space
        int k = s.length() - 1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                while (k >= 0 &&
                    (s[k] != 'a' && s[k] != 'e' && s[k] != 'i' &&
                        s[k] != 'o' && s[k] != 'u') &&
                    s[k] != 'A' && s[k] != 'E' && s[k] != 'I' &&
                    s[k] != 'O' && s[k] != 'U') {
                    k--;
                }
                if (i < k) { // To ensure k does a valid swap and doesnt go past
                    // our i
                    swap(s[i], s[k]);
                    k--;
                }
            }
        }
        return s;
    }
};