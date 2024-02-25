class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int counter = 1;
        int prev = nums[0];

        int singles = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                counter++;
            }
            else
            {
                if (counter == 1)
                {
                    singles++;
                }
                else if (counter > 2)
                {
                    return false;
                }
                counter = 1;
                prev = nums[i];
            }
        }

        if (counter == 1)
        {
            singles++;
        }
        else if (counter > 2)
        {
            return false;
        }

        if (singles > 0 && singles % 2 != 0)
        {
            return false;
        }

        return true;
    }
};