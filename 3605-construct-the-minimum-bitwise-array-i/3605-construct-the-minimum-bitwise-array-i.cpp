class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> output;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = 1;
            while (true)
            {
                if ((curr | (curr+1)) == nums[i])
                {
                    output.push_back(curr);
                    break;
                }
                else if (curr >= nums[i])
                {
                    output.push_back(-1);
                    break;
                }
                curr++;
            }
        }

        return output;
    }
};