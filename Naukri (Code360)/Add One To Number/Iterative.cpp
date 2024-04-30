/*
* Iterative
The problem can be solved by simply iterating the given array and doing the same steps as did in the recursive function.

Algorithm
- Reverse the given array and remove leading zeroes.
- Initialize a variable ‘carry’ to 1.
- Traverse the given array using a variable ‘i’
	- Add carry to the current digit and store result in a variable ‘D’ (D = arr[i] + carry)
	- Store the last digit of the number received after the above addition ( D % 10 ) in the current position
	- Update the carry  ( carry = D / 10 )
 
In the end, if carry is not equal to zero, append carry to the end of the array.

The reverse of the array will be the desired output.

Time Complexity
O(N), Where N is the number of digits in the given number.
Reversing the array takes O(N) time and we traverse the given array only once, so the time complexity is O(N+N+N)=O(N).

Space Complexity
O(1)
Constant additional space is required.
*/

/*
    Time Complexity: O(N)
    Space complexity: O(1)

    Where N is the number of digits in the given number.
*/

#include <algorithm>

vector<int> addOneToNumber(vector<int> arr)
{
    // Reverse the given array
    reverse(arr.begin(), arr.end());

    // Remove leading zeros
    while (arr.size() > 1 && arr.back() == 0)
    {
        arr.pop_back();
    }

    int n = arr.size();
    int carry = 1;

    // Iterate for all digits.
    for (int i = 0; i < n; i++)
    {
        // Store sum in 'd'
        int d = arr[i] + carry;

        // Update current digit and carry.
        arr[i] = d % 10;
        carry = d / 10;
    }

    if (carry != 0)
    {
        arr.push_back(carry);
    }

    // Reverse the array
    reverse(arr.begin(), arr.end());

    return arr;
}
