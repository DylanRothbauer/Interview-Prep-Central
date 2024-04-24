/*
* Brute Force
- Initialize a list to store our results.
- For each element in the array 'ARR[i]', check if ('ARR[i]' + ‘ARR[j]’), equals to given sum or not, where ‘i’ < ‘j’ < ‘N’.
- If the condition matches, add the pair('ARR[i]', ‘ARR[j]’) to the list. Sort the list of pairs as per the given output format and return this list.

Time Complexity
O(N ^ 2), where ‘N’ is the number of elements in the array.
In the worst case, for each element, we will be checking all other elements in the array. Hence the overall time complexity will be O(N ^ 2).

Space Complexity
O(1).
Constant extra space is required.
*/

/*

    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the size of the array.

*/

vector< vector<int> > pairSum(vector<int>& arr, int s) {
    int n = arr.size();
    // Used to store result.
    vector< vector<int> > ans;

    // Checking sum for every element.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == s) {
                vector<int> pair(2);
                pair[0] = arr[i];
                pair[1] = arr[j];
                ans.push_back(pair);
            }
        }
    }

    // Used to store final sorted result.
    vector<vector<int> > res(ans.size(), vector<int>(2, 0));
    for (int i = 0; i < ans.size(); i++) {
        int a = ans[i][0], b = ans[i][1];

        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }
    sort(res.begin(), res.end());
    return res;
}