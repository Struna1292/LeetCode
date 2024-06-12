class Solution {
public:
    void helper(int counter, int &i, vector<int>& nums, int num)
    {
        while (counter > 0)
        {
            counter--;
            nums[i] = num;
            i++;
        }
    }

    void sortColors(vector<int>& nums) {
        
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeros++;
            }
            else if (nums[i] == 1)
            {
                ones++;
            }
            else
            {
                twos++;
            }
        }

        int i = 0;

        helper(zeros, i, nums, 0);

        helper(ones, i, nums, 1);

        helper(twos, i, nums, 2);
        
    }
};