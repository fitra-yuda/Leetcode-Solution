/*

Basecase : 
- if (row == totalRow && col == totalCol), then return 1

DP State : 
DP[i][j] = represent the total ways to reach end of the grid start from i-th row and j-th col

DP Transtition : 
DP[i][j] = dp[i + 1][j] + dp[i][j + 1]

- dp[i + 1][j] = move to the next row or bottom
- dp[i][j + 1] = move to the next col or right

*/

class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
       if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1;
       } else if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) {
            return 0;
       } else if (obstacleGrid[i][j] == 1) {
            return 0;
       }

       if (dp[i][j] != -1) {
            return dp[i][j];
       }

       // move to the bottom
       int bottomResult = dfs(i + 1, j, obstacleGrid, dp);
       // move to the right
       int rightResult = dfs(i, j + 1, obstacleGrid, dp);

        dp[i][j] = bottomResult + rightResult;
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));   
        return dfs(0, 0, obstacleGrid, dp);
    }
};