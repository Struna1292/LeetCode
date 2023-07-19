class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> freq(1000, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                freq[nums[i][j]-1]++;
            }
        }

        vector<int> output;
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == nums.size())
            {
                output.push_back(i+1);
            }
        }

        return output;
    }
};