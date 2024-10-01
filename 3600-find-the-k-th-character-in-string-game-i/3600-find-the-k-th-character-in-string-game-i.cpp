class Solution {
public:
    char kthCharacter(int k) {
        
        string s = "a";

        while (s.length() < k)
        {
            string curr = s;

            for (int i = 0; i < curr.length(); i++)
            {
                if (curr[i]+1 > 'z')
                {
                    curr[i] = 'a';
                }
                else
                {
                    curr[i] += 1;
                }
            }

            s += curr;
        }

        return s[k-1];
    }
};