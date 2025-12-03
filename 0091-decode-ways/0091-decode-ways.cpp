/*

DP State : 
dp[i][j]
- j == 0 -> dp[i + 1][j + 1] + dp[i + 1][j + 2]
- j == 1 -> dp[i + 2][j + 1] + dp[i + 2][j + 2]

- if the current number == 0 || current number > 26, then return 0

*/

class Solution {
public:
    int numDecodings(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(2, 0));

        // basecase
        if (s[s.length() - 1] != '0') {
            dp[s.length() - 1][0] = 1;
        }

        for (int i = s.length() - 2; i >= 0; i--) {

            if (s[i] == '0') {
                dp[i][0] = 0;
                dp[i][1] = 0;
            } else {
                // take only one digit
                dp[i][0] = dp[i + 1][0] + dp[i + 1][1];

                // take two digit
                if (i + 1 < s.length() && s[i] >= '1' && s[i] <= '2') {
                    if (s[i] == '2' && s[i + 1] > '6') {
                        dp[i][1] = 0;
                    } else if (i + 2 >= s.length()) {
                        dp[i][1] = 1;
                    } else {
                        dp[i][1] = dp[i + 2][0] + dp[i + 2][1];
                    }
                }
            }
        }
        
        return dp[0][0] + dp[0][1];
    }
};