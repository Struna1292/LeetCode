class Solution {
public:
    void helper(vector<int> curr, int& k, set<vector<int>>& st, int i, int& n)
    {
        if (curr.size() == k)
        {
            st.insert(curr);
        }

        for (; i <= n; i++)
        {
            vector<int> currCp = curr;
            currCp.push_back(i);
            helper(currCp, k, st, i+1, n);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        
        set<vector<int>> st;

        helper({}, k, st, 1, n);

        vector<vector<int>> output;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            output.push_back(*itr);
        }

        return output;
    }
};