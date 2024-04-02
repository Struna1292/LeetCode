class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        vector<vector<int>> alph1(256, vector<int>());
        vector<vector<int>> alph2(256, vector<int>());

        for (int i = 0; i < s.length(); i++)
        {
            alph1[s[i]].push_back(i);
            alph2[t[i]].push_back(i);
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (alph1[s[i]].size() != alph2[t[i]].size())
            {   
                return false;
            }

            for (int j = 0; j < alph1[s[i]].size(); j++)
            {
                if (j == 0 && i != alph1[s[i]][0])
                {
                    break;
                }
                else if (alph1[s[i]][j] != alph2[t[i]][j])
                {
                    return false;
                }
            }   
        }


        return true;
    }
};