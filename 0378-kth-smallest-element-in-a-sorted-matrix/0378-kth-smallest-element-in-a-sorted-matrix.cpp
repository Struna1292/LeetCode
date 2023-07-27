class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        n *= n;

        vector<int> nums(n, 0);
        int iterator = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                nums[iterator] = matrix[i][j];
                iterator++;
            }
        }

        sort(begin(nums), end(nums));

        return nums[k-1];
    }
};