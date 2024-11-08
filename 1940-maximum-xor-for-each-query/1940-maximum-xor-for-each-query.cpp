class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> queryXor;

        int curr = nums[0];
        queryXor.push_back(curr);
        for (int i = 1; i < nums.size(); i++)
        {
            curr ^= nums[i];
            queryXor.push_back(curr);
        }

        vector<int> output;

        for (int i = 0; i < queryXor.size(); i++)
        {
            string s = bitset<64>(queryXor[i]).to_string();

            for (int i = s.length()-1; i > s.length()-1-maximumBit; i--)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                }
                else
                {   
                    s[i] = '0';
                }
            }
            bitset<64> bitset(s);

            output.push_back(static_cast<int64_t>(bitset.to_ullong()));
        }

        int i = 0;
        int j = output.size()-1;

        while (i < j)
        {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }   
};