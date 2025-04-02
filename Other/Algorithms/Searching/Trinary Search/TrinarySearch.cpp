#include <iostream>
#include <vector>

using namespace std;

/*
* Trinary Search
*/
int trinarySearch(vector<int>& vec, int target) {
    int count = 0; // using a counter for steps
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int oneThird = left + (right - left) / 3;
        int twoThirds = right - (right - left) / 3;
        count += 2;
        if (vec[oneThird] == target) {
            cout << "TRINARY SEARCH STEPS: " << count << endl;
            return oneThird;
        }
        else if (vec[twoThirds] == target) {
            cout << "TRINARY SEARCH STEPS: " << count << endl;
            return twoThirds;
        }
        else if (target < vec[oneThird]) {
            right = oneThird - 1;
        }
        else if (target > vec[twoThirds]) {
            left = twoThirds + 1;
        }
        else {
            left = oneThird + 1;
            right = twoThirds - 1;
        }
    }
    cout << "TRINARY SEARCH STEPS: " << count << endl;
    return -1;  // not found
}