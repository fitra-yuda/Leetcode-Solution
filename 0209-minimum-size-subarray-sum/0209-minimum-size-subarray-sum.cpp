class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int result = INT_MAX;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                result = min(result, (right - left) + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }
        
        if (result == INT_MAX) {
            result = 0;
        }

        return result;
    }
};