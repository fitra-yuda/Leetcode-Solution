class Solution {
private:
    int dfs(vector<int> &nums, unordered_map<int,unordered_map<int,int>> &dp, int index, int sum, int target) {
        if (index >= nums.size()) {
            if (target == sum) {
                return 1;
            }

            return 0;
        }

        if (dp.count(index) > 0 && dp[index].count(sum) > 0) {
            return dp[index][sum];
        }
        
        // choose positif sign
        int result = dfs(nums, dp, index + 1, sum + nums[index], target);
        // choose negative sign 
        result += dfs(nums, dp, index + 1, sum - nums[index], target);

        return dp[index][sum] = result;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;

        for (auto num : nums) sum += num;

        unordered_map<int, unordered_map<int,int>> dp;

        return dfs(nums, dp, 0, 0, target);
    }
};