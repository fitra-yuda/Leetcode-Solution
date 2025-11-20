class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // move : top, right, bottom , left
        int directionRow[] = {-1,0,1,0};
        int directionCol[] = {0,1,0,-1};

        int time = 0;
        int fresh = 0;

        // row | col
        queue<pair<int,int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (fresh > 0 && q.size() > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                grid[row][col] = 0;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nextRow = row + directionRow[i];
                    int nextCol = col + directionCol[i];

                    if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size()) {
                        continue;
                    } else if (grid[nextRow][nextCol] == 2 || grid[nextRow][nextCol] == 0) {
                        continue;
                    }

                    grid[nextRow][nextCol] = 0;
                    fresh--;
                    q.push({nextRow,nextCol});
                }
            }
            
            time++;
        }

        if (fresh != 0) {
            return -1;
        }

        return time;
    }
};