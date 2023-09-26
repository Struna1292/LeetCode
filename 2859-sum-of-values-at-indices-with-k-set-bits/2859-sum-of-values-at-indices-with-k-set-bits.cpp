class Solution {
public:
    bool isKSetBits(int n, int k)
    {
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                k--;
                if (k < 0)
                {
                    return false;
                }
            }
            n >>= 1;
        }

        if (k != 0)
        {
            return false;
        }

        return true;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        if (k == 0)
        {
            return nums[0];
        }

        int output = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (isKSetBits(i,k))
            {
                output += nums[i];
            }
        }

        return output;
    }
};