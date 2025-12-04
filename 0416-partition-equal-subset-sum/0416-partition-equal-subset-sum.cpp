class Solution {
private:
    bool recursive(vector<int> &nums, vector<vector<int>> &dp, int index, int current, int total) {
        if (current > total) {
            return false;
        } else if (current == total) {
            return true;
        } else if (index >= nums.size()) {
            return false;
        }

        if (dp[index][current] != -1) {
            return dp[index][current];
        }

        bool take = recursive(nums, dp, index + 1, current + nums[index], total);
        bool skip = recursive(nums, dp, index + 1, current, total);

        dp[index][current] = take || skip;

        return dp[index][current];
    }
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (auto number : nums) {
            total += number;
        }

        if (total % 2 == 1) {
            return false;
        }

        total /= 2;

        vector<vector<int>> dp(nums.size(), vector<int>(total, -1));

        bool result = recursive(nums, dp, 0, 0, total);

        return result;
    }
};