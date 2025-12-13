class Solution {
private:
    int bfs(vector<vector<int>> &grid, int row, int col) {

        int moveRow[] = {-1,0,1,0}; 
        int moveCol[] = {0,1,0,-1};

        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = 0;

        int result = 1;

        while (q.size() > 0) {
            auto [row, col] = q.front();
            q.pop();

            
            for (int i = 0; i < 4; i++) {
                int nextRow = moveRow[i] + row;
                int nextCol = moveCol[i] + col;

                if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size()) {
                    continue;
                } else if (grid[nextRow][nextCol] == 0) {
                    continue;
                }
                q.push({nextRow, nextCol});
                grid[nextRow][nextCol] = 0;

                result++;
            }
        }

        return result;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int totalRow = grid.size();
        int totalCol = grid[0].size();

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (grid[row][col] == 1) {
                    result = max(bfs(grid, row, col), result);
                }
            }
        }

        return result;
    }
};