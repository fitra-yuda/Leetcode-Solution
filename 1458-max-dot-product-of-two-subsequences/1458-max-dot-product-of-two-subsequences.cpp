class Solution {
private:
    int dfs(vector<int> &nums1, vector<int> &nums2, vector<vector<vector<int>>> &dp , int i, int j, int take) {
        if (i >= nums1.size() || j >= nums2.size()) {
            return take ? 0 : -1e7;
        }

        if (dp[i][j][take] != -1e8) {
            return dp[i][j][take];
        }

        int takeResult = nums1[i] * nums2[j] + dfs(nums1, nums2, dp, i + 1, j + 1, true);
        int skipNums1 = dfs(nums1, nums2, dp, i + 1, j, take);
        int skipNums2 = dfs(nums1, nums2, dp, i, j + 1, take);


        return dp[i][j][take] = max(takeResult, max(skipNums1, skipNums2));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2, -1e8)));
        return dfs(nums1, nums2, dp, 0, 0, false);
    }
};