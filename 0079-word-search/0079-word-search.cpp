class Solution {
private:
    bool check(vector<vector<char>> &board, string &word, int row, int col, int index) {
        if (index >= word.size()) {
            return true;
        } else if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        } else if (board[row][col] != word[index]) {
            return false;
        } else if (board[row][col] == '.') {
            return false;
        } 

        board[row][col] = '.';
        // move to the top
        bool top = check(board, word, row - 1, col, index + 1);

        // move to the bottom
        bool bottom = check(board, word, row + 1, col, index + 1);
        
        // move to the right
        bool right = check(board, word, row, col + 1, index + 1);
        
        // move to the left
        bool left = check(board, word, row, col - 1, index + 1);

        board[row][col] = word[index];

        return top || bottom || right || left;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                bool result = check(board, word, row, col, 0);

                if (result) {
                    return true;
                }
            }
        }

        return false;
    }
};