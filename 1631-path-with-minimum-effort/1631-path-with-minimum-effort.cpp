class Node {
private:
    int row;
    int col;
    int value;
    Node* parent;
public:
    Node(int row, int col, int value, Node* parent) {
        this -> row = row;
        this -> col = col;
        this -> parent = parent;
        this -> value = value;
    }

    Node* getParent() {
        return this -> parent;
    }

    int getValue() {
        return this -> value;
    }

    int getRow() {
        return this -> row;
    }
    
    int getCol() {
        return this -> col;
    }
};

struct Compare {
    bool operator()(Node* first, Node* second) {
        // if current node -> value > next node -> value, then swap the value
        // sort by value dest
        return first -> getValue() > second -> getValue();
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        pq.push(new Node(0, 0, heights[0][0], NULL));

        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        Node* resultNode = NULL;

        int moveRow[] = {-1,0,1,0};
        int moveCol[] = {0,1,0,-1};
        while (pq.size() > 0) {
            Node* node = pq.top();
            pq.pop();

            if (visited[node -> getRow()][node -> getCol()] == true) {
                continue;
            }

            visited[node -> getRow()][node -> getCol()] = true;
            if (node -> getRow() == heights.size() - 1 && node -> getCol() == heights[0].size() - 1) {
                resultNode = node;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nextRow = moveRow[i] + node -> getRow();
                int nextCol = moveCol[i] + node -> getCol();

                if (nextRow < 0 || nextRow == heights.size() || nextCol < 0 || nextCol == heights[0].size()) {
                    continue;
                } else if (visited[nextRow][nextCol] == true) {
                    continue;
                }

                pq.push(new Node(nextRow, nextCol, abs(heights[nextRow][nextCol] - heights[node -> getRow()][node -> getCol()]), node));
            }
        }

        int result = 0;
        while (resultNode -> getParent() != NULL) {
            Node* parent = resultNode -> getParent(); 
            int currentResult = heights[resultNode -> getRow()][resultNode -> getCol()];
            int parentResult = heights[parent-> getRow()][parent -> getCol()];
            result = max(result, abs(currentResult - parentResult));
            resultNode = parent;
        }

        return result;
    }
};