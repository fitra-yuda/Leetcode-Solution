class Solution {
private:
    int dfs(vector<int> &piles, int left, int right, int turn, vector<vector<int>> &dp) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        turn = (turn + 1) % 2;
        int leftResult = turn == 0 ? piles[left] : 0;
        int rightResult = turn == 0 ? piles[right] : 0;

        int result = max(
            dfs(piles, left + 1, right, turn, dp) + leftResult,
            dfs(piles, left, right - 1, turn, dp) + rightResult
        );

        dp[left][right] = result;
        return dp[left][right];
    }
public:
    bool stoneGame(vector<int>& piles) {
        return true;
        // int sum = 0;
        // for (auto pile : piles) {
        //     sum += pile;
        // }

        // vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));

        // int alice = dfs(piles, 0, piles.size() - 1, 0, dp);

        // if (alice > sum - alice) {
        //     return true;
        // } else {
        //     return false;
        // }
    }
};