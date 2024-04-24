// My solution
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> pairSum(vector<int>& arr, int s) {
    vector<vector<int>> pairs;
    for (int i = 0; i < arr.size(); i++) {
        for (int k = i + 1; k < arr.size(); k++) {
            if (arr[i] + arr[k] == s) {
                vector<int> pair = { min(arr[i], arr[k]), max(arr[i], arr[k]) };
                pairs.push_back(pair);
            }
        }
    }

    // Sort pairs according to the required criteria
    sort(pairs.begin(), pairs.end());

    return pairs;
}

