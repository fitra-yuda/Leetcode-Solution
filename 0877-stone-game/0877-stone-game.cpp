class Solution {
private:
    int dfs(vector<int> &piles, int left, int right, int turn, vector<vector<int>> &dp) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int result = 0;
        if (turn == 0) {
            result = max(result, dfs(piles, left + 1, right, 1, dp) + piles[left]);
            result = max(result, dfs(piles, left, right - 1, 1, dp) + piles[right]);
        } else {
            result = max(result, dfs(piles, left + 1, right, 0, dp)); 
            result = max(result, dfs(piles, left, right - 1, 0, dp));
        }

        dp[left][right] = result;
        return dp[left][right];
    }
public:
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        for (auto pile : piles) {
            sum += pile;
        }

        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));

        int alice = dfs(piles, 0, piles.size() - 1, 0, dp);

        if (alice > sum - alice) {
            return true;
        } else {
            return false;
        }
    }
};