/*

Basecase : 
- if (row == totalRow && col == totalCol), then return 1

DP State : 
DP[i][j] = represent the total ways to reach end of the grid start from i-th row and j-th col

DP Transtition : 

TOP DOWN
DP[i][j] = dp[i + 1][j] + dp[i][j + 1]
- dp[i + 1][j] = move to the next row or bottom
- dp[i][j + 1] = move to the next col or right

BOTTOM UP
DP[i][j] = dp[i - 1][j] + dp[i][j - 1]

DP Optimize Space : 
- This only works for bottom up approach
- We don't need an additional space for every single cell that we have, we just need to save previous row

dp[i] = dp[j - 1] + dp[j]

Final State : 

BOTTOM UP
- return cell (0,0)

TOP DOWN
- return dp[i][j] | dp[totalCol - 1]

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int totalRow = obstacleGrid.size();
        int totalCol = obstacleGrid[0].size();

        vector<int> dp(totalCol, 0);
        for (int i = 0; i < totalRow; i++) {
            for (int j = 0; j < totalCol; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = 1;
                } else if (i == 0) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[j] = 0;
                    } else {
                        dp[j] = dp[j - 1];
                    }
                } else if (j == 0) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[j] = 0;
                    }
                } else {
                    if (obstacleGrid[i][j] == 1) {
                        dp[j] = 0;
                    } else {
                        dp[j] = dp[j - 1] + dp[j];
                    }
                }
            }
        }

        return dp[totalCol - 1];
    }
};