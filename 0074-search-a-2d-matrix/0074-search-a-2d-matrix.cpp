class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();

        int left = 0;
        int right = (totalRow * totalCol) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / totalCol;
            int col = mid - ((mid / totalCol) * totalCol);

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};