#include <iostream>
#include <algorithm>
using namespace std;

int findUnique(int* arr, int size)
{
    //Write your code here
    sort(arr, arr + size);

    for (int i = 0; i < size - 1; i += 2) {
        if (arr[i] != arr[i + 1]) {
            return arr[i];
        }
    }
    // If no unique element found, return the last element
    // This could also work on the first I believe
    return arr[size - 1];
}