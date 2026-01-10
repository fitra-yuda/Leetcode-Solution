class Solution {
private:
    int dfs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if (i >= s1.length() && j >= s2.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i < s1.length() && j < s2.length() && s1[i] == s2[j]) {
            return dp[i][j] = dfs(s1, s2, i + 1, j + 1, dp);
        } else {
            // delete character from s1
            int skipS1 = INT_MAX;
            int skipS2 = INT_MAX;
            if (i < s1.length()) {
                skipS1 = dfs(s1, s2, i + 1, j, dp) + s1[i];
            }

            // delete character from s2
            if (j < s2.length()) {
                skipS2 = dfs(s1, s2, i, j + 1, dp) + s2[j];
            }

            return dp[i][j] = min(skipS1, skipS2);
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return dfs(s1, s2, 0, 0, dp);
    }
};