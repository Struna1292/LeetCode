class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        vector<int> prefix(nums.size(), 0);

        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {   
            curr += nums[i];
            prefix[i] = curr;
        }

        int output = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {   
            if ((prefix[i]-(curr-prefix[i])) % 2 == 0)
            {
                output++;
            }
        }

        return output;
    }
};