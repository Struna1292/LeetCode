class Solution {
public:
    string generateTag(string caption) {
        
        vector<string> words;

        string curr = "";

        for (char c : caption)
        {
            if (c == ' ' && curr != "")
            {
                if (words.size() >= 1)
                {
                    curr[0] -= 32;
                }
                words.push_back(curr);
                curr = "";
            }
            else if (c >= 'A' && c <= 'z')
            {
                if (c >= 'A' && c <= 'Z')
                {
                    c += 32;
                }

                curr.push_back(c);
            }
        }

        if (curr.length() >= 1)
        {
            if (words.size() >= 1)
            {
                curr[0] -= 32;
            }
            words.push_back(curr);
        }

        string output = "#";

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                if (output.length() == 100)
                {
                    return output;
                }
                output.push_back(words[i][j]);
            }
        }

        return output;
    }
};