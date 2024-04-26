/*
* Optimised Approach
- We note that rotating an Array K times is just placing the first K elements at the end and bringing forward rest of the elements.
- So we store the first K elements in a temporary array.
- We then bring the remaining N - K elements at the front by moving each of them K places ahead.
- Finally we append the initial first K elements at the end to get the rotated Array.
 

Time Complexity
O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
We are iteration over the array once.
Hence the time complexity is O(n). 

Space Complexity
O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
We are creating a new array to store the rotated values.
Hence the space complexity is O(n). 
*/

/*
    Time complexity: O(n)
    Space complexity: O(n)
    where 'n' is the size of array.
*/

vector<int> rotateArray(vector<int>& arr, int k) {

    int n = arr.size();

    // Create a 'rotatedArr' of size 'n'.
    vector<int> rotatedArr(n);

    // Now store ith value (0 <= i <= n-1) of 'arr' at ((i - k + n)%n)th position in 'rotatedArr'.
    for (int i = 0; i < n; i++) {
        rotatedArr[(i - k + n) % n] = arr[i];
    }
    // Return the rotatedArr.
    return rotatedArr;
}