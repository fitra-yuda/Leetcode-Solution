class Solution {
private:

    bool check(vector<pair<int,int>> &positions, int row, int col, int n) {
        bool result = true;
        // check row
        for (int currentRow = 0; currentRow < n; currentRow++) {
            if (currentRow == row) {
                continue;
            }

            for (auto [r, c] : positions) {
                if (currentRow == r && c == col) {
                    result = false;
                }
            }
        }

        // move to top left
        for (int currentRow = row - 1, currentCol = col - 1; currentRow >= 0 && currentCol >= 0; currentRow--, currentCol--) {
            
            for (auto [r , c] : positions) {
                if (currentRow == r && currentCol == c) {
                    result = false;
                }
            }
        }

        // move to bottom right
        for (int currentRow = row + 1, currentCol = col + 1; currentRow < n && currentCol < n; currentRow++, currentCol++) {
            
            for (auto [r , c] : positions) {
                if (currentRow == r && currentCol == c) {
                    result = false;
                }
            }
        }

        // move to top right
        for (int currentRow = row - 1, currentCol = col + 1; currentRow >= 0 && currentCol < n; currentRow--, currentCol++) {
            
            for (auto [r , c] : positions) {
                if (currentRow == r && currentCol == c) {
                    result = false;
                }
            }
        }

        // move to bottom left
        for (int currentRow = row + 1, currentCol = col - 1; currentRow < n && currentCol >= 0; currentRow++, currentCol--) {
            
            for (auto [r , c] : positions) {
                if (currentRow == r && currentCol == c) {
                    result = false;
                }
            }
        }

        return result;
    }

    void construct(vector<vector<pair<int,int>>> &results, vector<pair<int,int>> &positions, int row, int n, int total) {
        if (total == n) {
            results.push_back(positions);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (check(positions, row, col, n) == false) {
                continue;
            }

            positions.push_back({row, col});
            construct(results, positions, row + 1, n, total + 1);
            positions.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int,int>>> results;
        vector<pair<int, int>> positions;

        construct(results, positions, 0, n, 0);

        vector<vector<string>> answer;

        for (auto positions : results) {
            vector<string> temp;
            for (int row = 0; row < n; row++) {
                string map = "";
                for (int col = 0; col < n; col++) {
                    map += '.';
                }
                temp.push_back(map);
            }

            for (auto [row, col] : positions) {
                temp[row][col] = 'Q';
            }

            answer.push_back(temp);
        }

        return answer;
    }
};