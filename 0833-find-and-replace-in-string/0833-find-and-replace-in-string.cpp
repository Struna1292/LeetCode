class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        int indexBalance = 0;

        for (int i = 0; i < indices.size(); i++)
        {
            bool match = true;
            int index = indices[i];
            int indexStart = index;
            for (int j = 0; j < sources[i].length(); j++)
            {
                if (s[index] == sources[i][j])
                {
                    index++;
                }
                else
                {
                    match = false;
                    break;
                }
            }
            
            if (match)
            {
                indexBalance = (targets[i].length() - sources[i].length());
                for (int j = 0; j < indices.size(); j++)
                {
                    if (indices[j] >= indexStart)
                    {
                        indices[j] += indexBalance;
                    }
                }
                s.replace(indexStart, sources[i].length(), targets[i]);
            }

        }

        return s;
    }
};