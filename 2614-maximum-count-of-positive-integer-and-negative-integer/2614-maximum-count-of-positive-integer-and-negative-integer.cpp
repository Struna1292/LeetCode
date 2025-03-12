class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int pos = 0;
        int neg = 0;

        for (int n : nums)
        {
            if (n > 0)
            {
                pos++;
            }
            else if (n < 0)
            {
                neg++;
            }
        }

        return max(neg, pos);
    }
};