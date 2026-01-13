class Solution {
private:
    double calculate(double yLine, vector<vector<int>> &squares) {
        double top = 0;
        double bottom = 0;
        
        for (int i = 0; i < squares.size(); i++) {
            int x = squares[i][0];
            int y = squares[i][1];
            int l = squares[i][2];

            double total = (double) l * l;

            if (yLine <= y) {
                top += total;
            } else if (yLine >= y + l) {
                bottom += total;
            } else {
                double topHeight = (y + l) - yLine;
                double bottomHeight = yLine - y;

                top += l * topHeight;
                bottom += bottomHeight * l;
            }
        }

        return top - bottom;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        
        double left = 0;
        double right = 2e9;
        for (int i = 0; i < 50; i++) {
            double mid = left + (right - left) / 2.0;
            double diff = calculate(mid, squares);

            if (diff > 0) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return right;
    }
};