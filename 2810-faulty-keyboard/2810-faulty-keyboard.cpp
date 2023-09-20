class Solution {
public:
    void reverseString(string& s)
    {
        int i = 0;
        int j = s.length()-1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string finalString(string s) {
        string output;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'i')
            {
                int j = i;
                while (j < s.length() && s[j] == 'i')
                {
                    j++;
                }
                if ((j - i) % 2 == 1)
                {
                    reverseString(output);
                }
                i = j-1;
            }
            else
            {
                output.push_back(s[i]);
            }
        }

        return output;
    }
};