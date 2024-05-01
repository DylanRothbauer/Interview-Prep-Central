/*
* Approach
1) Check if the two strings are of equal length or not. If not, then it is impossible to make them equal.

2) Now, the idea is to count the number of unmatched characters in the strings.

3) If the count of unmatched characters is not equal to 2, then it is impossible to make the strings equal. 
   As we have to swap exactly one pair of characters.

4) If the count is 2, find their indices and swap the character at these indices.

5) After swapping the characters check if the characters at unmatched indices became equal or not.

Time Complexity
O(N), where ‘N’ is the length of the strings.
In the worst case, we are traversing the strings to count the number of unequal characters.

Space Complexity
O(1).
In the worst case, we are taking constant extra space.
*/

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the length of string.
*/

bool checkMeta(string& str1, string& str2)
{
    // If the length of strings is not equal, return false.
    if (str1.length() != str2.length())
    {
        return false;
    }

    // If the strings are already equal, return false.
    if (str1 == str2)
    {
        return false;
    }

    int n = str1.length();
    int count = 0;
    int first = -1;
    int second = -1;

    for (int i = 0; i < n; i++)
    {
        // Count total unmatched characters.
        if (str1[i] != str2[i])
        {
            if (first == -1)
            {
                first = i;
            }
            else if (second == -1)
            {
                second = i;
            }
            count++;
        }
        if (count > 2)
        {
            return false;
        }
    }

    // If the count is equal to 1, means we can not make strings equal in 1 swap.
    if (count == 1)
    {
        return false;
    }

    // Swap the characters at unmatched indices.
    swap(str2[first], str2[second]);

    // After swapping check if the string become equal or not.
    bool ans = (str1[first] == str2[first]) && (str1[second] == str2[second]);

    return ans;
}
