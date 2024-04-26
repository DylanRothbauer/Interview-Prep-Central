#include <iostream>
#include <array>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int size = arr.size();
    vector<int> result;

    int holder[size];
    for (int i = 0; i < size; i++) {
        if (i - k < 0) { // Check if it needs to wrap to the end
            holder[size + (i - k)] = arr.at(i);
        }
        else { // Otherwise, we can just set new position
            holder[i - k] = arr.at(i);
        }
    }

    for (int i = 0; i < size; i++) { // For return
        result.push_back(holder[i]);
    }

    return result;
}
