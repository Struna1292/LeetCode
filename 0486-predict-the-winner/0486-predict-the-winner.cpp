class Solution {
public:
    int helperMin(vector<int>& nums, int i, int j, int val, int num)
    {
        val -= num;

        int num1 = 0;
        int num2 = 0;

        if (i+1 == j)
        {
            if (nums[i] < nums[j])
            {
                val += (nums[j] - nums[i]);
            }
            else
            {
                val += (nums[i] - nums[j]);
            }
            return val;
        }
        else if (nums[i] < nums[j])
        {
            num1 = helperMax(nums, i+1, j, val, nums[i]);

            num2 = helperMax(nums, i, j-1, val, nums[j]);
        }
        else
        {
            num1 = helperMax(nums, i, j-1, val, nums[j]);

            num2 = helperMax(nums, i+1, j, val, nums[i]);
        }

        if (num1 > num2)
        {
            val = num1;
        }
        else
        {
            val = num2;
        }

        return val;
    }

    int helperMax(vector<int>& nums, int i, int j, int val, int num)
    {
        val += num;

        int num1 = 0;
        int num2 = 0;

        if (i+1 == j)
        {
            if (nums[i] > nums[j])
            {
                val += (nums[j] - nums[i]);
            }
            else
            {
                val += (nums[i] - nums[j]);
            }
            return val;
        }
        else if (nums[i] < nums[j])
        {
            num1 = helperMin(nums, i+1, j, val, nums[i]);

            num2 = helperMin(nums, i, j-1, val, nums[j]);
        }
        else
        {
            num1 = helperMin(nums, i, j-1, val, nums[j]);

            num2 = helperMin(nums, i+1, j, val, nums[i]);
        }

        if (num1 < num2)
        {
            val = num1;
        }
        else
        {
            val = num2;
        }

        return val;
    }

    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2)
        {
            return true;
        }
        
        int val = 0;
        int num1 = 0;
        int num2 = 0;

        if (nums[0] < nums[nums.size()-1])
        {
            num1 = helperMax(nums, 1, nums.size()-1, val, nums[0]);
            num2 = helperMax(nums, 0, nums.size()-2, val, nums[nums.size()-1]);
        }
        else
        {
            num1 = helperMax(nums, 0, nums.size()-2, val, nums[nums.size()-1]);
            num2 = helperMax(nums, 1, nums.size()-1, val, nums[0]);
        }

        if (num1 >= 0 || num2 >= 0)
        {
            return true;
        }
        return false;
    }
};