class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int output = 0;

        int j = 0;

        while (true)
        {
            int bits = 0;  
            int counter = 0;          
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0)
                {
                    if ((nums[i] & 1) == 1)
                    {
                        bits++;
                    }
                    nums[i] >>= 1;
                }
                else
                {
                    counter++;
                }
            }

            if (counter == nums.size())
            {
                break;
            }

            if (bits >= k)
            {
                output += pow(2,j);
            }
            j++;
        }

        return output;
    }
};