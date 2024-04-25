#include <bits/stdc++.h>

int findDuplicate(vector<int>& arr, int n) {
	// Write your code here.
	sort(arr.begin(), arr.end()); // O(N log N)

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == arr[i + 1]) {
			return arr[i];
		}
	}
}
