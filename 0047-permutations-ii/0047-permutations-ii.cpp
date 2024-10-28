class Solution {
public:
    void helper(vector<int>& nums, vector<int> curr, vector<bool> used, set<vector<int>>& st)
    {
        if (curr.size() == nums.size())
        {   
            st.insert(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                vector<int> currCp = curr;
                currCp.push_back(nums[i]);
                used[i] = true;
                helper(nums, currCp, used, st);
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<bool> used(nums.size(), false);

        set<vector<int>> st;

        helper(nums, {}, used, st);

        vector<vector<int>> output;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            output.push_back(*(itr));
        }

        return output;
    }
};