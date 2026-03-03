#include <iostream>

using namespace std;

void isSubstring(const string &str1, const string &str2) {
    if (str1.find(str2) != string::npos) {
        cout << "FOUND"<< endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

int main() {
    isSubstring("We like UW-Stout", "UW-Stout");
    isSubstring("We like UW-Stout", "UW-Madison");
    isSubstring("myEXEprogram >txt", ">");

    return 0;
}