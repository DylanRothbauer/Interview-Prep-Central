/*
* Binary Search
* O(log N)
*/
int search(vector<int>& nums, int target) {
    // Write your code here.
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            return middle; // the index
        }

        if (nums[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}