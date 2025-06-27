class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, int> playerLostMatches;

        for (int i = 0; i < matches.size(); i++) {
            playerLostMatches[matches[i][1]]++;
            playerLostMatches[matches[i][0]];
        }

        vector<vector<int>> output = {{}, {}};

        for (auto itr = playerLostMatches.begin(); itr != playerLostMatches.end(); itr++) {
            if (itr->second == 0) {
                output[0].push_back(itr->first);
            }
            else if (itr->second == 1) {
                output[1].push_back(itr->first);
            }
        }

        return output;
    }
};