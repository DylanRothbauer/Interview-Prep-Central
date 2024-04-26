/*
* Naive Approach
- We rotate the array ‘k’ times where in each iteration, we rotate the array by 1.
- Rotating the array once can be done by changing ‘arr’[i] to ‘arr’[i+1] and appending the first character to the end.

Time Complexity
O(n*k), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
We are doing a total of ‘k’ iterations where each iteration contributes O(n).
Hence the time complexity is O(n*k). 

Space Complexity
O(1).
We are not using any extra space.
Hence the space complexity is O(1). 
*/

/*
    Time Complexity: O(n*k)
    Space Complexity: O(1)
    where n is the size of the input array.
*/

vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    for (int i = 0; i < k; i++) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }

    return arr;
}
