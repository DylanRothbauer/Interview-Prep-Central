/*
* Approach:
- The basic idea is just to take two pointers, one pointing to the index i = M+1 and another pointer pointing to index j=N-1. 
  Now till the condition i<j holds, swap the elements.

Algorithm:

- Firstly take two pointers ‘i’ and ‘j’.
- i = M+1 and j = N-1.
- Now run a while loop with a condition i<j. Inside the while loop:
	swap ARR[i] and ARR[j].
	And after swapping, increment ‘i’ by one and decrement ‘j’ by one.
- This is the required array we want.

Time Complexity
O(N), where ‘N’ is the position after which the array has to be reversed.
Traversing over (N-M-1) elements will take O(N) time. Thus total time complexity will be O(N).   

Space Complexity
O(1)
Constant space is used as we have returned the same array with some modifications.
*/

/*
	Time complexity: O(N)
	Space Complexity: O(1)

	Where N is the number of elements in the array.
*/

void reverseArray(vector<int>& arr, int m) {

	int n = arr.size();

	// Declare two pointers.
	int i = m + 1;
	int j = n - 1;

	// Till the i<j condition holds swap the elements.
	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

}
