/*
* We need to insert elements into a data structure and look them up in constant time, so as to improve the complexity of sorting approach. 
  A set can be used to satisfy these conditions. So, we iterate over the array and insert each element into a set. 
  Before inserting we check whether the element is already present in the set or not. If it is found, we get the repeated element and hence return it.

Time Complexity
O(N), where N is the length of the array.
The insertion and lookup in the ‘set’ takes constant time, hence the complexity will only be due to the linear traversal making complexity = O(N).

 

Space Complexity
O(N), where N is the length of the array.
Extra space for the set makes the space complexity is O(N).
*/

/*

    Time complexity: O(N)
    Space complexity: O(N)

    Where N is the length of the array.

*/

int findDuplicate(vector<int>& arr, int n)
{

    // Create an unordered set to store each element.
    unordered_set<int> uset;

    // For each value of array perform.
    for (int i : arr)
    {

        // Check if current element is already present.
        if (uset.find(i) != uset.end())
        {

            // If present return this repeated element.
            return i;
        }
        else
        {

            // If element not found, insert it into the set.
            uset.insert(i);
        }
    }

    return -1;
}
