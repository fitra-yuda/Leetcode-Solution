
/*

How to solve : 

DP State
- if the last character from text1 and text2 is not equal
  - either remove character from text1 or text2
- else
  - just remove the character from text1 and text2

formula : 

if text1[i] == text2[i]
-> dp[i][j] = 1 + dp[i - 1][j - 1]
else
-> dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) -> either we remove the character from text1 or text2
   - dp[i - 1][j] -> we choose to remove character from text2
   - d[i][j - 1] -> we choose to remove character from text1


*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));        

        for (int i = 1; i < text1.size() + 1; i++) {
            for (int j = 1; j < text2.size() + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        

        return dp[text1.size()][text2.size()];
    }
};