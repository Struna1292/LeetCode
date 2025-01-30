class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        string curr;
        
        vector<string> output;

        string f;
        string s;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                if (f == first && s == second)
                {
                    output.push_back(curr);
                }

                f = s;
                s = curr;
                curr = "";
            }
            else
            {
                curr.push_back(text[i]);
            }
        }
        if (f == first && s == second)
        {
            output.push_back(curr);
        }

        return output;
    }
};