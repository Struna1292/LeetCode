class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string output;

        int index = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (index < spaces.size() && spaces[index] == i)
            {
                index++;
                output.push_back(' ');
            }

            output.push_back(s[i]);
        }

        return output;
    }
};