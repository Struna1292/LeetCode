class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int curr = 0;
        int i = 0;

        int currLength = 0;
        int minLength = 0;

        while (i < nums.size())
        {
            currLength++;
            curr += nums[i];

            
            while (curr >= target)
            {
                if (curr - nums[i-(currLength-1)] < target)
                {
                    break;
                }
                curr -= nums[i-(currLength-1)];
                currLength--;
            }
            
            if (curr >= target && (minLength == 0 || currLength < minLength))
            {
                minLength = currLength;
            }

            i++;
        }

        
        return minLength;
    }
};