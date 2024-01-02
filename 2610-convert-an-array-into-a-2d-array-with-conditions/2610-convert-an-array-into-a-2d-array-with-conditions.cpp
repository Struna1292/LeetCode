class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> count(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]-1]++;
        }

        vector<vector<int>> output;

        for (int i = 0; i < count.size(); i++)
        {
            for (int j = 0; j < count[i]; j++)
            {
                if (output.size() < j+1)
                {
                    output.push_back({});
                }
                output[j].push_back(i+1);
            }
        }

        return output;
    }
};