class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int index = -1;

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (index == -1)
                {
                    index = i;
                }
                else
                {
                    swap(s1[i], s1[index]);
                    return s1 == s2;
                }
            }
        }

        return index == -1;
    }
};