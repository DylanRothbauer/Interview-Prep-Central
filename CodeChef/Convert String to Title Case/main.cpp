/*
* Split the input string into individual words based on spaces.
* For each word:
*   Check if it is entirely in uppercase. If yes, it’s an acronym, so keep it unchanged.
*   If not, capitalize the first letter and convert the rest of the letters to lowercase.
* Join all the modified words back together into a single string with spaces between them.
* Output the resulting title case string.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype> // For isupper and tolower

using namespace std;

string to_title_case(const string& s) {
    istringstream iss(s);
    string word, title_case;
    while (iss >> word) {
        // Check if the word is an acronym (all uppercase)
        bool isAcronym = true;
        for (char c : word) {
            if (!isupper(c)) {
                isAcronym = false;
                break;
            }
        }

        if (isAcronym) {
            title_case += word + " ";
        }
        else {
            // Capitalize the first letter of the word
            word[0] = toupper(word[0]);
            // Convert the rest of the word to lowercase
            for (size_t i = 1; i < word.length(); ++i) {
                word[i] = tolower(word[i]);
            }
            title_case += word + " ";
        }
    }
    // Remove the last extra space
    if (!title_case.empty()) title_case.pop_back();
    return title_case;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input

    for (int i = 0; i < t; ++i) {
        string s;
        getline(cin, s); // Use getline to read a line of text
        cout << to_title_case(s) << endl;
    }

    return 0;
}
