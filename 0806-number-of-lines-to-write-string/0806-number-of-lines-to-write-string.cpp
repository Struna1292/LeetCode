class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        
        vector<int> output(2, 0);

        int line = 1;
        int currWidth = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (currWidth + widths[s[i]-'a'] <= 100)
            {
                currWidth += widths[s[i]-'a'];
            }
            else
            {
                line++;
                currWidth = widths[s[i]-'a'];
            }
        }

        output[0] = line;
        output[1] = currWidth;

        return output;
    }
};