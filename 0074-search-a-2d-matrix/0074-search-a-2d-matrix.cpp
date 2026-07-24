class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // no of rows
        int n = matrix[0].size(); // no of columns
        int low = 0;
        int high = m*n - 1;
        // we are applying binary search on whole matrix at once
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid/n;  //Because every row has n elements.Dividing by n tells us how many full rows   
                               //fit before this index.
            int cols = mid%n; // Because the remainder tells us the position inside the row.
            if (matrix[row][cols] == target)
               return true;
            else if(matrix[row][cols] < target)
            {
                low = mid+1;
            } else {
                high = mid-1;
            }    
            
        }

        return false;
    }
};