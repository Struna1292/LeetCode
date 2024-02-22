class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<pair<int, bool>> freq(n, {0, false});

        for (int i = 0; i < trust.size(); i++)
        {
            freq[trust[i][1]-1].first++;
            freq[trust[i][0]-1].second = true;
        }

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i].first == n-1 && !freq[i].second)
            {
                return i+1;
            }
        }

        return -1;
    }
};