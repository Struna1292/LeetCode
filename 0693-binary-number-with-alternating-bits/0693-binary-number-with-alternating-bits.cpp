class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        string s = bitset<64>(n).to_string(); 

        int i = 0;
        while (s[i] != '1')
        {
            i++;
        }

        for (; i < 64; i++)
        {
            if (s[i-1] == s[i])
            {
                return false;
            }
        }

        return true;
    }
};