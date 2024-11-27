class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string chars;

        for (int i = 0; i < s.length(); i++)
        {   
            if (s[i] != '-')
            {
                chars.push_back(toupper(s[i]));
            }
        }

        string output;

        int i = 0;
        if (chars.length() % k != 0)
        {
            int counter = chars.length() % k;

            while (i < counter)
            {
                output.push_back(chars[i]);
                i++;
            }
            if (i < chars.length())
            {
                output.push_back('-');
            }
        }

        int counter = 0;
        while (i < chars.length())
        {
            if (counter == k)
            {
                output.push_back('-');
                counter = 0;
            }
            else
            {
                output.push_back(chars[i]);
                counter++;
                i++;
            }
        }

        return output;
    }
};