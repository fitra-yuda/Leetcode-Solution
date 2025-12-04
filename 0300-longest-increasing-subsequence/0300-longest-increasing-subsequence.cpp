class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }

            dp[i] += 1;

            result = max(result, dp[i]);
        }

        return result;
    }
};