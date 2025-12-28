class Solution {
private:
    // 0 -> alice, 1 -> bob
    bool dfs(vector<int>& piles, vector<vector<vector<int>>> &dp, int left, int right, int turn, int alice, int bob) {
        if (left > right) {
            if (alice > bob) {
                return true;
            } else {
                return false;
            }
        }

        if (dp[left][right][turn] != -1) {
            return dp[left][right][turn];
        }

        bool leftResult = false;
        bool rightResult = false;
        if (turn == 0) {
            leftResult = dfs(piles, dp, left + 1, right, 1, alice + piles[left], bob);
            rightResult = dfs(piles, dp, left, right - 1, 1, alice + piles[right], bob);
        } else {
            leftResult = dfs(piles, dp, left + 1, right, 0 , alice, bob + piles[left]);
            rightResult = dfs(piles, dp, left, right - 1, 0, alice, bob + piles[right]);
        }

        dp[left][right][turn] = leftResult || rightResult;
        return dp[left][right][turn];
    }
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size(), vector<vector<int>>(piles.size(), vector<int>(2, -1)));
        return dfs(piles, dp, 0, piles.size() - 1, 0, 0, 0);
    }
};