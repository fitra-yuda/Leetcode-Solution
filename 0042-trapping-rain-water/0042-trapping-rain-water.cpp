class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        int minValue = min(height[left], height[right]);

        while (left < right) {

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

            // calculate the result
            if (minValue < min(height[left], height[right])) {
                minValue = min(height[left], height[right]);
            }

            result += minValue - min(height[left], height[right]);
        }

        return result;
    }
};