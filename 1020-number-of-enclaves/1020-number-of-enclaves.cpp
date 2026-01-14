class Solution {
private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        } else if (grid[i][j] == 0) {
            return 0;
        } else if (grid[i][j] == 1 && (i == 0 || i == grid.size() - 1 || j == 0 || j >= grid[0].size() - 1)) {
            return -1;
        } else {
            grid[i][j] = 0;
            int topMove = dfs(grid, i - 1, j);
            int bottomMove = dfs(grid, i + 1, j);
            int rightMove = dfs(grid, i, j + 1);
            int leftMove = dfs(grid,i, j - 1);

            if (topMove == -1 || bottomMove == -1 || rightMove == -1 || leftMove == -1) {
                return -1;
            }

            return topMove + bottomMove + rightMove + leftMove + 1;
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0; 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int currentResult = dfs(grid, i, j);
                    if (currentResult > 0) {
                        result += currentResult;
                    }
                }
            }
        }

        return result;
    }
};