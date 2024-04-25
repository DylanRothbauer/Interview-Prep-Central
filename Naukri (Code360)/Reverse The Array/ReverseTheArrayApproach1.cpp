/*
* Approach:
- Here we will use another array for reversing the elements.
- The basic idea is just to store the elements up to the Mth position in the newly created array in the same way as they are given in the original array. Now after the Mth position store the elements in the reverse order.
 
Algorithm:
- Firstly we will create another array say ‘BRR’ of the same size as the original array.
- We will take one variable P = 0.
- Now run a for loop in the forward direction from i=0 to i=M and fill the array ‘BRR’ in the same way as the original array i.e BRR[P++] = ARR[i]. Here ‘i’ will be incremented by one in each iteration.
- Now run a second for loop in the reverse direction from j=N-1 to j=k+1 and fill the array ‘BRR’.Now the elements will be filled in the reversed order i.e BRR[p++] = ARR[j]. Here ‘j’ will be decremented by one in each iteration.
- Finally copy back the array ‘BRR’ to array ‘ARR’ which the required array we want.

Time Complexity
O(N), where ‘N’ is the number of elements in the array.
Traversing over (M) elements will take O(M) time. Again traversing the array in the reverse direction over (N-M-1) elements will take (N-M-1) time. Thus total time complexity will be O(N).   

Space Complexity
O(N)

Another array is created for reversing the elements.
*/

/*
	Time complexity: O(N)
	Space Complexity: O(N)

	Where N is the number of elements in the array.
*/

void reverseArray(vector<int>& arr, int m) {

	int n = arr.size();

	// Declare vector BRR.
	vector<int> brr(n, 0);

	// Declare a varibale p
	int p = 0;

	// First fill the BRR in the same order as the original array upto Mth postion.
	for (int i = 0; i <= m; i++) {
		brr[p++] = arr[i];
	}

	// Now fill the BRR in the reverse order till (m+1)th postion.
	for (int j = n - 1; j > m; j--) {
		brr[p++] = arr[j];
	}

	// Now copy back the array ARR into array ARR.
	for (int i = 0; i < n; i++) {
		arr[i] = brr[i];
	}
}
