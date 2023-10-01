class Solution {
public:
    string reverseWords(string s) {

        int spaceIndex = -1;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                int j = i-1;
                spaceIndex++;
                while (spaceIndex < j)
                {
                    swap(s[spaceIndex], s[j]);
                    spaceIndex++;
                    j--;
                }
                spaceIndex = i;
            }
        }

        int j = s.length()-1;
        spaceIndex++;
        while (spaceIndex < j)
        {
            swap(s[spaceIndex], s[j]);
            spaceIndex++;
            j--;
        }

        return s;
    }
};