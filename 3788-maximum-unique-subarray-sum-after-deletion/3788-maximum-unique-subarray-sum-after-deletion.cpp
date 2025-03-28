class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        set<int> st;

        for (int n : nums)
        {
            if (n >= 0)
            {
                st.insert(n);
            }
        }

        int output = 0;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            output += *itr;
        }

        if (st.empty())
        {
            int biggest = nums[0];

            for (int n : nums)
            {
                if (biggest < n)
                {
                    biggest = n;
                }
            }

            return biggest;
        }

        return output;
    }
};