class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<int> turns(dist.size(), 0);

        for (int i = 0; i < dist.size(); i++)
        {
            turns[i] = dist[i] / speed[i];
            if (dist[i] % speed[i] != 0)
            {
                turns[i]++;
            }
        }

        sort(begin(turns), end(turns));

        for (int i = 1; i < turns.size(); i++)
        {
            if (turns[i] < i+1)
            {
                return i;
            }
        }
        
        return turns.size();
    }
};