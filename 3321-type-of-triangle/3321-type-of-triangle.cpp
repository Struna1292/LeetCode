class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        set<int> st;

        int biggest = nums[0];
        int total = 0;

        for (int n : nums)
        {
            st.insert(n);
            total += n;
            if (n > biggest)
            {
                biggest = n;
            }
        }

        total -= biggest;
        if (total <= biggest)
        {
            return "none";
        }

        if (st.size() == 1)
        {
            return "equilateral";
        }
        else if (st.size() == 2)
        {
            return "isosceles";
        }

        return "scalene";
    }
};