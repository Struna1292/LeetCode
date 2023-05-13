class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int counter = 0;
        int index = -1;
        int biggest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                counter++;
                if (counter > biggest)
                {
                    biggest = counter;
                }
            }
            else
            {
                if (index != -1)
                {
                    counter = i - index - 1;
                }
                index = i;
            }
        }

        if (index == -1)
        {
            biggest--;
        }

        return biggest;
    }
};