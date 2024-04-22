#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int T;
	int N;
	vector<int> input;

	cin >> T;

	while (T > 0) {
		cin >> N;
		while (N > 0) {
			int temp;
			cin >> temp;
			input.push_back(temp);
			N--;
		}
		sort(input.begin(), input.end()); // O(N log N)
		cout << input.at(input.size() - 1) << endl; // O(1)
		input.clear();
		T--;
	}
	return 0;
}
