//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string dna(string s) {
    // I could have passed in n for the length,
    // but I can just do s.length
    string concat = "";

    for (int i = 0; i < s.length(); i += 2) {
        if (s.at(i) == '0' && s.at(i + 1) == '0') {
            concat += "A";
        }
        else if (s.at(i) == '0' && s.at(i + 1) == '1') {
            concat += 'T';
        }
        else if (s.at(i) == '1' && s.at(i + 1) == '0') {
            concat += 'C';
        }
        else if (s.at(i) == '1' and s.at(i + 1) == '1') {
            concat += 'G';
        }
    }

    return concat;
}

int main() {
    // your code goes here
    int t; // number of test cases

    cin >> t;
    while (t > 0) {
        int n; // length of the sequence
        cin >> n;
        string s;
        cin >> s; // string

        string result = dna(s);
        cout << result << endl;

        t--;
    }
    return 0;

}
