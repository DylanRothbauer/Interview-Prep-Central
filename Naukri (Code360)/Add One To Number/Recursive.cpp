/*
* Recursive
The basic idea is to reverse the given array to make addition easier. 
We will maintain a variable ‘carry’ initially; it will be ‘1’ as we have to add 1 to the given number.
Now we will call a recursive function to add 1 to reversed array.

Recursive state: addOneToNumberHelper(Arr, N, carry, idx)
In each recursive state, we increment the value of idx.
 

In each recursive state, we will do these steps:
- Add carry to the current digit (D += carry)
- Store the last digit of the number received after the above addition ( D % 10 ) in the current position
- Update the carry  ( carry = D / 10 )
- Move to next recursive state with the new carry, i.e, addOneToNumberHelper(Arr, N, carry, idx + 1)
 
When we reach the end of the array (base case), we will append carry at the end of the array(if carry is not equal to zero) and then return from the recursive function.


Time Complexity
O(N), Where ‘N’ is the number of digits in the given number.
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

void addOneToNumberHelper(vector<int>& arr, int n, int i, int carry)
{
    // Base case
    if (i == n)
    {
        if (carry != 0)
        {
            arr.push_back(carry);
        }
        return;
    }

    // Store sum in 'd'.
    int d = arr[i] + carry;

    // Update current digit and carry.
    arr[i] = d % 10;
    carry = d / 10;

    addOneToNumberHelper(arr, n, i + 1, carry);
}

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

    // Recurrsive function to add 1.
    addOneToNumberHelper(arr, n, 0, 1);

    // Reverse the array
    reverse(arr.begin(), arr.end());

    return arr;
}
