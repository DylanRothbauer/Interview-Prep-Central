/*
* Using HashMap
- Initialize a list to store our results.
- For each element in the array ‘ARR[i]’, we will check whether there exists an element equals to ('S' - ‘ARR[i]’) already in the map.
- If it exists we will add the pair('ARR[i]', ‘S’ - ‘ARR[i]’ ) ‘COUNT’ number of times to the list, where ‘COUNT’ represents the frequency of ('S' - ‘ARR[i]’) in the map.
- Also, we will increment the frequency of the current element ('ARR[i]') in the map. Sort the list of pairs as per the given output format and return this list.

Time Complexity
O(N^2), where ‘N’ is the number of elements in the array.
For the worst case, when all elements are the same we must have to add ‘N’^2 pairs to the answer vector and so, the overall time complexity will be O(N^2).

Space Complexity
O(N), where ‘N’ is the number of elements in the array.
In the worst case, O(N) extra space is required for the hashmap to store the frequency of each element. Hence the overall space complexity will be O(N).
*/

/*

    Time Complexity: O(N^2)
    Space COmplexity: O(N)

    Where 'N' is the size of the array.

*/

#include <map>

vector<vector<int>> pairSum(vector<int>& arr, int s) {
    int n = arr.size();

    // Map to store frequency of elements.
    map<int, int> hash;

    // This will store the result.
    vector<vector<int>> ans;

    for (int ele : arr)
    {
        int count = hash[s - ele];

        vector<int> pair(2);
        pair[0] = ele;
        pair[1] = s - ele;

        while (count--)
        {
            ans.push_back(pair);
        }

        hash[ele] += 1;
    }

    // This will store the final result.
    vector<vector<int>> res(ans.size(), vector<int>(2, 0));

    // Sorting the 'ans' arrays element.
    for (int i = 0; i < ans.size(); i++)
    {
        int a = ans[i][0], b = ans[i][1];
        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }

    // Finally sorting each pair in 'res'.
    sort(res.begin(), res.end());
    return res;
}