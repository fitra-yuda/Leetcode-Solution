/*

DP State : 
dp[i][j]
- j == 0 -> dp[i + 1][j + 1] + dp[i + 1][j + 2]
- j == 1 -> dp[i + 2][j + 1] + dp[i + 2][j + 2]

- if the current number == 0 || current number > 26, then return 0

Convert to 1 DP : 
dp[i] = dp[i + 1] + dp[i + 2];

*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), 0);

        // basecase
        if (s[s.length() - 1] != '0') {
            dp[s.length() - 1] = 1;
        }

        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] == '0') { 
                dp[i] = 0;
            } else {
                // take one number
                dp[i] = dp[i + 1];

                // take two numbers
                if (s[i] >= '1' && s[i] <= '2') {
                    if (s[i] == '2' && s[i + 1] > '6') {
                        continue;
                    } else if (i + 2 >= s.length()) {
                        dp[i] += 1;
                    } else {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};