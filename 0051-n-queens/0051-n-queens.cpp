class Solution {
private:
    void construct(vector<vector<string>> &results, vector<string> &board, int row, int n) {
        if (row >= n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n) == false) {
                continue;
            } 

            board[row][col] = 'Q';
            construct(results, board, row + 1, n);
            board[row][col] = '.';
        }
    }

    bool isSafe(vector<string> &board, int row, int col, int n) {
        // check row
        for (int currentRow = 0; currentRow < row; currentRow++) {
            if (board[currentRow][col] == 'Q') {
                return false;
            }
        }

        // check top left
        for (int currentRow = row - 1, currentCol = col - 1; currentRow >= 0 && currentCol >= 0; currentRow--, currentCol--) {
            if (board[currentRow][currentCol] == 'Q') {
                return false;
            }
        }

        // check top right
        for (int currentRow = row - 1, currentCol = col + 1; currentRow >= 0 && currentCol < n; currentRow--, currentCol++) {
            if (board[currentRow][currentCol] == 'Q') {
                return false;
            }
        }

        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));

        construct(results, board, 0,  n);

        return results;
    }
};