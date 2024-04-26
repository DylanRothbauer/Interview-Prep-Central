/*
* Binary Search
Since our array is sorted, we can apply binary search here. 
We will keep two variables, ‘s’ and ‘e’, initially assigned to ‘0’ and ‘length of the array’, respectively. 
At each iteration, we will first calculate the middle value of ‘s’ and ‘e’ and store it in a variable called ‘mid’. 
Then we will check the following conditions:

- nums[mid] == target:
We have found our answer in this case, so that we will return the index.

- nums[mid] > target:
In this case, the current value is greater than the ‘target’, so we will go to the smaller values.

- nums[mid] < target:
In this case, the current value is smaller than the ‘target’, so we will go to the larger values.
 
If we don’t find any index, we will return ‘-1’.

The steps are as follows:-
// Function to find the element ‘target’

function search(int[] nums, int n, int target):

1) Int ‘n’ is the size of the array ‘nums’, and ‘target’ is the element we want to find.

2) Initialize two variables, ‘s’ and ‘e’, initially assigned to ‘0’ and ‘n - 1’, respectively.

3) while ‘s <= e’:
	Initialize a variable ‘mid’, and assign it to ‘(s + e) / 2’.
	If ‘nums[mid] == target’:
		Return ‘mid’.
	else if ‘nums[mid] > target’:
		Assign ‘e’ to ‘mid - 1’.
	else:
		Assign ‘s’ to ‘mid + 1’.
4) Return -1.

Time Complexity
O( N * logN ), where 'N' is the size of the array ‘nums’.
We are using the binary search here,
Hence the time complexity is O( N * logN ).

Space Complexity
O( 1 ).
We are only using some variables,
Hence the space complexity is O( 1 ).
*/

int search(vector<int>& nums, int target)
{
    // n is the size of the array 'nums'
    int n = nums.size();

    // Initialising two variables
    // 's' and 'e'
    int s = 0, e = n - 1;
    while (s <= e)
    {
        // Initializing the variable 'mid'
        int mid = s + (e - s) / 2;

        // If the current index's value is equal to
        // target, we will return the current index
        if (nums[mid] == target)
        {
            return mid;
        }
        // If the value is greater than target,
        // we will decrease the value of 'e'
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        // Otherwise, we will increase the value
        // of 's'
        else
        {
            s = mid + 1;
        }
    }

    // If we didn't find anything, we will return -1.
    return -1;
}