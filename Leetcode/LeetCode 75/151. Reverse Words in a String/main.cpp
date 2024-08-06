class Solution {
public:
    string reverseWords(string s) {
        vector<string> storage;
        istringstream iss(s);

        do {
            string word;
            iss >> word;
            storage.push_back(word);
        } while (iss);

        reverse(storage.begin(), storage.end());

        string result = "";
        for (int i = 0; i < storage.size(); i++) {
            result += storage[i];
            if (i == 0 || i == storage.size() - 1) {
                continue;
            }
            result += " ";
        }
        return result;
    }
};