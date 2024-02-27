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

        int counter = 1;
        int prev = setBits(nums[0]);


        for (int i = 1; i < nums.size(); i++)
        {
            if (prev == setBits(nums[i]))
            {
                counter++;
            }
            else
            {
                if (counter > 1)
                {                    
                    sort(begin(nums)+i-counter, begin(nums)+i);
                }
                counter = 1;
                prev = setBits(nums[i]);
            }
        }

        if (counter > 1)
        {
            sort(end(nums)-counter, end(nums));
        }


        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i-1])
            {
                return false;
            }
        }

        return true;
    }
};