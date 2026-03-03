#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Counting Sort
void countingSort(std::vector<int>& arr) {
    int n = arr.size();

    // 1. Find the maximum element to determine the range
    int max_val = *std::max_element(arr.begin(), arr.end());

    // 2. Create a count array of size max_val + 1 and initialize with zeros
    // The index represents the value, and the value at the index represents its count
    std::vector<int> count(max_val + 1, 0);

    // 3. Store the count of each element
    for (int num : arr) {
        count[num]++;
    }

    // 4. Calculate the cumulative count (prefix sum)
    // This helps in placing elements in their correct sorted positions
    for (int i = 1; i <= max_val; ++i) {
        count[i] += count[i - 1];
    }

    // 5. Build the output array using the cumulative count
    // Traverse the input array from right to left to ensure stability
    std::vector<int> output(n);
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--; // Decrease count after placing the element
    }

    // 6. Copy the sorted elements from output[] to original array arr[]
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}


// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    // Random pivot (prevents worst case)
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];

    int lt = low;      // < pivot
    int i  = low;      // current
    int gt = high;     // > pivot

    // 3-way partition
    while (i <= gt) {
        if (arr[i] < pivot)
            swap(arr[lt++], arr[i++]);
        else if (arr[i] > pivot)
            swap(arr[i], arr[gt--]);
        else
            i++;
    }

    quickSort(arr, low, lt - 1);
    quickSort(arr, gt + 1, high);
}


int main() {

    // Example usage of countingSort with an array of 100 million random integers
    const int SIZE = 100000000;
    std::vector<int> data(SIZE);
    // Fill the array with random integers in the range [0, 10000]
    for (int i = 0; i < SIZE; ++i) {
        data[i] = rand() % 10001; // Random integers between 0 and 10000
    }

    auto start = high_resolution_clock::now();

    countingSort(data);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Counting Sort took " << duration.count() << " milliseconds." << endl;

    // Example usage of quickSort with an array of 100 million random integers
    const int SIZE_QS = 100000000;
    std::vector<int> data_qs(SIZE_QS);
    // Fill the array with random integers in the range [0, 10000]
    for (int i = 0; i < SIZE_QS; ++i) {
        data_qs[i] = rand() % 10001; // Random integers between 0 and 10000
    }
    start = high_resolution_clock::now();
    quickSort(data_qs, 0, SIZE_QS - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Quick Sort took " << duration.count() << " milliseconds." << endl;

    return 0;
}