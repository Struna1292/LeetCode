class Solution {
public:
    string oddString(vector<string>& words) {
        
        vector<vector<int>> diffs;

        map<vector<int>, int> mp;

        for (int j = 0; j < words.size(); j++)
        {
            vector<int> curr;
            for (int i = 1; i < words[j].length(); i++)
            {
                curr.push_back(words[j][i]-words[j][i-1]);
            }
            diffs.push_back(curr);

            mp[curr]++;
        }

        for (int i = 0; i < diffs.size(); i++)
        {
            for (auto itr = mp.begin(); itr != mp.end(); itr++)
            {
                if (itr->second == 1 && diffs[i] == itr->first)
                {
                    return words[i];
                }
            }
        }

        return words[0];
    }
};