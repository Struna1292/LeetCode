class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        vector<int> prefix(nums.size(), 0);
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            prefix[i] = curr;
        }

        vector<int> suffix(nums.size(), 0);
        curr = 0;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            curr += nums[i];
            suffix[i] = curr;
            
        }
        
        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (prefix[i] == suffix[i])
                {
                    output += 2;
                }
                else if (abs(prefix[i] - suffix[i]) == 1)
                {
                    output++;
                }
            }
        }


        return output;
    }
};