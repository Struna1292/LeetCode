class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ones(64, 0);

        for (int i = 0; i < nums1.size(); i++)
        {
            string s = std::bitset<64>(nums1[i]).to_string();

            for (int j = 0; j < 64; j++)
            {
                if (s[j] == '1')
                {
                    ones[j] += nums2.size();
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            string s = std::bitset<64>(nums2[i]).to_string();

            for (int j = 0; j < 64; j++)
            {
                if (s[j] == '1')
                {
                    ones[j] += nums1.size();
                }
            }
        }

        string output(64, '1');

        for (int i = 0; i < 64; i++)
        {
            if (ones[i] % 2 == 0)
            {
                output[i] = '0';
            }
        }

        return stoi(output, nullptr, 2);
    }
};