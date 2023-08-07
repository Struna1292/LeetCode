class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int left = 0;
        int right = matrix.size()-1;
        int row = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
 
            if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1])
            {
                row = mid;
                break;
            }

            if (target < matrix[mid][0])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (row == -1)
        {
            return false;
        }

        left = 0;
        right = matrix[row].size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (target == matrix[row][mid])
            {
                return true;
            }

            if (matrix[row][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};