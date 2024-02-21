class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        
        int biggest = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    {
                        int curr = nums[i] ^ nums[j];

                        if (curr > biggest)
                        {
                            biggest = curr;
                        }
                    }
                }
            }
        }

        return biggest;
    }
};