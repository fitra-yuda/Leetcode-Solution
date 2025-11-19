class Solution {
private:
    void dfs(int row, int col, int totalRow, int totalCol, vector<vector<char>> &grid) {
        if (row < 0 || row >= totalRow) {
            return;
        } else if (col < 0 || col >= totalCol) {
            return;
        } else if (grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';
        // move to the bottom
        dfs(row - 1, col, totalRow, totalCol, grid);
        // move to the top
        dfs(row + 1, col, totalRow, totalCol, grid);
        // move to the right
        dfs(row, col + 1, totalRow, totalCol, grid);
        // move to the left
        dfs(row, col - 1, totalRow, totalCol, grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int totalRow = grid.size();
        int totalCol = grid[0].size();

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (grid[row][col] == '1') {
                    result++;
                    dfs(row, col, totalRow, totalCol, grid);
                }
            }
        }

        return result;
    }
};