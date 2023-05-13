class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        for (int i = 0; i < nums.size(); i++)
        {
            sort(begin(nums[i]), end(nums[i]), greater<int>());
        }

        int output = 0;
        for (int i = 0; i < nums[0].size(); i++)
        {
            int biggest = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j][i] > biggest)
                {
                    biggest = nums[j][i];
                }
            }
            output += biggest;
        }

        return output;
    }
};