class Solution {
private:
    int dfs(string &s1, string &s2, vector<vector<int>> &dp, int i, int j) {
        if (i == s1.length() && j == s2.length()) {
            return 0;
        } else if (i >= s1.length()) {
            return s2.length() - j;
        } else if (j >= s2.length()) {
            return s1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int result = INT_MAX;
        if (s1[i] == s2[j]) {
            result = dfs(s1, s2, dp, i + 1, j + 1);
        } else {
            // choose to insert 
            result = dfs(s1, s2, dp, i, j + 1) + 1;

            // choose to delete
            result = min(result, dfs(s1, s2, dp, i + 1, j) + 1);

            // choose to replace
            result = min(result, dfs(s1, s2, dp, i + 1, j + 1) + 1);
        }

        return dp[i][j] = result;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        
        return dfs(word1, word2, dp, 0, 0); 
    }
};