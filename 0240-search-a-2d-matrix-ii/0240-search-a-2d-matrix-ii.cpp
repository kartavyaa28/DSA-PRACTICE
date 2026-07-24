class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // no of rows
        int n = matrix[0].size(); // no of columns
        int row = 0, col = n - 1; // start at top-right
        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--; // move left
            else
                row++; // move down
        }
        return false;
    }
};