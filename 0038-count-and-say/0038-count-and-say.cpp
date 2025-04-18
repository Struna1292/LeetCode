class Solution {
public:
    string RLE(string s)
    {
        if (s == "")
        {
            return "";
        }

        int counter = 1;
        char prev = s[0];
        string output;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != prev)
            {
                output.push_back('0'+counter);
                output.push_back(prev);

                counter = 1;
                prev = s[i];
            }
            else
            {
                counter++;
            }
        }
        output.push_back('0'+counter);
        output.push_back(prev);

        return output;
    }

    string countAndSay(int n) {
        
        string output = "1";

        for (int i = 1; i < n; i++)
        {
            output = RLE(output);
        }

        return output;
    }
};