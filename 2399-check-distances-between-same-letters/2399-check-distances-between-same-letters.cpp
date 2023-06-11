class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {

        vector<vector<int>> indexes(26, vector<int>());

        for (int i = 0; i < s.length(); i++)
        {
            indexes[s[i]-'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++)
        {
            if (indexes[i].size() > 0)
            {
                if (indexes[i][1] - (indexes[i][0]+1) != distance[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};