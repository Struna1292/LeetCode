class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int output = -1;

        for (int i = 0; i < nums.size()-2; i++)
        {
            for (int j = i+1; j < nums.size()-1; j++)
            {
                if (nums[i] < nums[j])
                {
                    for (int k = j+1; k < nums.size(); k++)
                    {
                        if (nums[k] < nums[j])
                        {
                            if (output == -1)
                            {
                                output = nums[i] + nums[k] + nums[j];
                            }
                            else if (nums[i] + nums[k] + nums[j] < output)
                            {
                                output = nums[i] + nums[k] + nums[j];
                            }
                        }
                    }
                }
            }
        }

        return output;
    }
};