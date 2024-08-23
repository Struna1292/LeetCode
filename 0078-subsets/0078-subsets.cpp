class Solution {
public:
    void helper(vector<int>& nums, vector<int> curr, int i, set<vector<int>>& st)
    {
        st.insert(curr);

        for (int j = i+1; j < nums.size(); j++)
        {
            vector<int> c = curr;
            c.push_back(nums[j]);
            helper(nums, c, j, st);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++)
        {
            helper(nums, {nums[i]}, i, st);
        }

        vector<vector<int>> output = {{}};

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            output.push_back(*itr);
        }

        return output;
    }
};