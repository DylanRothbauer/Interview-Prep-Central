#include <cstdlib>
#include <unordered_map>

using namespace std;

void answer(string s1, string s2, string s) {

    unordered_map<char, int> freq;

    // Count frequency of characters in s1 and s2
    for (char c : s1) {
        freq[c]++;
    }
    for (char c : s2) {
        freq[c]++;
    }

    // Check if characters in s3 match with frequencies in the map
    for (char c : s) {
        if (freq.find(c) == freq.end() || freq[c] == 0) {
            cout << "NO" << endl;
            return;
        }
        freq[c]--;
    }

    // Check if all frequencies are zero
    for (auto it : freq) {
        if (it.second != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

    return;
}
