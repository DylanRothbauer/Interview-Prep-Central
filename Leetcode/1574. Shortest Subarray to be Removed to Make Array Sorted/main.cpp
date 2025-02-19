// Time Complexity: O(N)
// In the worst case for our two pointer algorithm, left will traverse through the entire blue sorted region once, 
// and right will traverse through the entiregreensorted region once. 
// Thus, the time complexity grows linearly with the size ofarr:O(N)

// Space Complexity: O(1)
// We only use two pointers to store indices and do not have any auxiliary data structures, 
// so the space complexity isO(1).

// Solution provided by LeetCode (Editorial)

class Solution {
    public:
        int findLengthOfShortestSubarray(vector<int>& arr) {
            int right = arr.size() - 1;
            while (right > 0 && arr[right] >= arr[right - 1]) {
                right--;
            }
    
            int ans = right;
            int left = 0;
            while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
                // find next valid number after arr[left]
                while (right < arr.size() && arr[left] > arr[right]) {
                    right++;
                }
                // save length of removed subarray
                ans = min(ans, right - left - 1);
                left++;
            }
            return ans;
        }
    };