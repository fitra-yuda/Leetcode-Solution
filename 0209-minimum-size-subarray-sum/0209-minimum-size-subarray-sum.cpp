class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                result = min(result, right - left + 1);

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