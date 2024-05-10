class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() < 1)
        {
            return 0;
        }
        
        sort(begin(nums), end(nums));

        int counter = 1;
        int prev = nums[0];

        int longest = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i]-1 == prev)
            {
                counter++;
            }
            else if (nums[i] == prev)
            {
                continue;
            }
            else
            {
                if (counter > longest)
                {
                    longest = counter;
                }
                counter = 1;
            }
            prev = nums[i];
        }

        if (counter > longest)
        {
            longest = counter;
        }
        counter = 1;        

        return longest;
    }
};