class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {

        if (nums.size() == 1)
        {
            return 0;
        }
        
        vector<int> twiceNums(nums.size()*2, 0);

        int k = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                twiceNums[k] = nums[j];
                k++;
            }
        }

        int i = 0;
        int counter = 0;
        while (i+1 < twiceNums.size())
        {
            if (twiceNums[i] < twiceNums[i+1])
            {
                counter++;
                if (counter == nums.size()-1)
                {
                    if (counter-i-1 == 0)
                        return 0;
                    return twiceNums.size() - i -2;
                }
            }
            else
            {
                counter = 0;
            }
            i++;
        }

        return -1;
    }
};