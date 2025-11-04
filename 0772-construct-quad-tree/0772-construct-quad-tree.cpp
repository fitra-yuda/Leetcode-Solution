/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:

    bool check(vector<vector<int>> &grid, int row, int col, int n) {
        int value = grid[row][col];
        bool result = true;

        for (int currentRow = row; currentRow < row + n; currentRow++) {
            for (int currentCol = col; currentCol < col + n; currentCol++) {
                if (grid[currentRow][currentCol] != value) {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }

    Node* dfs(vector<vector<int>> &grid, int row, int col, int n) {
        Node* newNode = new Node(grid[row][col], true); 
        bool checkCurrent = check(grid, row, col, n);
        if (checkCurrent) {
            return newNode;
        }

        newNode -> isLeaf = false;
        newNode -> topLeft = dfs(grid, row, col, n / 2);
        newNode -> topRight = dfs(grid, row, col + n / 2, n / 2);
        newNode -> bottomLeft = dfs(grid, row + n / 2, col, n / 2);
        newNode -> bottomRight = dfs(grid, row + n / 2, col + n / 2, n / 2);

        return newNode;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(grid, 0, 0, n);
    }
};