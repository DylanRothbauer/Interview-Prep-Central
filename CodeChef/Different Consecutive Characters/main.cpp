#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T; // # of test cases
	int N; // length of the binary string S
	string S;

	cin >> T;
	while (T > 0) {
		int counter = 0;
		cin >> N;
		cin >> S;

		for (int i = 0; i < S.length() - 1; i++) {
			if (S.at(i + 1) == S.at(i)) {
				counter++;
			}
		}
		cout << counter << endl;
		T--;
	}

}
