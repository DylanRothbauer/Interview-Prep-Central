/*
* We perform binary search on the array [1,N], then COUNT the number of elements that are less than or equal to MID of [1,N]. 
  If the duplicate is on the left side of the middle element, then the COUNT should be more than MID, else it is on the right side. 
  Narrow down the search space each time until you find the repeating number then return it.

Example:     Input: 2 4 1 5 3 6 8 7 4

Explanation: 

LOW = 1, HIGH = 9, MID = 5
COUNT elements smaller or equal to MID: count = 6
COUNT > MID , hence the repeated element is less than 5 -> 
HIGH = MID = 5, hence new MID = 3, now count elements smaller or equal to mid: COUNT = 3
COUNT <= MID, hence the repeated element is greater than 3 ->
LOW = MID + 1 = 4, hence new MID = 4, now count elements smaller or equal to mid: COUNT = 5   
COUNT > MID , hence the repeated element is less than or equal to 4 -> 
HIGH = MID = 4, hence new MID = old MID = 4, hence repeated element = 4.

Output: 
4

Time Complexity
O(N * log(N)), where N is the length of the array.
Search space decreases each time by half hence making the time complexity = O(N * log(N)).

Space Complexity
O(1), Constant space is required.
*/

/*

    Time complexity: O(N * log(N))
    Space complexity: O(1)

    Where N is the length of the array.

*/

int findDuplicate(vector<int>& arr, int n)
{

    // Initialise low and high pointers.
    int low = 1, high = n;

    // Find mid.
    while (low < high)
    {

        // Initialise mid element.
        int mid = low + (high - low) / 2;

        // Initialise count variable to count number of elements less than mid.
        int count = 0;

        // Count the number of elements smaller / equal to mid element.
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid)
            {
                count++;
            }
        }

        // Duplicate element is on left side of mid hence high = mid.
        if (count > mid)
        {
            high = mid;
        }

        // Duplicate element is on the right side of mid hence low = mid + 1.
        else
        {
            low = mid + 1;
        }
    }

    return low;
}
