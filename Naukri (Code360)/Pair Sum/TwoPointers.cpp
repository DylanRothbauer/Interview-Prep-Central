/*
* Two Pointers
We will create a map where the key is the unique element in the ‘ARR’ and value is the number of times that key appeared in the ‘ARR’. 
We will create a ‘KEYARRAY’ to store all the unique elements in the ‘ARR’.
We will first sort the ‘KEYARRAY’ and for every ‘KEY’ in ‘KEYARRAY’ we will check if ‘KEY’ + ‘KEY’ is equal to the target sum. If yes we will add all the occurrences of the ‘PAIR’ = {‘KEY’, ‘KEY’)  in the answer list. Total such possible pairs are given by the formula N*(N-1)/2. 

For example, if ‘ARR’ = {2, 2, 2}, ‘S’ = 4. Then ‘MAP’ = {[2, 4]}, ‘KEYARRAY’ = {2} and ‘ANS’ = {[2, 2], [2, 2], [2, 2]}.

Then we will maintain two pointers ‘LOW’ and ‘HIGH’ pointing to the start and end of the ‘KEYARR’. 
We will find the current sum, which will be ‘KEYARR[LOW]’ + ‘KEYARR[HIGH]’ and if the current sum is equal to the target sum then we will add all the occurrences of the current pair to our answer list. 
Otherwise, if the current sum is less than the target sum we will increment ‘LOW’ by 1 so that we can get a greater current sum in the next iteration. 
Otherwise, if the current sum is greater than the target sum we will decrement ‘HIGH’ by 1 so that we can get a lesser current sum in the next iteration.

Algorithm:
- Initialize a list ‘ANS’ to store the result.
- Initialize a map ‘MAP’.
- Iterate ‘NUM’ in ‘ARR’: Add ‘NUM’ to the ‘MAP’ and increment its value by 1.
- Initialize a list ‘KEYARRAY’ to store the unique elements in ‘ARR’.
- Iterate ‘KEY’ in ‘KEYARRAY’: If ‘KEY’ + ‘KEY’ is equal to ‘S’, add all such pairs([‘KEY’, ‘KEY’]) to the ‘ANS’.
- Initialize two pointers ‘LOW’ and ‘HIGH’ pointing to the left and right end of ‘KEYARRAY’ respectively.
- Iterate while ‘LOW’ is less than ‘HIGH’: 
	Set ‘CURRSUM’ as ‘KEYARRAY’[‘LOW’] + ‘KEYARRAY’[‘HIGH’]. 
	If ‘CURRSUM’ is equal to ‘S’, add all such pairs([‘KEYARRAY’[‘LOW’], ‘KEYARRAY’[‘HIGH’]]) to ‘ANS’.
		Increment ‘LOW’ by 1.
		Decrement ‘HIGH’ by 1.
	Otherwise, if ‘CURRSUM’ is less than ‘S’:
		Increment ‘LOW’ by 1.
	Otherwise,
		Decrement ‘HIGH’ by 1.
- Sort the list of pairs as per the given output format and return this list.

Time Complexity
O(N^2), where ‘N’ is the number of elements in the given array.
For the worst case, when all elements are the same we must have to add ‘N’^2 pairs to the answer vector and so, the overall time complexity will be O(N^2).

Space Complexity
O(N), where ‘N’ is the number of elements in the array.
In the worst case, O(N) extra space is required for the hashmap to store the unique elements and frequency of each element. Hence the overall space complexity will be O(N).
*/

/*

    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    where 'N' is the total number of elements
    i.e the size of the input array.

*/

#include<map>

vector<vector<int>> pairSum(vector<int>& arr, int s) {
    // Used to store result.
    vector<vector<int>> ans;

    map<int, int> mp;
    vector<int> keyArray;
    for (int num : arr) {

        if (!mp.count(num)) {
            keyArray.push_back(num);
        }

        // Store frequency of each unique element.
        mp[num] += 1;
    }

    sort(keyArray.begin(), keyArray.end());

    for (int key : keyArray) {

        if (key + key == s) {

            int freq = mp[key];

            // Total number of such pairs will be 'FREQ*(FREQ-1)/2'.
            for (int j = 0; j < freq * (freq - 1) / 2; j++) {

                ans.push_back({ key, key });
            }
        }
    }

    // Maintain two pointers.
    int low = 0;
    int high = keyArray.size() - 1;

    while (low < high) {

        int currSum = keyArray[low] + keyArray[high];

        // If the current sum is equal to the target sum.
        if (currSum == s) {

            int freq = mp[keyArray[low]] * mp[keyArray[high]];

            // Total number of such pairs will be 'FREQ'.
            for (int j = 0; j < freq; j++) {

                ans.push_back({ keyArray[low], keyArray[high] });
            }

            low++;
            high--;

        }
        else if (currSum < s) {

            low++;
        }
        else {

            high--;
        }

    }

    for (int i = 0; i < ans.size(); i++) {

        int a = ans[i][0], b = ans[i][1];
        ans[i][0] = min(a, b);
        ans[i][1] = max(a, b);
    }

    sort(ans.begin(), ans.end());
    return ans;
}