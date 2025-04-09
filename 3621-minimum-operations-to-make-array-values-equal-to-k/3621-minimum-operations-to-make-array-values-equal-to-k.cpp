class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        set<int> st;

        for (int n : nums)
        {
            st.insert(n);
        }

        auto itr = st.begin();

        if (*itr == k)
        {
            return st.size()-1;
        }
        else if (*itr < k)
        {
            return -1;
        }

        return st.size();
    }
};