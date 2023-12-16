class Solution {
public:
    void helper(vector<vector<int>>& output, vector<int>& nums, vector<bool> currAvailable, vector<int> curr)
    {
        if (curr.size() == nums.size())
        {
            output.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (currAvailable[i] == true)
            {
                vector<int> c1 = curr;
                c1.push_back(nums[i]);
                vector<bool> cA = currAvailable;
                cA[i] = false;
                helper(output, nums, cA, c1);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;

        vector<bool> available(nums.size(), true);

        helper(output, nums, available, {});

        return output;
    }
};