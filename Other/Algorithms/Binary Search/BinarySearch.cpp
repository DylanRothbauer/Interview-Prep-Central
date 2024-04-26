
#include <iostream>
#include <vector>

using namespace std;

/*
* Binary Search
*/
int binarySearch(vector<int>& vec, int target) {
    int count = 0; // using a counter for steps
    int left = 0; // at the start of the vector
    int right = vec.size() - 1; // at the end of the vector

    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++;
        if (vec[mid] == target) {
            cout << "BINARY SEARCH STEPS: " << count << endl;
            return mid;
        }
        else if (vec[mid] < target) { // left becomes mid + 1 (because we already checked if mid was the target
            left = mid + 1;
        }
        else { // otherwise, the right becomes mid - 1
            right = mid - 1;
        }
    }
    cout << "BINARY SEARCH STEPS: " << count << endl;
    return -1;  // target not found
}