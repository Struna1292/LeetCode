class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int ones[64] = { 0 }; // counter the number of ones in binary representation

        for (int i = 0; i < candidates.size(); i++)
        {
            string s = bitset<64>(candidates[i]).to_string();
            
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == '1')
                {
                    ones[j]++;
                }
            }
            
        }

        int output = ones[0];

        for (int i = 1; i < 64; i++)
        {
            if (ones[i] > output)
            {
                output = ones[i];
            }
        }

        return output;
    }
};