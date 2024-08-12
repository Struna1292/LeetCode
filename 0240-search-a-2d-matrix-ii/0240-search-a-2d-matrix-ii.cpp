class Solution {
public:
    int binarySearchRow(vector<vector<int>>& nums, int row, int target)
    {
        int left = 0;
        int right = nums[row].size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[row][mid] == target)
            {
                return mid;
            }

            if (nums[row][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target)
            {
                if (binarySearchRow(matrix, i, target) != -1)
                {
                    return true;
                }
            }
        }

        return false;
    }
};