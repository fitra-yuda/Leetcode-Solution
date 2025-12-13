class Solution {
private:
    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, queue<pair<int,int>> &q) {

        int moveRow[] = {-1,0,1,0};
        int moveCol[] = {0,1,0,-1};

        while (q.size() > 0) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextRow = moveRow[i] + row;
                int nextCol = moveCol[i] + col;

                if (nextRow < 0 || nextCol < 0 || nextRow >= (int) heights.size() || nextCol >= (int) heights[0].size()) {
                    continue;
                } else if (ocean[nextRow][nextCol]) {
                    continue;
                } else if (heights[row][col] > heights[nextRow][nextCol]) {
                    continue;
                } else {
                    ocean[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int result = 0;
        int totalRow = heights.size();
        int totalCol = heights[0].size();
        vector<vector<int>> results;

        vector<vector<bool>> pacific(totalRow, vector<bool>(totalCol, false));
        vector<vector<bool>> atlantic(totalRow, vector<bool>(totalCol, false));

        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;

        for (int row = 0; row < totalRow; row++) {
            pacificQueue.push({row,0});
            pacific[row][0] = true;
            atlanticQueue.push({row, totalCol - 1});
            atlantic[row][totalCol - 1] = true;
        }

        for (int col = 0; col < totalCol; col++) {
            pacificQueue.push({0, col});
            pacific[0][col] = true;
            atlanticQueue.push({totalRow - 1, col});
            atlantic[totalRow - 1][col] = true;
        }

        bfs(heights, pacific, pacificQueue);
        bfs(heights, atlantic, atlanticQueue);

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (pacific[row][col] && atlantic[row][col]) {
                    results.push_back({row, col});
                }
            }
        }

        return results;
    }
};