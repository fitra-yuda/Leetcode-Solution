class Solution {
private:

    bool isSafe(vector<pair<int,int>> &positions, int row, int col, int n) {

        // check top
        for (int currentRow = row - 1; currentRow >= 0; currentRow--) {
            
            for (auto [r, c] : positions) {
                if (currentRow == r && col == c) {
                    return false;
                }
            }
        }

        // check top left
        for (int currentRow = row - 1, currentCol = col - 1; currentRow >= 0 && currentCol >= 0; currentRow--, currentCol--) {
            for (auto [r, c] : positions) {
                if (currentRow == r && currentCol == c) {
                    return false;
                }
            }
        }

        // check top right
        for (int currentRow = row - 1, currentCol = col + 1; currentRow >= 0 && currentCol < n; currentRow--, currentCol++) {
            for (auto [r, c] : positions) {
                if (currentRow == r && currentCol == c) {
                    return false;
                }
            }
        }

        return true;
    }

    int construct(int n, int row, vector<pair<int,int>> &positions) {
        if (row == n) {
            return 1;
        }

        int result = 0;

        for (int col = 0; col < n; col++) {
            if (isSafe(positions, row, col, n) == false) {
                continue;
            }

            positions.push_back({row, col});
            result += construct(n, row + 1, positions);
            positions.pop_back();
        }

        return result;
    }
public:
    int totalNQueens(int n) {
        vector<pair<int,int>> positions;

        int result = construct(n, 0, positions);

        return result;
    }
};