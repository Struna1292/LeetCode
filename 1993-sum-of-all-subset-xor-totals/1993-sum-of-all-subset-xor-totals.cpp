class Solution {
public:
    void helper(int& length, vector<int>& nums, vector<bool>& used, vector<int> curr, int index, int& output)
    {
        if (curr.size() == length)
        {
            int x = curr[0];
            for (int i = 1; i < curr.size(); i++)
            {
                x ^= curr[i];
            }   
            output += x;

            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                vector<int> cp = curr;
                cp.push_back(nums[i]);
                helper(length, nums, used, cp, i, output);
                used[i] = false;
            }
        }
    }

    int subsetXORSum(vector<int>& nums) {
        
        vector<bool> used(nums.size(), false);

        int output = 0;

        for (int i = 1; i <= nums.size(); i++)
        {
            helper(i, nums, used, {}, 0, output);
        }

        return output;
    }
};