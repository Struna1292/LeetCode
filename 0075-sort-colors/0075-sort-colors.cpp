class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zeros = 0;
        int ones = 0;

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
        }   

        for (int i = 0; i < nums.size(); i++)
        {
            if (zeros > 0)
            {
                zeros--;
                nums[i] = 0;
            }
            else if (ones > 0)
            {
                ones--;
                nums[i] = 1;
            }
            else 
            {
                nums[i] = 2;
            }
        }

    }
};