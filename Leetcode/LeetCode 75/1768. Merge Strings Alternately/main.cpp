class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int k = 0;
        int counter = 0;
        string answer = "";
        int maxLength = max(word1.length(), word2.length());

        while (counter <= maxLength) {
            if (i < word1.length()) {
                answer += word1[i];
            }

            if (k < word2.length()) {
                answer += word2[k];
            }
            counter++;
            i++;
            k++;
        }
        return answer;
    }
};