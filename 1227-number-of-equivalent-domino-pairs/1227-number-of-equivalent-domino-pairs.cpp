class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        map<vector<int>, int> mp;

        for (int i = 0; i < dominoes.size(); i++)
        {   
            if (dominoes[i][0] > dominoes[i][1])
            {
                swap(dominoes[i][0], dominoes[i][1]);
            }

            mp[dominoes[i]]++;
        }

        int output = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            for (int i = itr->second-1; i > 0; i--)
            {
                output += i;
            }
        }

        return output;
    }
};