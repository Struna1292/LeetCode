class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int output = 0;

        int prev = nums[0];
        int counter = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                if (counter == 1)
                {
                    return -1;
                }

                if (counter % 3 == 0)
                {
                    output += counter / 3;
                }
                else
                {
                    output += (counter / 3)+1;
                }

                prev = nums[i];
                counter = 1;
            }
            else
            {
                counter++;
            }
        }

        if (counter == 1)
        {
            return -1;
        }

        if (counter % 3 == 0)
        {
            output += counter / 3;
        }
        else
        {
            output += (counter / 3)+1;
        }


        return output;
    }
};