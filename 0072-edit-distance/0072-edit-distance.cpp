class Solution {
private:

    long long min(long long a, long long b) {
        if (a > b) return b;
        else return a;
    }
    
    long long dfs(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        if (i >= word1.length() && j >= word2.length()) {
            return 0;
        } else if (i >= word1.length()) {
            return word2.length() - j;
        } else if (j >= word2.length()) {
            return word1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        long long result = INT_MAX;
        if (word1[i] == word2[j]) {
            result = min(result, dfs(i + 1, j + 1, word1, word2, dp));
        } else {
            // delete
            result = min(result, dfs(i + 1, j, word1, word2, dp) + 1);

            // replace
            result = min(result, dfs(i + 1, j + 1, word1, word2, dp) + 1);

            // insert
            result = min(result, dfs(i, j + 1, word1, word2, dp) + 1);
        }

        dp[i][j] = result;
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length()) {
            string temp = word1;
            word1 = word2;
            word2 = temp;
        }

        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

        return dfs(0, 0, word1, word2, dp);
    }
};