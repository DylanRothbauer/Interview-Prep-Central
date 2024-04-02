#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string ChefWordle(string S, string T) {
	// both ar length 5 always
	string M = "";
	for (int i = 0; i < 5; i++) {
		if (S.at(i) == T.at(i)) {
			M += "G";
		}
		else {
			M += "B";
		}
	}
	return M;
}

int main() {
	// your code goes here

	int numberOfTest;
	string S; // the hidden word
	string T; // the guess word

	cin >> numberOfTest;
	while (numberOfTest > 0) {
		cin >> S;
		cin >> T;
		string result = ChefWordle(S, T);
		cout << result << endl;
		numberOfTest--;
	}

}
