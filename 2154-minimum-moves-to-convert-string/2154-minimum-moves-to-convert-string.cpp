class Solution {
public:
    int minimumMoves(string s) {
        
        int output = 0;

        for (int i = 0; i < s.length()-2; i++)
        {
            if (s[i] == 'X')
            {
                output++;
                for (int j = i; j < i+3; j++)
                {
                    s[j] = 'O';
                }
            }
        }

        if (s[s.length()-1] == 'X' || s[s.length()-2] == 'X')
        {
            output++;
        }

        return output;
    }
};