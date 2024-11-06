class Solution {
public:
    int setBits(int num)
    {
        int counter = 0;

        while (num > 0)
        {
            if ((num & 1) == 1)
            {
                counter++;
            }
            num >>= 1;
        }

        return counter;
    }

    bool canSortArray(vector<int>& nums) {
        
        vector<int> bits(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            bits[i] = setBits(nums[i]);
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i-1])
            {
                int j = i;
                while (j > 0 && nums[j] < nums[j-1])
                {
                    if (bits[j] != bits[j-1])
                    {
                        return false;
                    }
                    swap(nums[j], nums[j-1]);
                    swap(bits[j], bits[j-1]);
                    j--;
                }
            }
        }

        return true;
    }
};