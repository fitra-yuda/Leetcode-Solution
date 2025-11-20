class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> bucket(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        // move : top, right, bottom , left
        int directionRow[] = {-1,0,1,0};
        int directionCol[] = {0,1,0,-1};
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2) {
                    // first = row, second = col
                    bucket[row][col] = 0;
                    queue<pair<int,int>> q;
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

                    q.push({row, col});
                    visited[row][col] = true;

                    while (q.size() > 0) {
                        auto [currRow, currCol] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nextRow = currRow + directionRow[i];
                            int nextCol = currCol + directionCol[i];

                            if (nextRow < 0 || nextRow >= grid.size()) {
                                continue;
                            } else if (nextCol < 0 || nextCol >= grid[0].size()) {
                                continue;
                            } else if (grid[nextRow][nextCol] == 0) {
                                continue;
                            } else if (visited[nextRow][nextCol] == true) {
                                continue;
                            }

                            bucket[nextRow][nextCol] = min(bucket[currRow][currCol] + 1, bucket[nextRow][nextCol]);
                            q.push({nextRow, nextCol});
                            visited[nextRow][nextCol] = true;
                        }
                    }
                } else if (grid[row][col] == 0) {
                    bucket[row][col] = 0;
                }
            }
        }

        int result = INT_MIN;
        for (int row = 0; row < bucket.size(); row++) {
            for (int col = 0; col < bucket[0].size(); col++) {
                if (bucket[row][col] == INT_MAX) {
                    return -1;
                } 

                result = max(result, bucket[row][col]);
            }
        }

        return result;
    }
};