#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int m) {
    // Write your code here
    reverse(arr.begin() + m + 1, arr.end()); // after m

}