class Solution {
private:
    bool check(vector<vector<char>> &board, string &word, string &current, int row, int col) {
        if (current.length() == word.length()) {
            return current == word;
        } else if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        } else if (current.length() > 0 && current[current.length() - 1] != word[current.length() - 1]) {
            return false;
        } else if (board[row][col] == '.') {
            return false;
        } 

        current += board[row][col];
        board[row][col] = '.';
        cout << current << endl;
        // move to the top
        bool top = check(board, word, current, row - 1, col);

        // move to the bottom
        bool bottom = check(board, word, current, row + 1, col);
        
        // move to the right
        bool right = check(board, word, current, row, col + 1);
        
        // move to the left
        bool left = check(board, word, current, row, col - 1);

        board[row][col] = current[current.length() - 1];
        current.pop_back();

        return top || bottom || right || left;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                string current = "";
                bool result = check(board, word, current, row, col);

                if (result) {
                    return true;
                }
            }
        }

        return false;
    }
};