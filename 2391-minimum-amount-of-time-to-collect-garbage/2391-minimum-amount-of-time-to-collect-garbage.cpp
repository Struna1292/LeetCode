class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<pair<char,int>> occurrences = {{'M', 0}, {'G', 0}, {'P', 0}};

        for (int i = 0; i < garbage.size(); i++)
        {
            for (int j = 0; j < garbage[i].length(); j++)
            {
                for (int k = 0; k < occurrences.size(); k++)
                {
                    if (occurrences[k].first == garbage[i][j])
                    {
                        occurrences[k].second++;
                    }
                }
            }
        }

        int totalTime = 0;
        int currTime = 0;
        for (int i = 0; i < occurrences.size(); i++)
        {
            currTime = 0;
            for (int j = 0; j < garbage.size(); j++)
            {
                if (occurrences[i].second > 0)
                {
                    if (j != 0)
                    {
                        currTime += travel[j-1];
                    }
                }
                else
                {
                    break;
                }
                for (int k = 0; k < garbage[j].length(); k++)
                {
                    if (garbage[j][k] == occurrences[i].first)
                    {
                        occurrences[i].second--;
                        currTime++;
                    }
                }
            }
            totalTime += currTime;
        }

        return totalTime;
    }
};