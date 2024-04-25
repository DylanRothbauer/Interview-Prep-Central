/*
* For this approach we use the array indices to store the visited state of each number. 
  We know that only the duplicate element would be visited more than once. 
  For each number we go to its index position and multiply it with ’-1’, thus making it negative. 
  In case of duplicate, it will visit twice and hence will become positive, which will be returned.

Example:     Input: 2 4 1 5 3 6 8 7 4

Explanation: 

Traverse from start and multiply each element with ‘-1’ and checking if after multiplication it becomes positive then return it.

2 4 1 5 3 6 8 7 4

-2 -4 -1 -5 -3 -6 -8 -7 4

4 is positive hence return 4

Output: 
4

Time Complexity
O(N), where N is the length of the array.
We need to traverse the array only once hence, in the worst case the complexity will be O(N).

Space Complexity
O(1), Constant space is required.
*/

/*

    Time complexity: O(N)
    Space complexity: O(1)

    Where N is the length of the array.

*/

int findDuplicate(vector<int>& arr, int n)
{

    // Traverse through the array.
    for (int i = 0; i < n; i++)
    {

        // Use array indices to store visited state of each element.
        int index = abs(arr[i]) - 1;

        // Mark as visited by multiplying with '-1'.
        arr[index] *= -1;

        // In case of duplicate, this will become +ve.
        if (arr[index] > 0)
        {

            // Return duplicate element.
            return abs(arr[i]);
        }
    }

    return -1;
}
