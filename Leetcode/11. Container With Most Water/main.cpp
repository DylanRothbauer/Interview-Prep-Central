// Two pointers approach

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxAmount = 0;

        while (left < right) {
            int minHeight = std::min(height[left], height[right]);
            int minLength = right - left;
            //int tmp = pow(min,2);
            int tmp = minLength * minHeight;
            if (tmp > maxAmount) {
                maxAmount = tmp;
            }

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxAmount;
    }
};