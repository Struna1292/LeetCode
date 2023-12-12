class Solution {
public:

    long long countSubarrays(vector<int>& nums, int k) {
        int biggest = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > biggest)
            {
                biggest = nums[i];
            }
        }

        long long output = 0;

        int i = 0;
        int j = 0;

        bool window = false;

        while (i < nums.size())
        {   
            if (!window)
            {
                if (nums[i] == biggest)
                {
                    k--;
                }
    
                if (k == 0)
                {
                    output += nums.size()-i;
                    window = true;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                if (nums[j] == biggest)
                {
                    window = false;
                    k++;
                    i++;
                }
                else
                {
                    output += nums.size()-i;
                }
                j++;
            }
        }


        return output;
    }
};