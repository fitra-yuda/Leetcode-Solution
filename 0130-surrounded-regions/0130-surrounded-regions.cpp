class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int totalRow = board.size();
        int totalCol = board[0].size();
 
        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (row == 0 || row == totalRow - 1 || col == 0 || col == totalCol - 1) {
                    if (board[row][col] == 'O') {
                        q.push({row, col});
                        board[row][col] = 'Z';
                    }
                }
            }
        }

        int moveX[] = {-1,0,1,0};
        int moveY[] = {0,1,0,-1};
        while (q.size() > 0) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextRow = row + moveY[i];
                int nextCol = col + moveX[i];

                if (nextRow < 0 || nextRow >= totalRow || nextCol < 0 || nextCol >= totalCol) {
                    continue;
                } else if (board[nextRow][nextCol] == 'Z' || board[nextRow][nextCol] == 'X') {
                    continue;
                }

                board[nextRow][nextCol] = 'Z';
                q.push({nextRow,nextCol});
            }
        }

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                } else if (board[row][col] == 'Z') {
                    board[row][col] = 'O';
                }
            }
        }

    }
};