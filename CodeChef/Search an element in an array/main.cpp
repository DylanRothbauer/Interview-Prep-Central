// Used binary search to find target element
// Could have just did a linear search for 0(n) 
#include <vector>
using namespace std;

void BinarySearch(vector<int>& arr, int target) { // 0 (log N)
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target) {
            cout << "YES" << endl;
            return;
        }

        if (arr[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int N; // size of array
    int X; // element to be searched
    vector<int> arr;

    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end()); // O(N log N)
    BinarySearch(arr, X);

    return 0;
}